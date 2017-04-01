#include <stdio.h>
#include <stdlib.h>

// (Can be compiled with tcc)

int main(int argc, char ** argv) {
	if (argc == 1) {
		printf("A tiny utility to retrieve bits from cpuid.\n");
		printf("Usage: cpuinfo outreg bit initEax [initEcx]\n");
		printf("outreg  register to retrieve bit from (eax=0, ebx=1, ecx=2, edx=3)\n");
		printf("bit     bit to retrieve from output register\n");
		printf("initEax initial value for eax\n");
		printf("initEcx initial value for ecx (default 0)\n");
		return 1;
	}

	unsigned regs[4];

	regs[0] = atoi(argv[3]);
	regs[2] = argc == 5 ? atoi(argv[4]) : 0;

	asm volatile("cpuid"
		: "=a" (regs[0]),
		  "=b" (regs[1]),
		  "=c" (regs[2]),
		  "=d" (regs[3])
		: "0" (regs[0]), "2" (regs[2]));

	unsigned reg = atoi(argv[1]);
	unsigned bit = atoi(argv[2]);
	printf("%d", (regs[reg] & (1<<bit)) != 0);
	return 0;
}
