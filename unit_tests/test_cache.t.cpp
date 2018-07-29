//
// Created by leoz on 7/29/18.
//

#include <gtest/gtest.h>
#include "../test_cache.h"

using namespace ::testing;

namespace rwLock {
    TEST(TestCacheUnitTest, generalTest)
    {
        TestCache cache;

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