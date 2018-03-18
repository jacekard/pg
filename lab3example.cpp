#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

// 1. Drzewo z tablicy forkami
// 2. Drzewo binarne o zadanej wielkości

void binaryForkTree(int how_deep) {
	int my_pid = getpid();
	//printf("I'm process with PID %d!\n", my_pid);

	if (how_deep > 0) {
		printf("I'm process with PID %d, with %d levels to go!\n", my_pid, how_deep);

		int child1_fork, child2_fork;
		if ((child1_fork = fork()) > 0) {
			// We're the parent process, spawn another!
			child2_fork = fork();
		}

		if (child1_fork > 0 && child2_fork > 0) {
			waitpid(child1_fork, NULL, 0);
			waitpid(child2_fork, NULL, 0);
		}

		binaryForkTree(how_deep - 1);
	} else printf("I'm process with PID %d with no levels to go ;-;\n", my_pid);

	sleep(15);
	printf("Process #%d signing off. o7\n", my_pid);
	return;
}

void weirdRecurringTree(int levels) {
	for (int i = levels; i >= 0; i--) {
		printf("Process with PID %d, level %d (loop %d), spawned by %d\n", getpid(), levels, i, getppid());
		if (i == 0) {
			printf("PID %d done!\n", getpid());
			sleep(1);
			return;
		}

		int child_pid = fork();
		if (child_pid == 0) {
			weirdRecurringTree(i - 1);
			return;
		} // else waitpid(child_pid, NULL, 0);
	}
}

int main(int argc, char ** argv) {
	if (argc > 1) {
		int levels = 0;
		printf("Binary tree fork - how many levels? ");
		scanf("%d", &levels);

		binaryForkTree(levels);
	} else weirdRecurringTree(3);

	return 0;
}
