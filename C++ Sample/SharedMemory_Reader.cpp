#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string>
#include <cstring>
#define FAILURE -1
using namespace std;

int main()
{
	int key = 1234;
	int shmid = shmget((key_t)key, 1024, 0666);
	
	if(shmid == FAILURE)
	{
		cout << "Error in creating a shared memory." << endl;
		return 1;
	}
	void *attach = shmat(shmid, NULL, 0);
	if(attach == (void *)FAILURE)
	{
		cout << "Error in attaching to a shared memory." << endl;
		return 1;
	}
	cout << "Address of shared memory is " << attach << endl;
	cout << "Reader: " << (char*)attach << endl;
	shmdt(attach);
	return 0;
}
