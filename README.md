# NotBinary-Interpreter
An interpreter for an esolang I made in the first two days of learning C++.
Written in C++11.

# What is NotBinary?
Very simple. It looks like binary, smells like binary, but it is not binary.

# How NotBinary Works
The esolang uses a stack and a variable for memory.
The code consists of 1s and 0s. Other characters are allowed, but the interpreter will automatically remove them when run.

Commands:
Stack commands manipulate the stack. Each stack command starts with ``111``.
|Command|Description|
|---|---|
|111|Pushes 0 to the stack|
|011|Pops the top value out of the stack and outputs it as an ASCII character|
|110|Outputs the top value as an ASCII character|
|010|Shifts the stack|
|101|Squares the top value of the stack|
|100|Increments top value|
|001|Decrements top value|
