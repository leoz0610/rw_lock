//
// Created by leoz on 7/28/18.
//

#include <random>
#include <iostream>
#include <thread>

#include "workers.h"
#include "utils/stop_watch.h"
#include "test_cache.h"
#include "mutex_cache.h"
#include "rwlock_cache.h"


namespace rwLock {

    void read(std::shared_ptr<const Cache> cache) {
        static const size_t max_times(1000);

        size_t times(0);
        while (times < max_times) {
            int a(0);
            int b(0);
            cache->get(&a, &b);
            ++times;
        }
    }

    void write(std::shared_ptr<Cache> cache) {
        static std::default_random_engine gen;
        static std::uniform_int_distribution<int> dist(0, 99);
        static const size_t max_times(1000);

        size_t times(0);
        while (times < max_times) {
            int value = dist(gen);
            cache->set(value, value);
            ++times;
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
    }

    void runCache(std::shared_ptr<Cache> cache, const std::string& label) {
        std::vector<std::thread> rThreads;
        std::vector<std::thread> wThreads;

        StopWatch watch;
        watch.start();
        for (size_t i = 0; i < 10; ++i) {
            rThreads.emplace_back(std::bind(read, cache));

            if (i < 5) {
                wThreads.emplace_back(std::bind(write, cache));
            }
        }

        std::for_each(rThreads.begin(), rThreads.end(), [&](std::thread& t) { t.join(); });
        std::for_each(wThreads.begin(), wThreads.end(), [&](std::thread& t) { t.join(); });
        watch.stop();

        std::cout << label << " process time " << watch.ellipseInMs() / 1000.0 << " second(s)" << std::endl;
    }

    void runTestCache() {
        std::shared_ptr<Cache> cache(new TestCache());

        runCache(cache, "testCache");
    }

    void runMutexCache() {
        std::shared_ptr<Cache> cache(new MutexCache());

        runCache(cache, "mutexCache");
    }

    void runRwLockCache() {
        std::shared_ptr<Cache> cache(new RwLockCache());

        runCache(cache, "rwLockCache");
    }
}