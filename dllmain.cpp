#include <Windows.h>
#include <iosteam>
#define rebase(x) (x - 0x400000 + (DWORD)GetModuleHandleA(0))
void printsploit()
{
      typedef int(__cdecl* print_t)(int, const char*, ...);
	    print_t r_print = (print_t)rebase(0x0172CFD0); // print address for version-1088f3c8e4a44cc7 7/5/2024
      while(true)
      {
            r_print(0, "Hello from printsploit!");
            Sleep(2000)
            r_print(1, "Hello from printsploit!");
            Sleep(2000)
            r_print(2, "Hello from printsploit!");
            Sleep(2000)
            r_print(3, "Hello from printsploit!");
      }
}

int __stdcall DllMain(
	const HMODULE instance,
	const std::uintptr_t reason,
	const void* reserved
)
{
      if(reason == 1)
      {
            printsploit();
      }
}
