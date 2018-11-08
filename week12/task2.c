#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

const size_t BUFFER_SIZE = 1<<5;

int main(int argc, char ** argv){
    char * buf = malloc(BUFFER_SIZE);
    char * mode = "w";
    size_t bytes_read;

    if (strcmp(argv[1], "-a") == 0){
        mode = "a";
        for (int i = 1; i < argc - 1 ; ++i)
            argv[i] = argv[i+1];
        argc--;
    }

    FILE ** outputs = malloc(argc * sizeof(FILE *));
    outputs[0] = stdout;

    for (int i = 1; i < argc; ++i)
        outputs[i] = fopen(argv[i], mode);

    while( (bytes_read = fread(buf, 1, BUFFER_SIZE, stdin)))
        for (int i = 0; i < argc; ++i)
            for (int j = 0; j< bytes_read; ++j)
                if (buf[j] != '\0')
                    fprintf(outputs[i], "%c", buf[j]);
    for (int i = 1; i < argc; ++i)
        fclose(outputs[i]);
    return 0;
}
