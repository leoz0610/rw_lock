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
        while (true) {

            int a(0);
            int b(0);
            cache.get(&a, &b);
        }
    }

    void write(TestCache& cache) {
        static std::default_random_engine gen;
        static std::uniform_int_distribution<int> dist(0, 99);

        while (true) {
            int value = dist(gen);
            cache.set(value, value);
        }
    }
}