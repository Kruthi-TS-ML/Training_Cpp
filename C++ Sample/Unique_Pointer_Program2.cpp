/* Unique Pointer in C++ */
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int> ptr1 = make_unique<int>(25);
    cout << *ptr1 << endl;
    return 0;
}