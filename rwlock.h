//
// Created by leoz on 7/31/18.
//

#ifndef RW_LOCK_RWLOCK_H
#define RW_LOCK_RWLOCK_H


#include <mutex>

namespace rwLock {

    class RwLock {
    public:
        RwLock();
        RwLock(const RwLock&) = delete;
        RwLock& operator=(const RwLock&) = delete;
        ~RwLock() = default;

        void lockRead();
        void lockWrite();
        void unlock();

    private:
        std::mutex d_mutex;
        std::condition_variable d_readEvent;
        std::condition_variable d_writeEvent;
        size_t d_readingNum;
        size_t d_writingNum;
        bool d_isWriting;
    };

}


#endif //RW_LOCK_RWLOCK_H
