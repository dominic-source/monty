# Installation

**type:** gcc -Wall -Werror -Wextra -pedantic *.c -o monty

**Usage:** ./monty filename

+ The File should contain the Operators
+ A line can only contain one operator

# Monty Language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

# Task
The goal of this project is to create an interpreter for Monty ByteCodes files

**Task 0** - Implement the push and pall opcodes

**Task 1** - Implement the pint opcode

**Task 2** - Implement the pop opcode

**Task 3** - Implement the swap opcode

**Task 4** - Implement the add opcode

**Task 5** - Implement the nop opcode

# Guide

**Operators Instruction**

op_push - pushes the value of the push argument to the stack
:sunglasses: **usage**: push 123

op_pall - this will print everything on the stack following the LIFO principle
:sunglasses: **usage**: pall

op_pint - pint will print the top value of the stack
:sunglasses: **usage**: pint

op_add - the top two element of the stack will be added when this command is used
:sunglasses: **usage**: add

op_sub - subtract the top two element of the stack
:sunglasses: **usage**: sub

op_swap - the two element of the stack will be swapped
:sunglasses: **usage**: swap

op_pop - remove the top element of the stack
:sunglasses: **usage**: pop

op_nop - do no changes on the stack
:sunglasses: **usage**: nop

op_div - the top two element of the stack will be divided
:sunglasses: **usage**: div

op_mul - multiplies the top two element of the stack
:sunglasses: **usage**: mul

op_mod - calculate the modulo of the top two element of the stack
:sunglasses: **usage**: mod

op_pchar - prints the value at the top of the stack in the form of ascii character, followed by a newline
:sunglasses: **usage**: pchar

op_pstr - prints the values from the top of the stack but display it in ascii character, followed by a new line.
:sunglasses: **usage**: pstr

op_rotl - make the first element of the stack to become the last element.
:sunglasses: **usage**: rotl

op_rotr - make the last element of the stack become the first element of the stack.
:sunglasses: **usage**: rotr
