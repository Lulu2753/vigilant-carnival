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

extern struct User admin;
extern struct Info info[100];



void psw();
