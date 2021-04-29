//
// Created by Donsg on 29.04.2021.
//

#include "windows.h"
#include "iostream"
#include "process.h"

#define N_THREAD 2
#define M 10

int counter = 0;

typedef struct MyData {
  int id;
  HANDLE* mutex;
} MYDATA, * PMYDATA;

DWORD WINAPI thread1_fun(LPVOID lpParam);

int main(){
  HANDLE mutex = CreateMutexA(NULL, FALSE, NULL);
  HANDLE  hThreadArray[N_THREAD];
  PMYDATA pDataArray[N_THREAD];


  for (int i = 0; i < N_THREAD; ++i) {
    pDataArray[i] = (PMYDATA)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY,
                                       sizeof(MYDATA));
    pDataArray[i]->id = i + 1;
    pDataArray[i]->mutex = &mutex;
    hThreadArray[i] = CreateThread(
        NULL,                   // default security attributes
        0,                      // use default stack size
        thread1_fun,       // thread function name
        pDataArray[i],          // argument to thread function
        CREATE_SUSPENDED, NULL);
  }
  for (int i = 0; i < N_THREAD; ++i) {
    ResumeThread(hThreadArray[i]);
  }


  WaitForMultipleObjects(N_THREAD, hThreadArray, TRUE, INFINITE);
  CloseHandle(mutex);
  for(int i=0; i<N_THREAD; i++)
  {
    CloseHandle(hThreadArray[i]);
    if(pDataArray[i] != NULL)
    {
      HeapFree(GetProcessHeap(), 0, pDataArray[i]);
      pDataArray[i] = NULL;    // Ensure address is not reused.
    }
  }
}

DWORD WINAPI thread1_fun(LPVOID lpParam){
  PMYDATA pDataArray;
  pDataArray = (PMYDATA)lpParam;
  HANDLE* mutex = pDataArray->mutex;
  int id = pDataArray->id;
  for(int i = 0; i < M; ++i){
    WaitForSingleObject(*mutex, INFINITE);
    counter += id;
    std::cout << counter << '\n';
    ReleaseMutex(*mutex);
  }
  return 0;
}