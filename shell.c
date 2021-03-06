#include"myhdr.c"
int main()
{   
	
	int i=0,fd,fdp[2];
	char s[50],r[50],w[50],x[50];
	printf("NOTE: this shell expecting upto 3 arguments\n");
	while(1){

			for(i=0;i<50;i++){
				x[i]=s[i]=r[i]=w[i]=0;
			}

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
					else if(w[0]=='<'){
						fd = open(x,O_RDONLY);
						close(0);
						dup(fd);
						execlp(r,r,(char*) NULL);
					}


					/*pipe*/
					else if(w[0]=='|'){
						pipe(fdp);
						if(fork()==0){
							close(0);
							dup(fdp[0]);
							close(fdp[1]);
							execlp(x,x,(char*)NULL);
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
