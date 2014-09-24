#include "myhdr.c"
int main()
{
	char buf[100];
	getcwd(buf,sizeof(buf));
	printf("%s \n",buf);
	return 0;
}
