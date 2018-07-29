//
// Created by leoz on 7/28/18.
//

#ifndef RW_LOCK_WORKERS_H
#define RW_LOCK_WORKERS_H

#include "cache.h"

namespace rwLock {
    void read(const Cache& cache);

    void write(Cache& cache);

    void runTestCache();
}

#endif //RW_LOCK_WORKERS_H
