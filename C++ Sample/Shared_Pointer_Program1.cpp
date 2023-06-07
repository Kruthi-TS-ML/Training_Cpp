/* Shared Pointer in C++ using class */
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
    shared_ptr<Sample> sam1 = make_shared<Sample>();
    shared_ptr<Sample> sam2 = sam1;
    cout << "Count is " << sam1.use_count() << endl;
    return 0;
}