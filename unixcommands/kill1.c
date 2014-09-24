#include"myhdr.c"
int main(int argc, char *argv[])
{
	int i=0;
	assert(argc<4);
	atoi(argv[1]);
	kill(atoi(argv[1]),atoi(argv[2]));
	perror("kill:");
	return 0;
}
