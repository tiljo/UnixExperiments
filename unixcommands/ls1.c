#include "myhdr.c"
int main(int argc,char *argv[])
{	
	int i=0,j;
	char s[100];
	getcwd(s,sizeof(s));
	for(i=0;s[i]!='\0';i++);
	s[i++]='/';
	
	for(j=0;argv[1][j]!=0;j++)
		s[i++]=argv[1][j];
	s[i]=0;

	DIR *p;
	struct dirent *q;
	assert(argc<3);
	p = opendir(s);//(argv[1]);
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
