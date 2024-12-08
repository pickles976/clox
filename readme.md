My implementation of the Lox programming language from https://craftinginterpreters.com/

https://www.lua.org/doc/jucs05.pdf

https://journal.stuffwithstuff.com/2011/03/19/pratt-parsers-expression-parsing-made-easy/

gcc -o clox.exe main.c chunk.c memory.c debug.c value.c vm.c compiler.c scanner.c

- [x] 14 - Chunks of Bytecode
- [x] 15 - A Virtual Machine
- [x] 16 - Scanning on Demand
- [x] 17 - Compiling Expressions
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

Challenges:
- implement `reallocate` without `realloc`
- make stack height dynamic