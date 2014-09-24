#include"myhdr.c"
int main(int argc, char *argv[])
{
	int i=0;
	for(i=1; i<=argc-1;i++)
		mkdir(argv[i],S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
	return 0;
}
