#include "vm.h"
#include "vm_instructions.h"

#include <stdio.h>

int code[];
int codeLength;

int ip;
int ic;


int MAXSIZE = 256;
int stack[256];
int top = -1;

int stack_isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

int stack_isfull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int stack_peek() {
   return stack[top];
}

int stack_pop() {
   int data;

   if(!stack_isempty()) {
      data = stack[top];
      top = top - 1;
      return data;
   } else {
      printf("VM error: cannot pop from empty stack\n");
   }
}

int stack_push(int data) {

   if(!stack_isfull()) {
      top = top + 1;
      stack[top] = data;
   } else {
      printf("VM error: cannot push to full stack\n");
   }
}

void vm_isum() {
	 int a = stack_pop();
	 int b = stack_pop();
	 stack_push(a+b);
}

void vm_isub() {
	 int a = stack_pop();
	 int b = stack_pop();
	 stack_push(a-b);
}

void vm_imul() {
	 int a = stack_pop();
	 int b = stack_pop();
	 stack_push(a*b);
}

void vm_idiv() {
	 int a = stack_pop();
	 int b = stack_pop();
	 if (b == 0) {
	 	printf("VM error: cannot divide by 0 \n");
	  return;
	 }
	 stack_push(a/b);
}

void vm_jump() {
	ip++;
	int addr = code[ip];
	printf("VM: jumping to $%i  \n", addr);
	ip = addr;
}

void vm_putstr() {
    ip++;
    int charcode = code[ip];
    while (charcode != 0 && ip < codeLength) {
        printf("%c", charcode);
        ip++;
        charcode = code[ip];
    }
}

void vm_jumpeq() {
	ip++;
	int val = code[ip];
    ip++;
    int addr = code[ip];
    if (stack_pop() == val) {
        ip = addr;
        printf("VM: jumping to $%i (EQUAL) \n", addr);
    }
}

void vm_load(int ucode[], int size, int memSize) {
    codeLength = size / sizeof(int);
    for(size_t i=0;i<codeLength;i++) {
      code[i] = ucode[i];
    }
  printf("VM: loaded code of %i bytes (%i operands) \n", size, codeLength);

}

void vm_main() {
	printf("VM: starting CPU... \n");
	printf("VM: executing bytecode (%i length): \n", codeLength);

	for (int i=0; i<codeLength; i++) {
		printf("%i ", code[i]);
	}


	printf("\n");

	ip = 0; //Instruction pointer
    ic = code[ip]; // Instruction code
	while (ic != HALT && ip < codeLength) {
		switch(ic) {
			case INT:
			   ip++;
			   int val = code[ip];
			   printf("VM: adding INT(%i) to stack \n", val);
			   stack_push(val);
			   break;
			 case SPRINT:
			   printf("VM: stack= [ ");
			   for (int i = 0; i < top+1; i++) {
			   	 printf("%i ", stack[i]);
			   }
			   printf("] \n");
			   break;
			 case ISUM:
			   vm_isum();
			   break;
			 case ISUB:
			   vm_isub();
			   break;
			 case SPOP:
			   printf("VM: stack pop \n");
			   stack_pop();
			   break;
			 case IMUL:
			   vm_imul();
			   break;
			 case IDIV:
			   vm_idiv();
			   break;
			 case JMP:
			   vm_jump();
			   break;
			 case PUTCHAR:
			   ip++;
			   char c = code[ip];
			   printf("%c", c);
			   break;
             case JMPEQ:
                vm_jumpeq();
                break;
             case PUTSTR:
                vm_putstr();
                break;
             default:
                printf("VM: unknown instruction: %i \n", ic);
		}
		ip++;
		ic = code[ip];
	}
	printf("\nVM: halting..");
}
