//
// Created by Donsg on 29.04.2021.
//

#include <iostream>
#include <Windows.h>
#include <process.h>

#define M 20

HANDLE event1, event2;

DWORD WINAPI thread1_proc(LPVOID lpParam);
DWORD WINAPI thread2_proc(LPVOID lpParam);

int main()
{
  event1 = CreateEvent(NULL, true, false, "event1"); //L"event1"
  event2 = CreateEvent(NULL, true, false, "event2"); //L"event2"
  ResetEvent(event1);
  ResetEvent(event2);



  auto i1 = CreateThread(
      NULL,                   // default security attributes
      0,                      // use default stack size
      thread1_proc,       // thread function name
      NULL,          // argument to thread function
      0,                      // use default creation flags
      NULL);
  auto i2 = CreateThread(
      NULL,                   // default security attributes
      0,                      // use default stack size
      thread2_proc,       // thread function name
      NULL,          // argument to thread function
      0,                      // use default creation flags
      NULL);

  SetEvent(event1);

  WaitForSingleObject(i1, INFINITE);
  WaitForSingleObject(i2, INFINITE);

}

DWORD WINAPI thread1_proc(LPVOID lpParam){
  for (int i = 0; i < M; ++i) {
    while (WaitForSingleObject(event2, 1) != WAIT_OBJECT_0) {}
    ResetEvent(event2);
    std::cout << "1 ";
    SetEvent(event1);
  }
  return 0;
}

DWORD WINAPI thread2_proc(LPVOID lpParam) {
  for (int i = 0; i < M; ++i) {
    while (WaitForSingleObject(event1, 1) != WAIT_OBJECT_0) {}
    ResetEvent(event1);
    std::cout << "2 ";
    SetEvent(event2);
  }
  return 0;
}