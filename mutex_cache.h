//
// Created by leoz on 7/29/18.
//

#ifndef RW_LOCK_MUTEX_CACHE_H
#define RW_LOCK_MUTEX_CACHE_H

#include <mutex>
#include <iostream>
#include <thread>

#include "cache.h"

namespace rwLock {

    class MutexCache : public Cache {
    public:
        MutexCache();

        void get(int* a, int* b) const override;
        void set(int a, int b) override;

    private:
        int d_a;
        int d_b;
        mutable std::mutex d_mutex;
    };

    inline
    void MutexCache::get(int *a, int *b) const {
        std::lock_guard<std::mutex> guard(d_mutex);
        *a = d_a;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        *b = d_b;
        std::cout << "get a=" << *a << " b=" << *b << std::endl;
    }

    inline
    void MutexCache::set(int a, int b) {
        std::lock_guard<std::mutex> guard(d_mutex);
        d_a = a;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        d_b = b;
        std::cout << "set d_a=" << d_a << " d_b=" << d_b << std::endl;
    }
}

#endif //RW_LOCK_MUTEX_CACHE_H
