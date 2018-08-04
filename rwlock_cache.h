//
// Created by leoz on 8/4/18.
//

#ifndef RW_LOCK_RWLOCK_CACHE_H
#define RW_LOCK_RWLOCK_CACHE_H


#include <thread>
#include <iostream>
#include "cache.h"
#include "rwlock.h"
#include "rwlock_guard.h"


namespace rwLock {

    class RwLockCache : public Cache {
    public:
        RwLockCache();

        void get(int* a, int *b) const override;
        void set(int a, int b) override;

    private:
        int d_a;
        int d_b;
        mutable RwLock d_lock;
        mutable std::mutex d_mutex;
    };

    inline
    void RwLockCache::get(int *a, int *b) const {
        RwReadLockGuard<RwLock> rwReadLockGuard(d_lock);
        *a = d_a;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        *b = d_b;

        std::lock_guard<std::mutex> guard(d_mutex);
        std::cout << "get a=" << *a << " b=" << *b << std::endl;
    }

    inline
    void RwLockCache::set(int a, int b) {
        RwWriteLockGuard<RwLock> rwWriteLockGuard(d_lock);
        d_a = a;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        d_b = b;
        
        std::lock_guard<std::mutex> guard(d_mutex);
        std::cout << "set d_a=" << d_a << " d_b=" << d_b << std::endl;
    }
}

#endif //RW_LOCK_RWLOCK_CACHE_H
