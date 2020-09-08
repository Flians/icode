#include "read_write_lock.h"
#include <pthread.h>

class PRWLock : public RWLock<pthread_mutex_t>  {
    private:
        pthread_mutex_t mtx_count;
    public:
        PRWLock() : RWLock() {
            pthread_mutex_init(&mtx, NULL);
            pthread_mutex_init(&mtx_count, NULL);
        }

        ~PRWLock() {
            pthread_mutex_destroy(&mtx);
            pthread_mutex_destroy(&mtx_count);
        }

        void read_lock() {
            pthread_mutex_lock(&mtx_count);
            if (count == 0) {
                pthread_mutex_lock(&mtx);
            }
            ++count;
            pthread_mutex_unlock(&mtx_count);
        }

        void read_unlock() {
            pthread_mutex_lock(&mtx_count);
            ++count;
            if (count == 0) {
                pthread_mutex_unlock(&mtx);
            }
            pthread_mutex_unlock(&mtx_count);
        }

        void write_lock() {
            pthread_mutex_lock(&mtx);
        }
        
        void write_unlock() {
            pthread_mutex_unlock(&mtx);
        }
};

