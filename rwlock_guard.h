//
// Created by leoz on 8/4/18.
//

#ifndef RW_LOCK_RWLOCK_GUARD_H
#define RW_LOCK_RWLOCK_GUARD_H

namespace rwLock {

    template <class LOCK>
    class RwReadLockGuard {
    public:
        explicit RwReadLockGuard(LOCK& lock);
        ~RwReadLockGuard();

        RwReadLockGuard(const RwReadLockGuard&) = delete;
        RwReadLockGuard &operator=(const RwReadLockGuard&) = delete;

    private:
        LOCK& d_lock;
    };

    template <class LOCK>
    class RwWriteLockGuard {
    public:
        explicit RwWriteLockGuard(LOCK& lock);
        ~RwWriteLockGuard();

        RwWriteLockGuard(const RwWriteLockGuard&) = delete;
        RwWriteLockGuard& operator=(const RwWriteLockGuard&) = delete;

    private:
        LOCK& d_lock;
    };

    /*
     * class RwReadLockGuard
     */
    template <class LOCK>
    RwReadLockGuard<LOCK>::RwReadLockGuard(LOCK &lock)
    : d_lock(lock)
    {
        d_lock.lockRead();
    }

    template <class LOCK>
    RwReadLockGuard<LOCK>::~RwReadLockGuard() {
        d_lock.unlock();
    }

    /*
     * class RwWriteLockGuard
     */
    template <class LOCK>
    RwWriteLockGuard<LOCK>::RwWriteLockGuard(LOCK &lock)
    : d_lock(lock)
    {
        d_lock.lockWrite();
    }

    template <class LOCK>
    RwWriteLockGuard<LOCK>::~RwWriteLockGuard() {
        d_lock.unlock();
    }
}


#endif //RW_LOCK_RWLOCK_GUARD_H
