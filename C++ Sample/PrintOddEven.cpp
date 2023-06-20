#include <iostream>
#include <thread>
using namespace std;

void PrintOdd()
{
    int y = 1;
    while(y <= 20)
    {
        if(y % 2 == 1)
        	cout << "Odd: " << y << endl;
        y++;
    }
}

void PrintEven()
{
    int x = 1;
    while(x <= 20)
    {
        if(x % 2 == 0)
        	cout << "Even: " << x << endl;
        x++;
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
