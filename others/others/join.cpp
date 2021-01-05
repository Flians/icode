/**
 * thread::join(): 阻塞当前线程，直至 *this 所标识的线程完成其执行。*this 所标识的线程的完成同步于从 join() 的成功返回。
 * 主线程等待子进程期间什么都不能做, thread::join()会清理子线程相关的内存空间,
 * 此后thread object将不再和这个子线程相关了，即join对于一个子线程来说只可以被调用一次
 */
#include <iostream>
#include <thread>
#include <chrono>
#include<boost/thread.hpp>
#include<boost/noncopyable.hpp>
 
void foo()
{
    std::cout << "foo is started\n";
    // 模拟昂贵操作
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "foo is done\n";
}
 
void bar()
{
    std::cout << "bar is started\n";
    // 模拟昂贵操作
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "bar is done\n";
}

void do_something(int& i){  
    i++;  
}  
class func{  
    public:  
        func(int& i):i_(i){}  
        void operator() (){  
            for(int j=0;j<100;j++)  
                do_something(i_);  
        }  
    public:  
        int& i_;  
};
void do_something_in_current_thread(){}


void f(){  
    int local=0;  
    func my_func(local);  
    boost::thread t(my_func);  
    try{  
        do_something_in_current_thread();  
    }  
    catch(...){  
        t.join();//确保在异常条件下join子线程  
        throw;  
    }  
    t.join();  
} 


class thread_guard:boost::noncopyable{  
    public:  
        explicit thread_guard(boost::thread& t):t_(t){}  
        ~thread_guard(){  
            if(t_.joinable()){//检测是很有必要的，因为thread::join只能调用一次，要防止其它地方意外join了  
               t_.join();  
            }  
        }  
        //thread_guard(const thread_guard&)=delete;//c++11中这样声明表示禁用copy constructor需要-std=c++0x支持，这里采用boost::noncopyable已经禁止了拷贝和复制  
        //thread_guard& operator=(const thread_guard&)=delete;  
    private:  
        boost::thread& t_;  
};   
void fun(){  
    int local=0;  
    func my_func(local);  
    boost::thread t(my_func);  
    thread_guard g(t);  
    do_something_in_current_thread();  
}
 
int main()
{
    std::cout << "starting first helper...\n";
    std::thread helper1(foo);
 
    std::cout << "starting second helper...\n";
    std::thread helper2(bar);
    std::cout << "done!\n";
 
    std::cout << "waiting for helpers to finish...\n" << std::endl;
    helper1.join();
    helper2.join();

    /* 异常环境下join，假设主线程在一个函数f()里面创建thread object,接着f()又调用其它函数g(),那么确保在g()以任何方式下退出主线程都能join子线程 */
    f();

    /* 采用RAII(资源获取即初始化)，将一个thread object通过栈对象A管理，在栈对象A析构时调用thread::join.按照局部对象析构是构造的逆序，栈对象A析构完成后再析构thread object */
    fun(); 
    return 0;
}