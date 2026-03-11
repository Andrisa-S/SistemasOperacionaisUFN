#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t procID;
	procID = fork();
	
	if (procID < 0)
	{
		printf("Erro na criação do novo processo\n");
		return -1;
	}
	else if (procID == 0)
		{
		printf("Processo filho - PID = %d\n", getpid());
		//execl("./procTwo", (char *) NULL);
		//execl("./bin/ls", "ls", "-l", (char *) NULL);
		//execl("./bin/ps", "ps", "-aux", (char *) NULL);
		exit(0);
		}
		else
		{
		printf("Processo Pai - PID = %d\n", getpid());
		return 0;
		}
}
