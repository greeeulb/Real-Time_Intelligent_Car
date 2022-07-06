#include <iostream>
#include <unistd.h>
#include <cstring>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstdlib>
using namespace std;
#define USEPORT 1234

#include "up.cpp"
#include "down.cpp"
#include "right.cpp"
#include "left.cpp"
#include "stop.cpp"
//111111 直接引用:在一个cpp文件中调用另外一个cpp文件, main.cpp与xxx.cpp在同一目录下

int main()
{
	//**** create socket
	int serverSock = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSock < 0)
	{
		cout << "socket creation failed" << endl;
		exit(-1);
	}
	cout << "socket creation successfully" << endl;
	//**** bind ip and port
	struct sockaddr_in serverAddr;
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(USEPORT);
	//INADDR_ANY
	serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//**** bind socket
	if (bind(serverSock,
		(struct sockaddr*)&serverAddr,
		sizeof(struct sockaddr)) == -1)
	{
		cout << "Bind error, Port[" << USEPORT << "]" << endl;
		exit(-1);
	}
	cout << "Bind successfully" << endl;

	//**** listen
	if (listen(serverSock, 10) == -1)
	{
		cout << "Listen error!" << endl;
	}
	cout << "Listening on port[" << USEPORT << "]" << endl;

	//**** start to accept
	struct sockaddr clientAddr;
	int size = sizeof(struct sockaddr);

	int clientSock = accept(serverSock, (struct sockaddr*)&clientAddr, (socklen_t*)&size);

	cout << "The Controler Connected!" << endl;
	//system("sudo python stop.py");//2222222
	//**** communication
	while (1)
	{
		char revData[5];
		int ret = recv(clientSock,revData,5,0);
		if(ret > 0){
			revData[ret] = 0x00;
			cout<<"retrevData:"<<revData<<endl;
		}
		cout<<"lenth:"<<ret<<endl;
		cout<<"revData:"<<revData<<endl;
		if(strcmp(revData, "UPUP") == 0){
			cout<<"up"<< '\n';
			/*system("ls");打开system清单，py
			system("sudo python up.py");引用 py的up文件*/
			//3333333
			go_up();//或者试试return go_up();
			//444
		}
		else if(strcmp(revData,"DOWN") == 0){
			/*system("sudo python down.py");*/
			go_down();
			cout<<"down"<< '\n';
		}
		else if(strcmp(revData,"LEFT") == 0){
			/*system("sudo python left.py");*/
			go_left();
			cout<<"left"<< '\n';
			/*printf是C语言的输出函数，C++兼容C所以也可以在C++中使用；cout是C++专有的输出流ostream对象*/
		}
		else if(strcmp(revData,"RIGHT") == 0){
			/*system("sudo python right.py");*/
			go_right();
			cout<<"right"<< '\n';
		}
		else if(strcmp(revData,"STOP") == 0){
			/*system("sudo python stop.py");*/
			go_stop();
			cout<<"stop"<< '\n';
		}
		else if(strcmp(revData,"QUIT") == 0){
			cout<<"shutdown"<<endl;
			break;
		}
	}

	close(serverSock);
	return 0;
}
