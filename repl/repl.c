#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define READ_BUFFER_SIZE 100

typedef struct {
    int buffer_size;
    int input_size;
    char *input;
} InputBuffer;

int read_input(InputBuffer *input_buffer);

int
main(int argc, char *argv[]) {
    int exit = 0;
    InputBuffer input_buffer;

    // Allocate input buffer and buffer to read user input
    input_buffer.input = malloc(READ_BUFFER_SIZE);

    while (!exit) {
        write(1,"$ ",2);
        exit = read_input(&input_buffer);

        if (exit) break;     

        new_process(input_buffer);
    }
}



int
read_input(InputBuffer *input_buffer) {

    input_buffer->input_size = read(0, input_buffer->input, READ_BUFFER_SIZE);

    if (input_buffer->input_size == -1) {
        return 1;
    }

    return 0;
}

void
new_process(InputBuffer *input_buffer) {
    
}
