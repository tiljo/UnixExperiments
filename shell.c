#include"myhdr.c"
int main()
{   
	
	int h=0,i=0,j=0,k=0,fd,fdp[2];
	char s[10],r[10],w[10],x[10];
	for(k=0;k<10;k++){
		x[k]=s[k]=r[k]=w[k]=0;
	}
	printf("NOTE: this shell expecting upto 3 arguments\n");
	while(1){
			if(fork()==0){
				printf("myunix$:");
					gets(s);
					sscanf(s,"%s %s	%s",r,w,x);
					/*redirection*/
					if(w[0]=='>'){
						fd = open(x,O_WRONLY | O_CREAT | O_TRUNC,0644);
						close(1);
						dup(fd);
						execlp(r,r,(char*)NULL);
					}
					/*pipe*/
					else if(w[0]=='|'){
						pipe(fdp);
						if(fork()==0){
							close(0);
							dup(fdp[0]);
							close(fdp[1]);
							execlp(x,x,(char*)NULL);
							wait();
						}
						else{
							close(1);
							dup(fdp[1]);
							close(fdp[0]);
							execlp(r,r,(char*)NULL);
						}
					}
					/*basic arguments upto 3*/
					else if(w[0]==0 && x[0]==0 )
						execlp(s,r,(char*)NULL);
					else if(x[0]==0 )
						execlp(r,r,w,(char*)NULL);
					else
						execlp(r,r,w,x,(char*)NULL);
			}
			wait();
	}
	return 0;
}
