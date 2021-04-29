// V7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include "windows.h"
#include "iostream"
#include "process.h"

typedef struct MyData {
  int val1;
  CRITICAL_SECTION* val2;
} MYDATA, * PMYDATA;

int counter = 0;

DWORD WINAPI MyThreadFunction(LPVOID lpParam) {

  PMYDATA pDataArray;
  pDataArray = (PMYDATA)lpParam;
  int numThread = pDataArray->val1;
  CRITICAL_SECTION* critsect = pDataArray->val2;
  EnterCriticalSection(critsect);
  for (int i = 0; i < 18; ++i) {
    counter += numThread;
    std::cout <<numThread<<" "<< counter << std::endl;
  }
  LeaveCriticalSection(critsect);
  return 0;
}

int main()
{
  PMYDATA pDataArray[10];
  DWORD   dwThreadIdArray[10];
  HANDLE  hThreadArray[10];

  CRITICAL_SECTION critsect;
  InitializeCriticalSection(&critsect);
  for (int i = 0; i <= 9; ++i) {
    pDataArray[i] = (PMYDATA)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
                                       sizeof(MYDATA));
    pDataArray[i]->val1 = i + 1;
    pDataArray[i]->val2 = &critsect;
    hThreadArray[i] = CreateThread(
        NULL,                   // default security attributes
        0,                      // use default stack size
        MyThreadFunction,       // thread function name
        pDataArray[i],          // argument to thread function
        CREATE_SUSPENDED, &dwThreadIdArray[i]);
  }
  for (int i = 0; i <= 9; ++i) {
    ResumeThread(hThreadArray[i]);
  }
  WaitForMultipleObjects(10, hThreadArray, TRUE, INFINITE);
  return 0;
}



