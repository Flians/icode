#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <algorithm>
#include <condition_variable>
using namespace std;

std::condition_variable conv;
std::mutex mtx;
int g_ch = 0;

/************ 1 *************/
void print_t1(char ch) {
    for (int i = 0; i < 10; ++i) {
        mtx.lock();
        if (g_ch % 3 ==0) {
            cout << 'A' << endl;
            ++g_ch;
        } else {
            --i;
        }
        mtx.unlock();
    }
}
void print_t2(char ch) {
    for (int i = 0; i < 10; ++i) {
        mtx.lock();
        if (g_ch % 3 == 1) {
            cout << 'B' << endl;
            ++g_ch;
        } else {
            --i;
        }
        mtx.unlock();
    }
}
void print_t3(char ch) {
    for (int i = 0; i < 10; ++i) {
        mtx.lock();
        if (g_ch % 3 ==2) {
            cout << 'C' << endl;
            ++g_ch;
        } else {
            --i;
        }
        mtx.unlock();
    }
}

/************ 2 *************/

void print_t(char ch) {
    for (int i = 0; i < 10; ++i) {
        mtx.lock();
        if (g_ch % 3 == (ch - 'A')) {
            cout << ch << endl;
            ++g_ch;
        } else {
            --i;
        }
        mtx.unlock();
    }
}

/************ 4 *************/
void print_ct(char ch) {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> ulk(mtx);
        conv.wait(ulk, [ch](){return g_ch % 3 == (ch - 'A');});
        cout << ch << endl;
        ++g_ch;
        ulk.unlock();
        conv.notify_all();
    }
}

int main() {
    std::vector<std::thread> threads;
	threads.push_back(std::thread(print_ct, 'A'));
	threads.push_back(std::thread(print_ct, 'B'));
	threads.push_back(std::thread(print_ct, 'C'));
    std::for_each(threads.begin(), threads.end(), std::mem_fun_ref(&std::thread::join));

    return 0;
}