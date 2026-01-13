struct Info
{
	char subject[100];
	int term;
	double credit;
	double score;
	char type;

};

struct User
{
	char name[20];
	char password[50];
};

extern struct User admin;  //定义的时候就没有extern
extern struct Info info[100];   //头文件声明，源文件定义！！



void psw();
