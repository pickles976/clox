#include <stdio.h>
#include "value.h"
#include "common.h"
#include "debug.h"
#include "vm.h"

VM vm;

static void resetStack() {
    vm.stackTop = vm.stack;
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
    vm.stackTop--;
    return *vm.stackTop;
}

static InterpretResult run() {
    #define READ_BYTE() (*vm.ip++) // increment the ptr
    #define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()]) // increment ptr and read from that index of values array

    for (;;) {

        #ifdef DEBUG_TRACE_EXECUTION
            printf("         ");
            for (Value* slot = vm.stack; slot < vm.stackTop; slot++) { // print stack from bottom to top
                printf("[ ");
                printValue(*slot);
                printf(" ]");
            }
            printf("\n");
            disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code)); // ptr2 - ptr1 = offset
        #endif

        uint8_t instruction;

        // Dispatch
        // To read: "direct threaded code", "jump table", and "computed goto"
        switch (instruction = READ_BYTE()) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                push(constant);
                break;
            }
            case OP_RETURN: {
                printValue(pop());
                printf("\n");
                return INTERPRET_OK;
            }
        }
    }

    #undef READ_BYTE
    #undef READ_CONSTANT
}

InterpretResult interpret(Chunk* chunk) {
    vm.chunk = chunk;
    vm.ip = vm.chunk->code;
    return run();
}