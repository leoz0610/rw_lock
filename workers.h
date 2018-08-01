//
// Created by leoz on 7/28/18.
//

#ifndef RW_LOCK_WORKERS_H
#define RW_LOCK_WORKERS_H

#include <string>
#include "cache.h"

namespace rwLock {
    void read(std::shared_ptr<const Cache> cache, std::shared_ptr<std::atomic<int>> count);

    void write(std::shared_ptr<Cache> cache, std::shared_ptr<std::atomic<int>> count);

    void runCache(std::shared_ptr<Cache> cache, const std::string& label);

    void runTestCache();

    void runMutexCache();
}

#endif //RW_LOCK_WORKERS_H
