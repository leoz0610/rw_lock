//
// Created by leoz on 7/29/18.
//

#include <gtest/gtest.h>
#include "../utils/stop_watch.h"
#include <thread>

using namespace ::testing;

namespace rwLock {
    TEST(StopWatchUnitTest, generalTest)
    {
        using namespace std::chrono;

        StopWatch watch;
        watch.start();

        std::this_thread::sleep_for(seconds(1));
        watch.stop();

        EXPECT_GE(1, watch.ellipseInSeconds());
    }
}