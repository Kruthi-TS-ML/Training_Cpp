#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#define MAX 20

std::mutex mu;
std::condition_variable cond;
int count = 1;

void PrintOdd()
{
    while(count < MAX)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker,[](){ return (count%2 == 1); });
        std::cout << "Odd: " << count << std::endl;
        count++;
        locker.unlock();
        cond.notify_all();
    }
}

void PrintEven()
{
    while(count < MAX)
    {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker,[](){ return (count%2 == 0); });
        std::cout << "Even: " << count << std::endl;
        count++;
        locker.unlock();
        cond.notify_all();
    }
}

int main()
{
    std::thread t1(PrintOdd);
    std::thread t2(PrintEven);
    t1.join();
    t2.join();
    return 0;
}
