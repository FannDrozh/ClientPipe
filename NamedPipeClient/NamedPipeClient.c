#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#define SIZE_BUFFER 140
int main()
{
	system("chcp 1251");
	//������� 1
	//LPSTR lpszPipeName = L"\\\\.\\pipe\\MyPipe";//����� �� ��� �� �������
	//HANDLE hNamedPipe;
	//BOOL flag_otvet = TRUE;
	//char message[SIZE_BUFFER];
	//DWORD size_buffer = SIZE_BUFFER;
	//DWORD actual_written;
	//DWORD actual_readen;
	//BOOL isSuccess;
	//BOOL SuccessRead;
	//DWORD dwMode = PIPE_READMODE_MESSAGE;
	//LPWSTR buffer = (CHAR*)calloc(size_buffer, sizeof(CHAR));
	//while (TRUE)
	//{
	//	hNamedPipe = CreateFile(lpszPipeName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	//	isSuccess = SetNamedPipeHandleState(hNamedPipe, &dwMode, NULL, NULL);
	//	if (!isSuccess)
	//	{
	//		printf("������ �� ��������\n");
	//		flag_otvet = TRUE;
	//	}
	//	else
	//	{
	//		//printf("���������� �����������:\n");
	//		if (flag_otvet)
	//		{
	//			printf("������� ��������� ��� �������:\n");
	//			gets(message);
	//			buffer = &message;
	//			WriteFile(hNamedPipe, buffer, size_buffer, &actual_written, NULL);
	//			flag_otvet = FALSE;
	//		}
	//		SuccessRead = ReadFile(hNamedPipe, buffer, size_buffer, &actual_readen, NULL);
	//		if (SuccessRead)
	//		{
	//			printf("\n������ �����: ");
	//			printf(buffer);
	//			putchar('\n');
	//			flag_otvet = TRUE;
	//		}
	//	}
	//	Sleep(1000);
	//	CloseHandle(hNamedPipe); 
	//}
	//������� 2
	printf("���������� ����� � �������\n");
	LPSTR lpszPipeName = L"\\\\.\\pipe\\MyPipe";//����� �� ��� �� �������
	HANDLE hNamedPipe;
	BOOL flag_otvet = TRUE;
	char message[SIZE_BUFFER];
	DWORD size_buffer = SIZE_BUFFER;
	DWORD actual_written;
	DWORD actual_readen;
	BOOL isSuccess;
	BOOL SuccessRead;
	DWORD dwMode = PIPE_READMODE_MESSAGE;
	LPWSTR buffer = (CHAR*)calloc(size_buffer, sizeof(CHAR));
	while (TRUE)
	{
		hNamedPipe = CreateFile(lpszPipeName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
		isSuccess = SetNamedPipeHandleState(hNamedPipe, &dwMode, NULL, NULL);
		if (!isSuccess)
		{
			printf("������ �� ��������\n");
			flag_otvet = TRUE;
		}
		else
		{
			//printf("���������� �����������:\n");
			if (flag_otvet)
			{
				printf("������� ����� ��� �������:\n");
				gets(message);
				buffer = &message;
				WriteFile(hNamedPipe, buffer, size_buffer, &actual_written, NULL);
				flag_otvet = FALSE;
			}
			SuccessRead = ReadFile(hNamedPipe, buffer, size_buffer, &actual_readen, NULL);
			if (SuccessRead)
			{
				printf("\n������ �����: ");
				printf(buffer);
				putchar('\n');
				flag_otvet = TRUE;
			}
		}
		Sleep(1000);
		CloseHandle(hNamedPipe); 
	}
}