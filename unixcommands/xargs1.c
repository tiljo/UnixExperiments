#include"myhdr.c"
#define SIZE 1000
int main(int argc,char *argv[])
{
	int n,i=0,h=0,l=1,k=0;
	char buf[SIZE];
	char *rslt[SIZE];
	char *til[SIZE];
	/*clearing all buffers*/
	while(i<SIZE){
		rslt[i]=til[i]=NULL;
		i++;
	}
	/*reading from stdin*/
	while((n = read(0,buf,sizeof(buf)-1))){
		buf[n-1]='\0';
		break;
	}
	/*parsing the stdin and store to rslt[]*/
    char * pch;
    pch = strtok (buf," ,\n");
    for (h=0; pch != NULL;h++){
		rslt[h]=pch;
		pch = strtok (NULL, " ,\n");
    }
	/*copying argv[] and rslt[] to til[]*/
	h=0;
	while(l<argc){
		til[k++]=argv[l++];
	}
	while(rslt[h]!=0){
		til[k++]=rslt[h++];
	}
	/*executing the command*/
	if(fork()==0){
		execvp(argv[1],til);
	}
	wait();
	return 0;
}

