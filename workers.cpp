//
// Created by leoz on 7/28/18.
//

#include <random>
#include <iostream>
#include <thread>

#include "workers.h"
#include "utils/stop_watch.h"
#include "test_cache.h"


namespace rwLock {

    void read(const Cache& cache) {
        static const size_t max_times(1000);

        size_t times(0);
        while (times < max_times) {
            int a(0);
            int b(0);
            cache.get(&a, &b);
            ++times;
        }
    }

    void write(Cache& cache) {
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

    void runTestCache() {
        TestCache cache;

        std::vector<std::thread> rThreads;
        std::vector<std::thread> wThreads;

        StopWatch watch;
        watch.start();
        for (size_t i = 0; i < 10; ++i) {
            rThreads.emplace_back(std::bind(read, cache));
        }
        for (size_t i = 0; i < 5; ++i) {
            wThreads.emplace_back(std::bind(write, cache));
        }

        for (size_t i = 0; i < 10; ++i) {
            rThreads[i].join();
        }
        for (size_t i = 0; i < 5; ++i) {
            wThreads[i].join();
        }
        watch.stop();

        std::cout << "testCache process time " << watch.ellipseInMs() / 1000.0 << " second(s)" << std::endl;
    }
}