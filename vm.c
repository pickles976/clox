#include <stdio.h>
#include "value.h"
#include "common.h"
#include "debug.h"
#include "vm.h"

VM vm;

void initVM() {

}

void freeVM() {

}

static InterpretResult run() {
    #define READ_BYTE() (*vm.ip++) // increment the ptr
    #define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()]) // increment ptr and read from that index of values array

    for (;;) {

        #ifdef DEBUG_TRACE_EXECUTION
            disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code)); // ptr2 - ptr1 = offset
        #endif

        uint8_t instruction;

        // Dispatch
        // To read: "direct threaded code", "jump table", and "computed goto"
        switch (instruction = READ_BYTE()) {
            case OP_CONSTANT: {
                Value constant = READ_CONSTANT();
                printValue(constant);
                printf("\n");
                break;
            }
            case OP_RETURN: {
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