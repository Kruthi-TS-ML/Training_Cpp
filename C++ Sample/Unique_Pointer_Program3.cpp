/* Unique Pointer in C++ using class */
#include <iostream>
#include <memory>
using namespace std;
class Sample
{
    public:
    Sample()
    {
        cout << "Constructor called" << endl;
    }
    ~Sample()
    {
        cout << "Destructor called" << endl;
    }
};
int main()
{
    unique_ptr<Sample> sam1 = make_unique<Sample>();
    return 0;
}