#include"myhdr.c"
int main(int argc, char *argv[])
{
	int pid=0;
	if(argc>2)
		printf("usage:accept pid only");
	assert(argc<3);
	pid =atoi(argv[1]);
	if(kill(pid,SIGKILL)==-1)
		perror("kill:");
	return 0;
}
