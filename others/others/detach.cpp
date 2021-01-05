/**
 * thread::detach(): 从 thread 对象分离执行的线程，允许执行独立地持续。一旦线程退出，则释放所有分配的资源。调用 detach 后， *this 不再占有任何线程。
 */
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

void independentThread()
{
    std::cout << "Starting concurrent thread.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Exiting concurrent thread.\n";
}

void threadCaller()
{
    std::cout << "Starting thread caller.\n";
    std::thread t(independentThread);
    t.detach();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Exiting thread caller.\n";
}

using milliseconds_duration = std::chrono::duration<double, std::milli>; //milli = ratio<1,1000>
using seconds_duration = std::chrono::duration<double, std::ratio<1, 1>>;

#define SUB_THREAD_NUM 1
std::chrono::high_resolution_clock::time_point tps[SUB_THREAD_NUM][2]; //建立一个Time_point类型的数组，每个subThread都有一个start_tp、一个end_tp
milliseconds_duration t1;
int call_intervak_t1 = 5; //执行速度  5ms call 1次

bool thread1_ended = false; //使用detach时，需要独立地提供一种同步机制来等待线程完成

void pause_thread_second(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
}

void pause_thread_millisecond(int n)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(n));
}

//要以一定的频率调用该函数
void threadFunc1()
{
    pause_thread_millisecond(1);
    std::cout << "Thread :" << std::this_thread::get_id() << std::endl;
}

void Func1()
{
    int i = 10;
    double run_time = 0.0f;
    while (i--)
    {
        tps[0][0] = std::chrono::high_resolution_clock::now(); //start_timepoint
        threadFunc1();
        tps[0][1] = std::chrono::high_resolution_clock::now(); //end_tp
        t1 = std::chrono::duration_cast<milliseconds_duration>(tps[0][1] - tps[0][0]);
        if (t1.count() < call_intervak_t1)
            pause_thread_millisecond(call_intervak_t1 - t1.count()); //若执行时间比规定的hz快，则sleep一段时间

        //看是否达到了规定的频率
        tps[0][1] = std::chrono::high_resolution_clock::now();
        t1 = std::chrono::duration_cast<milliseconds_duration>(tps[0][1] - tps[0][0]);
        run_time += t1.count();
        std::cout << "Thread " << std::this_thread::get_id() << "has ran  " << run_time << " ms" << std::endl;
    }
    std::cout << "Sub thread " << std::this_thread::get_id() << " ended." << std::endl;
    thread1_ended = true; //同步标志，线程1已结束
}

int main()
{
    threadCaller();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "back to main.\n";

    auto n = std::thread::hardware_concurrency();
    std::cout << "CPU核心数为:\t" << n << std::endl;
    std::thread myThread(Func1);
    myThread.detach();
    while (!thread1_ended) //同步机制等待  thread1结束
    {
        //此处除了  pause之外， 主线程可以做其他一切自己想做的事情
        pause_thread_second(1);
    }
    pause_thread_second(1);
    std::cout << "Main thread " << std::this_thread::get_id() << " ended." << std::endl;

    return 0;
}