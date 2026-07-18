#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (int argc, char *argv[])
{
	pid_t pid;
	char *arg[] = {"free", "-m"};

	pid = fork();
	switch (pid) {
	case -1:
		perror("fork");
		exit(EXIT_FAILURE);
	case 0:
		// child
		printf("fork success\n");
		execvp(arg[0], arg);
	default:
		// parent
		wait(NULL);
		printf("child successfully done...\n");
	}


	return 0;
}
