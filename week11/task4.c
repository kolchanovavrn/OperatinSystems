#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>

int main(){

    char *src, *dst;
    size_t fs;

    int source = open("task1.txt", O_RDONLY);
    int destination = open("task1.memcopy.txt", O_RDWR);

    fs = lseek(source, 0, SEEK_END);
    src = mmap(NULL, fs, PROT_READ, MAP_PRIVATE, source, 0);

    ftruncate(destination, fs);

    dst = mmap(NULL, fs, PROT_READ | PROT_WRITE, MAP_SHARED, destination, 0);

    memcpy(dst, src, fs);
    munmap(dst, fs);

    close(source);
    close(destination);

    return 0;
}
