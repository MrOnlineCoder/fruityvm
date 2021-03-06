#include <stdio.h>
#include <conio.h>

#include "vm_instructions.h"
#include "vm.h"

int main() {
    printf("FruityVM by MrOnlineCoder \n");
    int testAll[] = {
		INT, 2,
		INT, 6,
		SPRINT,
		ISUM,
		SPRINT,
		SPOP,
		INT, 100,
		INT, 256,
		SPRINT,
		ISUB,
		SPRINT,
		SPOP,
		SPRINT,
		INT, 10,
		INT, 5,
		SPRINT,
		IMUL,
		SPRINT,
		SPOP,
		SPRINT,
		INT, 7,
		INT, 35,
		SPRINT,
		IDIV,
		SPRINT,
		SPOP,
		SPRINT,
		INT, 0,
		INT, 25,
		SPRINT,
		IDIV,
		SPRINT,
		JMP, 47,
		SPOP,
		INT, 989,
		SPOP,
		INT, 545,
		SPRINT,
		INT, 2,
        JMPEQ, 2, 58,
        SPRINT,
        SPRINT,
        SPRINT,
		PUTCHAR, 104,
		PUTCHAR, 105,
		HALT
	};

	int hello[] = {
        INT, 5,
        INT, 120,
        ISUM,
        SPRINT,
        JMPEQ, 125, 8,
        PUTSTR, 72, 69, 76, 76, 79, 33, 0,
        HALT
	};

	int inputTest[] = {
        PUTSTR, 73, 58, 0,
        READ,
        SPRINT,
        HALT
	};
	vm_load(inputTest, sizeof(inputTest), 32);
	vm_main();
    _getch();
    return 0;
}
