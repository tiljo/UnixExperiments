

#include"myhdr.c"
#define SIZE 10000


int checkdir(char *s)
{
	struct stat k;
	stat(s,&k);
	if(k.st_mode & S_IFDIR)
		return 0;
	else return 1;
}


/*checking for "." and ".."*/
int check(char *w){
	if((strcmp(w,".")==0)||(strcmp(w,"..")==0))
		return 0;
	else return 1;
}
/*ls -r function*/
void lsr(char *w,int *count)
{
	if((*count)==1)
		*count = 0;
	else{
	/*leave . and ..*/
		if(check(w)==0)
			return;
	}
/*some initialization*/
	char end[]="/..";
	DIR *p;
	char *re[SIZE];
	int k=0,path;
	while(k<SIZE)
		re[k++]=NULL;
	k=0;
	struct dirent *q;
	int i=0;
	char *r=NULL;
	char *s=NULL;
	char buf[SIZE];
	s=w;
	struct stat l;
	stat(s,&l);
	/*check whether given argument w is a dir..*/
	if( l.st_mode & S_IFDIR ){
		getcwd(buf,sizeof(buf));
		while(buf[i++]!=0);
		buf[i-1] ='/';buf[i]='\0';
		strcat(buf,s);
		r=buf;//creating pwd
		chdir(r);//change dir to  given dir..
	}
	/*for a valid path print 'ls'*/
	if(r!=NULL){
		printf(".");
		for(path=54;r[path]!=0;path++)
			printf("%c",r[path]);
		printf(":\n");
		p = opendir(r);
		while((q = readdir(p))!=0){
			if(check(q->d_name)==0);
			else{
				printf("%s ",q->d_name);
			}
		}
		closedir(p);
		printf("\n");


	p = opendir(r);
		while((q = readdir(p))!=0){
			if(check(q->d_name)==0);
			else{
				lsr(q->d_name,count);
			}
		}
		closedir(p);

		printf("\n");
		k=0;
		strcat(r,end);//creating backward path
		chdir(r);//moving backward 
	}
}



/*execute 'ls -R' command using function lsr*/
int main(int argc,char *argv[])
{	
	int count =1;
	lsr(argv[1],&count);
	return 0;
}
