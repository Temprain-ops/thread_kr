//
// Created by Donsg on 29.04.2021.
//

#include <iostream>
#include <Windows.h>
#include <process.h>

#define M 30

typedef struct MyData {
  HANDLE* mutex1;
  HANDLE* mutex2;
} MYDATA, * PMYDATA;

int counter = 0;
DWORD WINAPI thread_fun(LPVOID lpParam);

int main(){
  HANDLE mutex1, mutex2;
  PMYDATA pData1;
  mutex1 = CreateMutexA(NULL, TRUE, NULL);
  mutex2 = CreateMutexA(NULL, FALSE, NULL);
  pData1  = (PMYDATA)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
                             sizeof(MYDATA));
  pData1->mutex1 = &mutex1;
  pData1->mutex2 = &mutex2;

  auto th1 = CreateThread(
      NULL,                   // default security attributes
      0,                      // use default stack size
      thread_fun,       // thread function name
      pData1,          // argument to thread function
      NULL, NULL);
  auto th2 = CreateThread(
      NULL,                   // default security attributes
      0,                      // use default stack size
      thread_fun,       // thread function name
      pData1,          // argument to thread function
      NULL, NULL);


  ReleaseMutex(mutex1);

  WaitForSingleObject(th1, INFINITE);
  WaitForSingleObject(th2, INFINITE);

  std::cout << "Counter: " << counter << "\n";

  CloseHandle(mutex1);
  CloseHandle(mutex2);
}

DWORD WINAPI thread_fun(LPVOID lpParam){
  PMYDATA pDataArray;
  pDataArray = (PMYDATA)lpParam;
  HANDLE* mutex1 = pDataArray->mutex1;
  HANDLE* mutex2 = pDataArray->mutex2;

  for(int i = 0; i < M; ++i) {
    WaitForSingleObject(*mutex1, INFINITE);
    std::cout << "1\n";
    WaitForSingleObject(*mutex2, INFINITE);
    std::cout << "2\n";
    ++counter;
    ReleaseMutex(*mutex1);
    ReleaseMutex(*mutex2);
  }

  return 0;
}