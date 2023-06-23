#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#define MAX_BYTES 256

using namespace std;

int main() 
{
	int fd[2];
	int pid = 0;
	if(pipe(fd) == -1)
	{
		cout << "Pipe creation failed!" << endl;
		return 1;
	}
  	
  	pid = fork();
  	
  	if(pid < 0)
  	{
  		cout << "Process creation failed!" << endl;
		return 1;
	}
	if(pid > 0)
	{
		string message;
		cout << "Enter a message: " << endl;
		cin >> message;
		/* Parent Process is dedicated to write */
		close(fd[0]);
		if(write(fd[1], message.c_str(), message.length()) == -1) 
		{
			std::cerr<< "Error: write to pipe failed" << std::endl;
            		return 1;  
            	}
            	
        	close(fd[1]);
	}
	else
	{
		char buffer[MAX_BYTES];
		/* Child Process is dedicated to read */
		close(fd[1]);
		if (read(fd[0], buffer, sizeof(buffer)) == -1) 
		{
			cout << "Read failed!" << endl;
			return 1;
		}
		cout << "Buffer received is " << buffer << endl;
		close(fd[0]);
	}
	
	return 0;
}
