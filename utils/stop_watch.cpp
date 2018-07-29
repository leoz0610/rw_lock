//
// Created by leoz on 7/29/18.
//

#include "stop_watch.h"


namespace rwLock {

    StopWatch::StopWatch()
    : d_startPoint(),
      d_endPoint()
    {}

    void StopWatch::start() {
        using namespace std::chrono;
        d_startPoint = system_clock::now();
    }

    void StopWatch::stop() {
        using namespace std::chrono;
        d_endPoint = system_clock::now();
    }

    int64_t StopWatch::ellipseInSeconds() const {
        using namespace std::chrono;
        seconds d = duration_cast<std::chrono::seconds>(d_endPoint - d_startPoint);
        return d.count();
    }
}