#include <iostream>
#include <ctime>
using namespace std;

int main() 
{
   time_t systime = time(0);

   // convert now to string form
   char* date_time = ctime(&systime);

   cout << "The current date and time is: " << date_time << endl;
}