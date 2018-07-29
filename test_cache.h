//
// Created by leoz on 7/28/18.
//

#ifndef RW_LOCK_TEST_CACHE_H
#define RW_LOCK_TEST_CACHE_H

#include <vector>
#include <iostream>

#include "cache.h"

namespace rwLock {

    class TestCache : public Cache {
    public:
        TestCache();

        void get(int* a, int *b) const override;
        void set(int a, int b) override;

    private:
        int d_a;
        int d_b;
    };

    inline
    void TestCache::get(int* a, int* b) const {
        *a = d_a;
        *b = d_b;
        std::cout << "get a=" << *a << " b=" << *b << std::endl;
    }

    inline
    void TestCache::set(int a, int b) {
        d_a = a;
        d_b = b;
        std::cout << "set d_a=" << d_a << " d_b=" << d_b << std::endl;
    }

}


#endif //RW_LOCK_TEST_CACHE_H
