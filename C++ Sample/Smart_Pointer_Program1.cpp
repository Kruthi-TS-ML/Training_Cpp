#include <iostream>
using namespace std;

class Sample
{
  int *ptr;
  public:
    explicit Sample(int *data = NULL)
    {
        ptr = data;
    }
    ~Sample()
    {
        cout << "Destructor called" << endl;
        delete ptr;
    }
    int & operator * () { return *ptr; }
};

int main()
{
    int *p = new int(19);
    Sample sObj = Sample(p);
    cout << *sObj << endl;
    return 0;
}