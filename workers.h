//
// Created by leoz on 7/28/18.
//

#ifndef RW_LOCK_WORKERS_H
#define RW_LOCK_WORKERS_H

#include "test_cache.h"

namespace rwLock {
    void read(const TestCache& cache);

    void write(TestCache& cache);
}

#endif //RW_LOCK_WORKERS_H
