#include <iostream>
#include <cstdlib>
#include <thread>

void sort(int num)
{
    std::this_thread::sleep_for(std::chrono::seconds(num));
    std::cout << num << " ";
}

int main(int argc, char const *argv[])
{
    int i = 1;
    std::thread ths[argc-1];
    for(; i<argc; i++)
    {    
        ths[i-1] = std::thread(sort, atoi(argv[i]));
    }
    for(i=0; i<argc-1; i++)
    {    
        ths[i].join();
    }
    std::cout << std::endl;
    return 0;
}
