/*execute 'ls -R' command using function lsr*/
#include "myhdr.c"
#include"lsr.c"
//#define SIZE 10000
int main(int argc,char *argv[])
{	
	int i=0,j,h=0;
	char *w[SIZE];
	char s[SIZE];
	while(i<SIZE)
		w[i++]=NULL;
	i=0;

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
		else{
			w[h++]=q->d_name;
			//printf("\n-------%d-%s\n",h-1,w[h-1]);
			printf("%s  ",q->d_name);
		}
	}
//	printf("\n\n%s------%s\n",w[0],w[1]);
	i=0;
	while(w[i++]!=NULL){
		//printf("%s ",w[i-1]);
		lsr(w[i-1]);
	}
	printf("\n");
	return 0;
}
