/* Shared memory - IPC Mechanism
* Sender program does the following:
* 1. Create a shared memory segment 
* 2. Attach to the shared memory segment created
* 3. Write data
*/

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
	int shmid = shmget((key_t)key, 1024, 0666 | IPC_CREAT);
	string buffer = "Hello World!";
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
	strcpy((char *)attach, buffer.c_str());	
	cout << "Writer: " << (char*)attach << endl;
	shmdt(attach);
	return 0;
}
