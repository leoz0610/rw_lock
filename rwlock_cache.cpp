//
// Created by leoz on 8/4/18.
//

#include "rwlock_cache.h"


namespace rwLock {
    RwLockCache::RwLockCache()
    : d_a(0),
      d_b(0),
      d_lock(),
      d_mutex()
    { }
}