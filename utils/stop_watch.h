//
// Created by leoz on 7/29/18.
//

#ifndef RW_LOCK_STOP_WATCH_H
#define RW_LOCK_STOP_WATCH_H

#include <cstdint>
#include <chrono>

namespace rwLock {
    class StopWatch {
    public:
        StopWatch();
        ~StopWatch() = default;

        StopWatch(const StopWatch&) = delete;
        StopWatch& operator=(const StopWatch) = delete;

        void start();
        void stop();

        int64_t ellipseInMs() const;

    private:
        typedef std::chrono::time_point<std::chrono::system_clock> SystemTimePoint;

        SystemTimePoint d_startPoint;
        SystemTimePoint d_endPoint;
    };
}

#endif // RW_LOCK_STOP_WATCH_H