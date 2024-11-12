#include "common.h"
#include "vm.h"
#include "debug.h"
#include "compiler.h"
#include <stdio.h>

VM vm;

static void resetStack() {
    vm.stackTop = vm.stack; // sets the stack ptr equal to the start of the stack
}

static InterpretResult run() {
    #define READ_BYTE() (*vm.ip++) 
    #define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
    // do-while loop is used to wrap our operations in a scope
    #define BINARY_OP(op) \
        do { \
            double a = pop(); \
            double b = pop(); \
            push(a op b); \
        } while(false) 

    for (;;) {

        #ifdef DEBUG_TRACE_EXECUTION
            // Print the stack state
            printf("          ");
            for (Value* slot = vm.stack; slot < vm.stackTop; slot++) {
                printf("[ ");
                printValue(*slot);
                printf(" ]");
            }
            printf("\n");

            // Print the current instruction
            // array offset = ip - array start
            disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
        #endif

        // dispatch
        uint8_t instruction;
        switch (instruction = READ_BYTE()) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                push(constant);
                break;
            }
            case OP_ADD: BINARY_OP(+); break;
            case OP_SUBTRACT: BINARY_OP(-); break;
            case OP_MULTIPLY: BINARY_OP(*); break;
            case OP_DIVIDE: BINARY_OP(/); break;
            case OP_NEGATE: push(-pop()); break;
            case OP_RETURN: {
                printValue(pop());
                printf("\n");
                return INTERPRET_OK;
            }
        }
    }
    #undef READ_BYTE
    #undef READ_CONSTANT
    #undef BINARY_OP

}

void initVM() {
    resetStack();
}

void freeVM() {

}

void push(Value value) {
    *vm.stackTop = value;
    vm.stackTop++;
}

Value pop() {
    vm.stackTop--; // decrement stackTop
    return *vm.stackTop; // Return value pointed to by stackTop
}

InterpretResult interpret(const char* source) {
    compile(source);
    return INTERPRET_OK;
}