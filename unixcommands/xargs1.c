#include"myhdr.c"
int main(int argc,char *argv[])
{
	int n,i=0,h=0,l=1,k=0;
	char buf[1000];
	char *rslt[10];
	char *til[10];
	while(i<10)
		til[i++]=NULL;
	i=0;
	while(i<10)
		rslt[i++]=NULL;
	while((n = read(0,buf,sizeof(buf)-1))){
		buf[n-1]='\0';
		break;
	}
    char * pch;
    pch = strtok (buf," ,.\n");
    for (h=0; pch != NULL;h++){
		rslt[h]=pch;
		pch = strtok (NULL, " ,.\n");
    }

	h=0;
	while(l<argc){
		til[k++]=argv[l++];
	}
	while(rslt[h]!=0){
		til[k++]=rslt[h++];
	}
	for(k=0;til[k]!=0;k++){
		printf("%s\n",til[k]);
	}
	if(fork()==0){
		execvp(argv[1],til);
	}
	wait();
	return 0;
}

