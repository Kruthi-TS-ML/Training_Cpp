#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string>
#define FAILURE -1
#define MAX_SIZE 64
#define MESSAGE "Program"
#define PERMISSION 0666

using namespace std;

struct buffer
{
	long int msg_type;
	char msg[MAX_SIZE];
}buf, recv_buf;

int main()
{
	key_t key;
	int msg_id = 0;

	key = ftok(MESSAGE, MAX_SIZE);
	if(key == FAILURE)
	{
		cout << "ftok() failed!" << endl;
		return 1;
	}
	msg_id = msgget(key, PERMISSION | IPC_CREAT);
	if(msg_id == FAILURE)
	{
		cout << "msgget() failed!" << endl;
		return 1;
	}
	/* Set the message type */
	buf.msg_type = 1;
	cout << "Enter text: ";
	cin.getline(buf.msg, MAX_SIZE);
	/* Send the message */
  msgsnd(msg_id, &buf, sizeof(buf), 0);
	cout << "Data sent : " << buf.msg << endl;
	/* Receive message */
  msgrcv(msg_id, &recv_buf, sizeof(recv_buf), 1, 0);
  cout << "Data received : " << recv_buf.msg << endl;
  /* Delete message queue created */
  msgctl(msg_id, IPC_RMID, NULL);
	return 0;
}
