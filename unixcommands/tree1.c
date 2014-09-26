
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
void lsr(char *w,int *count,int *tabn)
{
	if((*count)==1){
		*count = 0;
		*tabn=-1;
	}
	else{
	/*leave . and ..*/
		if(check(w)==0)
			return;
	}
/*some initialization*/
	char end[]="/..";
	char tab[10];
	int i=0;
	int t=0;
	DIR *p;
	char *re[SIZE];
	int k=0,path;
	while(k<SIZE)
		re[k++]=NULL;
	k=0;
	struct dirent *q;
	//int i=0;
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
		(*tabn)++;
	}
	/*for a valid path print 'ls'*/
	if(r!=NULL){
		path = (*tabn)*2;
		for(t=0;t<(path);t++){
			tab[t]='|';
			tab[t+1]='\t';
			t++;
		}
		tab[t]='\0';
		 t=0;

		/**/
		p = opendir(r);
		while((q = readdir(p))!=0){
			if(check(q->d_name)==0);
			else{
				if(q->d_name == NULL)return;
				printf("%s|--%s\n",tab,q->d_name);
				lsr(q->d_name,count,tabn);
			}
		}
		closedir(p);
		k=0;
		strcat(r,end);//creating backward path
		(*tabn)--;
		chdir(r);//moving backward 
	
	}
}



/*execute 'ls -R' command using function lsr*/
int main(int argc,char *argv[])
{	
	int count =1;int tabn =0;
	if(argc>1){
		printf("usage error:no arguments expected with tree\n");
		exit(1);
	}
	lsr(".",&count,&tabn);
	return 0;
}
