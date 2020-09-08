#include <iostream>

template <class T>
class RWLock {
    protected:
        int count;  
        T mtx;
        
    public:
        RWLock():count(0) {}
        virtual ~RWLock() = 0;

        virtual void read_lock() = 0;
        virtual void read_unlock() = 0;

        virtual void write_lock() = 0;
        virtual void write_unlock() = 0;
};

