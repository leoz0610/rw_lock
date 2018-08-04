//
// Created by leoz on 7/31/18.
//

#include <gtest/gtest.h>

#include "../rwlock.h"

#include <thread>

using namespace ::testing;

namespace rwLock {
    namespace {
        void readAccess(RwLock* lock, int sleepInMs, int* count) {
            lock->lockRead();
            ++*count;
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepInMs));
            lock->unlock();
        }

        void writeAccess(RwLock* lock, int sleepInMs, int* count) {
            lock->lockWrite();
            ++*count;
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepInMs));
            lock->unlock();
        }
    }

    TEST(RwLockTest, concurrentReadTest)
    {
        RwLock lock;
        int count(0);

        std::thread thread1(std::bind(readAccess, &lock, 100, &count));
        thread1.detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        EXPECT_EQ(1, count);

        std::thread thread2(std::bind(readAccess, &lock, 50, &count));
        thread2.detach();
        std::thread thread3(std::bind(readAccess, &lock, 50, &count));
        thread3.detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        EXPECT_EQ(3, count);
    }

    TEST(RwLockTest, concurrentWriteTest)
    {
        RwLock lock;
        int count(0);

        std::thread thread1(std::bind(writeAccess, &lock, 100, &count));
        thread1.detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        EXPECT_EQ(1, count);

        std::thread thread2(std::bind(writeAccess, &lock, 50, &count));
        thread2.detach();
        std::thread thread3(std::bind(writeAccess, &lock, 50, &count));
        thread3.detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        EXPECT_EQ(1, count);
    }
}