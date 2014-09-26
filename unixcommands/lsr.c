#define SIZE 10000
/*checking for "." and ".."*/
int check(char *w){
	if((strcmp(w,".")==0)||(strcmp(w,"..")==0))
		return 0;
	else return 1;
}
/*ls -r function*/
void lsr(char *w)
{
	/*leave . and ..*/
	if(check(w)==0)
		return;
/*some initialization*/
	char end[]="/..";
	DIR *p;
	char *re[SIZE];
	int k=0;
	while(k<SIZE)
		re[k++]=NULL;
	k=0;
	struct dirent *q;
	int i=0;
	char *r=NULL;
	char *s=NULL;
	char buf[SIZE];
	s=w;
	//s=argv[1];

	struct stat l;
	stat(s,&l);
	/*check whether given argument w is a dir..*/
	if( l.st_mode & S_IFDIR ){
		printf("\n./%s\n",s);
		getcwd(buf,sizeof(buf));
		while(buf[i++]!=0);
		buf[i-1] ='/';buf[i]='\0';
		strcat(buf,s);
		r=buf;//creating pwd
		chdir(r);//change dir to  given dir..
	}
	/*for a valid path print 'ls'*/
	if(r!=NULL){
		printf("PATH->%s\n",r);
		p = opendir(r);
		while((q = readdir(p))!=0){
			printf("%s ",q->d_name);
			if(check(q->d_name)==0);
			else re[k++]=q->d_name;//store filenames in a array
		}
		closedir(p);
		//k=0;
		//printf("\n");
			/*for(k=0;re[k]!=NULL;k++){
				printf("REP%d->%s ",k,re[k]);
			}*/
			printf("\n");
	/*recursive call for files within the directory*/
		for(k=0;re[k]!=NULL;k++){
			//printf("RE%d->%s ",k,re[k]);
			 lsr(re[k]);
		//	 strcat(r,end);
		//	chdir(r);
		}
		k=0;
		strcat(r,end);//creating backward path
	//	printf("END->%s\n",r);
		chdir(r);//moving backward 

		printf("\n");
	}

//	return 0;
}
