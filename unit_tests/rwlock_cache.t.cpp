//
// Created by leoz on 8/4/18.
//

#include <gtest/gtest.h>

#include "../rwlock_cache.h"

using namespace ::testing;

namespace rwLock {
    TEST(RwLockCacheUnitTest, generalTest)
    {
        RwLockCache cache;

        int a, b;
        cache.get(&a, &b);
        EXPECT_EQ(0, a);
        EXPECT_EQ(0, b);

        cache.set(3, 5);
        cache.get(&a, &b);
        EXPECT_EQ(3, a);
        EXPECT_EQ(5, b);
    }
}