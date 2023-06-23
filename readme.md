My implementation of the Lox programming language from https://craftinginterpreters.com/

https://craftinginterpreters.com/scanning-on-demand.html
https://www.lua.org/doc/jucs05.pdf

gcc -o clox main.c chunk.c memory.c debug.c vm.c value.c compiler.c scanner.c

- [x] 14 - Chunks of Bytecode
- [x] 15 - A Virtual Machine
    - [x] 15.1
    - [x] 15.2
    - [x] 15.3
- [x] 16 - Scanning on Demand
    - [x] 16.1
    - [x] 16.2
- [ ] 17 - Compiling Expressions
    - [x] 17.3
    - [ ] 17.4
    - [ ] 17.5
    - [ ] 17.6
    - [ ] 17.7
- [ ] 18 - Types of Values
- [ ] 19 - Strings
- [ ] 20 - Hash Tables
- [ ] 21 - Global Variables
- [ ] 22 - Local Variables
- [ ] 23 - Jumping Back and Forth
- [ ] 24 - Calls and Functions
- [ ] 25 - Closures
- [ ] 26 - Garbage Collection
- [ ] 27 - Classes and Instances
- [ ] 28 - Methods and Initializers
- [ ] 29 - Superclasses
- [ ] 30 - Optimization