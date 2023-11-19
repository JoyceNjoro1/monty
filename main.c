#include "monty.h"

#define MAX_LINE_LENGTH 1024

bus_t bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[]) {
    char content[MAX_LINE_LENGTH];
    FILE *file;
	size_t len;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;

    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(content, sizeof(content), file) != NULL) {
        bus.content = content;
        counter++;

	len = strlen(content);
        if (len > 0 && content[len - 1] == '\n') {
            content[len - 1] = '\0';
        }

        if (content[0] != '\0') {
            execute(content, &stack, counter, file);
        }
    }

    free_stack(stack);
    fclose(file);

    return 0;
}
