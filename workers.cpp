//
// Created by leoz on 7/28/18.
//

#include <random>
#include <iostream>
#include "workers.h"


namespace rwLock {
    namespace {
        std::mutex workLock;
    }

    void read(const TestCache& cache) {
        static const size_t max_times(1000);

        size_t times(0);
        while (times < max_times) {
            int a(0);
            int b(0);
            cache.get(&a, &b);
            ++times;
        }
    }

    void write(TestCache& cache) {
        static std::default_random_engine gen;
        static std::uniform_int_distribution<int> dist(0, 99);
        static const size_t max_times(1000);

        size_t times(0);
        while (times < max_times) {
            int value = dist(gen);
            cache.set(value, value);
            ++times;
        }
    }
}