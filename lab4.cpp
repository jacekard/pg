#include<stdio.h>
#include<Windows.h>

DWORD WINAPI threadFunction(void *args) {
	Sleep(3000);
	return 0;
}

int calculateMaxProcesses() {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	int i = 0;
	while (CreateProcess(NULL, (LPSTR)"app.exe", NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi) != NULL) {
		printf("Utworzono %d procesow\r", i);
		i++;
	}
	return i;
}

int calculateMaxThreads(int stackSize) {
	int i = 0;
	DWORD dwCreationFlags = STACK_SIZE_PARAM_IS_A_RESERVATION;
	while (CreateThread(NULL, stackSize, threadFunction, NULL, dwCreationFlags, NULL) != NULL) {
		i++;
	}
	return i;
}



int main() {
	//printf("Max threads x86 with stack size of 1MB: %d\n", calculateMaxThreads(0));
	//Sleep(3000);
	//printf("Max threads x86 with stack size of 4097B: %d\n", calculateMaxThreads(4097));
	printf("Max processes %d\n", calculateMaxProcesses());
	system("pause");
	return 0;
}
