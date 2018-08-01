//
// Created by leoz on 7/31/18.
//

#include "rwlock.h"


namespace rwLock {
    RwLock::RwLock()
    : d_mutex(),
      d_readEvent(),
      d_writeEvent(),
      d_readingNum(0),
      d_writingNum(0),
      d_isWriting(false)
    {}

    void RwLock::lockRead() {
        std::unique_lock<std::mutex> lck(d_mutex);
        while (d_writingNum > 0) {
            d_readEvent.wait(lck);
        }
        ++d_readingNum;
    }

    void RwLock::lockWrite() {
        std::unique_lock<std::mutex> lck(d_mutex);
        ++d_writingNum;
        while (d_readingNum > 0 || d_isWriting) {
            d_writeEvent.wait(lck);
        }
        d_isWriting = true;
    }

    void RwLock::unlock() {
        std::unique_lock<std::mutex> lck(d_mutex);
        if (d_isWriting) {
            d_isWriting = false;
            if (--d_writingNum == 0) {
                d_readEvent.notify_all();
            }
            else {
                d_writeEvent.notify_one();
            }
        }
        else {
            --d_readingNum;
            d_writeEvent.notify_one();
        }
    }
}