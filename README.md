# FruityVM

This is simple stack virtual machine written in C. 
Available instructions:

**HALT** - halts the machine

**INT X** - pushes the X number to stack

**ISUM** - pops two last numbers from the stack, adds them and pushes the result to stack. Same for ISUB (-), IMUL(*), IDIV(/)

**SPRINT** - prints the stack contents

**SPOP** - pops the item from stack

**JMP X** - jumps to X operand

**PUTCHAR X** - prints the X char (ASCII)

**JMPEQ XX YY** - jumps to YY operand if top stack item equals XX

**PUTSTR XXX...** - prints the XXX string of characters until facing 0 (null) character

**READ** - reads an int from input and pushes it onto the stack