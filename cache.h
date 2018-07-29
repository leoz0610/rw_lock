//
// Created by leoz on 7/29/18.
//

#ifndef RW_LOCK_CACHE_H
#define RW_LOCK_CACHE_H


namespace rwLock {

    class Cache {
    public:
        Cache() = default;
        virtual ~Cache() = default;

        virtual void get(int* a, int* b) const = 0;
        virtual void set(int a, int b) = 0;
    };

}

#endif //RW_LOCK_CACHE_H
