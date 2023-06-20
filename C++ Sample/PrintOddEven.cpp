#include <iostream>
#include <thread>
using namespace std;

//Make this program to print the numbers in ascending order.
//And the threads needs to sync and print their numbers accordingly.
//Exampe:
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
//Please check the thread synchronization and do it

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
