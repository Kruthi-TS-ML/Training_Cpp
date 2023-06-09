#include <iostream>
#include <memory>
using namespace std;

class SmartPointers
{
    int value;
    public:
        SmartPointers(int x) : value(x) { cout << "Constructor called!" << endl;}
        ~SmartPointers() {cout << "Destructor called!" << endl;}
        void put_x()
        {
            cout << "Value = " << value << endl;
        } 
};

int main()
{
    cout << "Smart Pointers Demonstration!" << endl;

    //auto_ptr 
    {
        auto_ptr<SmartPointers> sPtr {new SmartPointers(10)};
        sPtr->put_x();
        auto_ptr<int> intPtr {new int(35)};
        cout << "Value is " << *intPtr << endl;
    }
    //unique_ptr
    {
        unique_ptr<SmartPointers> uPtr = make_unique<SmartPointers>(25);
        uPtr->put_x();
    }
    //shared_ptr
    {
        shared_ptr<SmartPointers> shPtr {new SmartPointers(120)};
        shPtr->put_x();
        cout << "Shared count " << shPtr.use_count() << endl;
        shared_ptr<SmartPointers> shPtr2 = shPtr;
        shPtr2->put_x();
        cout << "Shared count " << shPtr.use_count() << endl;
    }
}