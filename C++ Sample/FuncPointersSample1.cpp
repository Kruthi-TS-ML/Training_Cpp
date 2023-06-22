#include <iostream>
using namespace std;

int add(int a, int b)
{
    return (a+b);
}

int multiply(int a, int b)
{
    return (a*b);
}

int subtract(int a, int b)
{
    if (a > b)
    {
        return (a - b);
    }
    else
    {
        return (b - a);
    }
}

typedef int (*funcPtr)(int, int);

int main()
{
   int res = 0;
   funcPtr fp[] = {add, multiply,subtract};
   for(int i = 0; i < 3; i++)
   {
        res = fp[i](10,20);
        cout << "Result is " << res << endl;
   }
    
    return 0;
}
