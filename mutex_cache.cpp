//
// Created by leoz on 7/29/18.
//

#include "mutex_cache.h"


namespace rwLock {

    MutexCache::MutexCache()
    : Cache(),
      d_a(0),
      d_b(0),
      d_mutex()
    {}

}