#include <iostream>
#include <csignal>
using namespace std;

void signalHandler( int signum ) {
   	switch(signum)
   	{
	   case SIGINT  : cout << "\nSIGINT signal received!" << endl;
			  break;
	   case SIGTERM : cout << "\nSIGTERM signal received!" << endl;
			  break;
	   case SIGSEGV : cout << "\nSIGSEGV signal received!" << endl;
			  break;
	   case SIGFPE : cout << "\nSIGFPE signal received!" << endl;
			  break;
	   default: cout << "Exitting from code ..! " << endl;
   		    
   	}
	cout << "Demo: Interrupt signal received: " << signum << endl;
	exit(signum);  
}

int main () 
{
	signal(SIGINT, signalHandler);  //2
	signal(SIGTERM, signalHandler); //15
	signal(SIGSEGV, signalHandler); //11
	signal(SIGFPE, signalHandler); //11
	/* The following lines have to be uncommented to demonstrate 
	* segmentation fault - SIGSEGV signal */
	//char *str = "Hello";
	//*(str + 1) = 'A';
	/* SIGFPE signal is caused by a fatal arithmetic operation like divide by 0. 
	 * It can also be checked by using raise() explicitly */
	//raise(SIGFPE);
	while(1) {
		cout << "Going to sleep...." << endl;
		sleep(1);
	}

	return 0;
}
