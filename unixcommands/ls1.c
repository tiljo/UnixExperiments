#include "myhdr.c"
int main(int argc,char *argv[])
{	
	int i=0;
	char *s[100];
	DIR *p;
	struct dirent *q;
	assert(argc<2);
	p = opendir(".");//(argv[1]);
	while((q = readdir(p))!=0){
		if((strcmp(q->d_name,".")==0) || strcmp(q->d_name,"..")==0)
			;
		else
			//s[i++]=q->d_name;
			printf("%s  ",q->d_name);
	}
	printf("\n");
	return 0;
}
