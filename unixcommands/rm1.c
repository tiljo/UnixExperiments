#include"myhdr.c"
int main(int argc, char *argv[])
{
	int i = 0,p=0;
	for(i =1; i<=argc-1; i++){
		p = remove(argv[i]);
		if(p== -1){
			printf("warning: directory %s is not empty\n",argv[i]);
			break;
		}
	}
	return 0;
}


