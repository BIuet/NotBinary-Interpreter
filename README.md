# NotBinary-Interpreter
An interpreter for an esolang I made in the first two days of learning C++.
<br>
Written in C++11.

# What is NotBinary?
Very simple. It looks like binary, smells like binary, but it is not binary.

# How NotBinary Works
The esolang uses a stack and a variable for memory.
<br>
The code consists of 1s and 0s. Other characters are allowed, but the interpreter will automatically remove them when run.

Commands:
Stack commands manipulate the stack. Each stack command has an identifier of ``111``.
<br>
A stack command: ``111 011`` (pops first value and outputs it)
<br>
|Command|Description|
|---|---|
|111|Pushes 0 to the stack|
|011|Pops the top value out of the stack and outputs it as an ASCII character|
|110|Outputs the top value as an ASCII character|
|010|Shifts the stack|
|101|Squares the top value of the stack|
|100|Increments top value|
|001|Decrements top value|

<br>
Variable commands manipulate the one variable. Each variable command has an identifier of ``000``.
<br>

|Command|Description|
|---|---|
|110|Mirror command: sets the variable value to the top value in the stack|
|011|Pushes a copy of variable's value into the stack|
|111|Input and stores it in the variable|

<br>
Other commands (they do not require identifiers and thus will appear alone):
<br>

|Command|Description|
|---|---|
|110|Addition: pops a, b and push a + b|
|011|Subtraction: pops a, b and push a - b|
|100|Start of loop|
|001|If top value is 0, proceed, else, goes back to start of loop, if there's any|
|101|Start of code block. If value is 0, execute code block, else, skip it|
|010|End of code block|

# Resources
For basic concept of Interpreter: https://www.programiz.com/article/difference-compiler-interpreter
<br>
A basic concept of Lexer by zeroFruit: https://medium.com/de-labtory/create-new-smartcontract-language-with-go-lexer-part-a5cdfca9b42e
