#include <iostream>
#include <thread>

#include "test_cache.h"
#include "workers.h"

using namespace rwLock;


int main() {
    TestCache cache;

    cache.set(2, 2);
    int a(0);
    int b(0);
    cache.get(&a, &b);
    std::cout << "a=" << a << " b=" << b << std::endl;

    std::thread rThreads[10];
    std::thread wThreads[5];

    for (size_t i = 0; i < 10; ++i) {
        rThreads[i] = std::thread(std::bind(read, cache));
    }
    for (size_t i = 0; i < 5; ++i) {
        wThreads[i] = std::thread(std::bind(write, cache));
    }

    for (size_t i = 0; i < 10; ++i) {
        rThreads[i].join();
    }
    for (size_t i = 0; i < 5; ++i) {
        wThreads[i].join();
    }
    return 0;
}