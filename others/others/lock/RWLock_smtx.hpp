#include "read_write_lock.h"
#include <mutex>
#include <condition_variable>

class SRWLock : public RWLock<std::mutex> {   
    private:
        std::condition_variable cond;     
    public:
        SRWLock() : RWLock() {
        }

        ~SRWLock(){}

        void read_lock(){
            std::unique_lock<std::mutex> locker(mtx);
            while (count < 0) {
                cond.wait(locker);
            }
            ++count;
            locker.unlock();
        }

        void read_unlock(){
            mtx.lock();
            --count;
            if (count == 0) {
                cond.notify_one();
            }
            mtx.unlock();
        }

        void write_lock(){
            std::unique_lock<std::mutex> locker(mtx);
            while (count != 0) {
                cond.wait(locker);  
            }
            count = -1;
            locker.unlock();
        }

        void write_unlock(){
            mtx.lock();
            count = 0;  
            cond.notify_all();
            mtx.unlock();
        }
};

