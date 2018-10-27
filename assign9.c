#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd,fd1;
	char buffer[20],buffer1[20];

	fd = open("file1.txt",O_RDWR | O_CREAT , 0777);
	write(fd,"HELLOWORLD",10);
	close(fd);

	fd = open("file1.txt",O_RDONLY, 0777);
	read(fd,buffer,sizeof(buffer)-1);
	printf("File 1 contains %s \n",buffer);

	fd1 = open("file2.txt",O_RDWR | O_CREAT , 0777);
	write(fd1,buffer,sizeof(buffer)-1);
	close(fd1);

	fd1 = open("file1.txt",O_RDONLY, 0777);
	write(fd1,buffer1,sizeof(buffer1)-1);
	printf("File 2 contains %s \n",buffer);

}

