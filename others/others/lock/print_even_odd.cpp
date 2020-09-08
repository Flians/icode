#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <algorithm>
using namespace std;

std::mutex mtx;
int i = 0;

void print_t(int add) {
    while  (i < 100) {
        mtx.lock();
        if (i % 2 == add) {
            cout << add << " -> " << i << endl;
            ++i;
        }
        mtx.unlock();
    }
}
int main() {
    vector<thread> threads;
    threads.push_back(thread(print_t, 0));
    threads.push_back(thread(print_t, 1));
    for_each(threads.begin(), threads.end(), mem_fun_ref(&thread::join));
    return 0;
}