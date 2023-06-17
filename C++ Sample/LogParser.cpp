#include <iostream>
using namespace std;

class Singleton{
	private:
		string message;		

		static Singleton *instancePtr;

		Singleton() {}
	public:
		Singleton(const Singleton &obj) = delete;
	
		static Singleton *getInstance()
		{
			return instancePtr;
		}

		void setValues(string msg)
		{
			this->message = msg;
		}

		void printLog()
		{
			cout << " Message:  " << message << endl;
		}
};

Singleton *Singleton ::instancePtr = new Singleton();

int main()
{
	Singleton *ptr = Singleton::getInstance();
	ptr->setValues("Hello World!");
	ptr->printLog();

	ptr->setValues("Welcome!");
	ptr->printLog();
	return 0;
}
