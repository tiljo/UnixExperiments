#include"myhdr.c"
int main(int argc, char *argv[])
{
	struct stat t;
	while(--argc > 0){
		if(stat((*++argv),&t)==-1){
			perror("stat");
			exit(1);
		}
		else{
	  	printf("filename: '%s'\n", *argv);
		  printf(" device: %lld\n",                     (long long int)  t.st_dev);
		  printf(" inode: %ld\n",                         t.st_ino);
		  printf(" protection: %o\n",                     t.st_mode);
		  printf(" number of hard links: %d\n",         (int)  t.st_nlink);
		  printf(" user ID of owner: %d\n",               t.st_uid);
		  printf(" group ID of owner: %d\n",              t.st_gid);
		  printf(" device type (if inode device): %lld\n",(long long int)t.st_rdev);
		  printf(" total size, in bytes: %ld\n",          t.st_size);
		  printf(" IO Block: %ld\n",  t.st_blksize);
		  printf(" Blocks: %ld\n",    t.st_blocks);
		  printf(" time of last access: %ld : %s",        t.st_atime, ctime(&t.st_atime));
    	  printf(" time of last modification: %ld : %s",  t.st_mtime, ctime(&t.st_mtime));
		  printf(" time of last change: %ld : %s",        t.st_ctime, ctime(&t.st_ctime));	
		}
	}
	  return 0;
}

