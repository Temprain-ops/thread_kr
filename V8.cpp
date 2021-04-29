// V8.cpp : This file contains the 'main' function. Program execution begins
// and ends there.
//

//#include "pch.h"
#include <tchar.h>
#include "windows.h"
#include "iostream"
#include "process.h"
#define threads 8
#define M 13
typedef struct MyData {
    int val1;
} MYDATA, * PMYDATA;

int counter = 0;
HANDLE hSemaphore;

DWORD WINAPI MyThreadFunction(LPVOID lpParam) {

    PMYDATA pDataArray;
    pDataArray = (PMYDATA)lpParam;
    int numThread = pDataArray->val1;
    WaitForSingleObject(hSemaphore,	INFINITE);
    for (int i = 0; i < M; ++i) {
        counter += numThread;
        std::cout <<numThread<<" "<< counter << std::endl;
    }
    ReleaseSemaphore(
            hSemaphore,	// указатель на светофор
            1,		// изменяет счетчик на 1
            NULL);
    return 0;
}

int main()
{
    PMYDATA pDataArray[threads];
    DWORD   dwThreadIdArray[threads];
    HANDLE  hThreadArray[threads];


    hSemaphore = CreateSemaphore(
            NULL,	// нет атрибута
            1,	// начальное состояние
            1,	// максимальное состояние
            "semaph"
    );

    for (int i = 0; i < threads; ++i) {
        pDataArray[i] = (PMYDATA)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
                                           sizeof(MYDATA));
        pDataArray[i]->val1 = i + 1;
        hThreadArray[i] = CreateThread(
                NULL,                   // default security attributes
                0,                      // use default stack size
                MyThreadFunction,       // thread function name
                pDataArray[i],          // argument to thread function
                CREATE_SUSPENDED, &dwThreadIdArray[i]);
    }
    for (int i = 0; i < threads; ++i) {
        ResumeThread(hThreadArray[i]);
    }
    WaitForMultipleObjects(threads, hThreadArray, TRUE, INFINITE);
    std::cout.flush();
    return 0;
}



