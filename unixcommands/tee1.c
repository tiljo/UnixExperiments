#include"myhdr.c"
#define SIZE 1000
int main(int argc, char *argv[])
{
	char buf[SIZE];
	int fd,n;
	fd = open(argv[1],O_RDWR|O_CREAT|O_TRUNC,0644);
	while((n = read(0,buf,sizeof(buf)-1))>0){    /*when sizeof(buf) replaced by SIZE error(n=1) occurs?*/
			write(1,buf,n);
			write(fd,buf,n);
	}
	return 0;
}


