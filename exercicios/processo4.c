#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	
	fork();
	fork();
	
	printf("PID = %d\n", getpid());
	
	return 1;
}
