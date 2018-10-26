#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main(){
    
    FILE *fp;
    fp = fopen("ex4.txt", "w");

    DIR* dirp = opendir("tmp");
    
    char path[50];
    struct dirent* dirEntry;
    struct stat buffer; 
    
    int amount_of_files = 0;
    int index = 0;

    while ( (dirEntry = readdir(dirp)) != NULL){
        strcpy(path, "tmp/");
        strcat(path, dirEntry->d_name); //constructing a path - tmp/name_of_entry
        stat(path,&buffer);

        if (buffer.st_nlink >=2){
            amount_of_files++;
        }
    }    
    
    struct stat files[amount_of_files];
    struct dirent dfiles[amount_of_files];

    dirp = opendir("tmp");

    while ( (dirEntry = readdir(dirp)) !=NULL ) {     
        strcpy(path, "/tmp");
        strcat(path, dirEntry->d_name);
        stat(path,&buffer);
        if (buffer.st_nlink >= 2){
            files[index] = buffer;
            dfiles[index] = *dirEntry;
            index++;
        }
    }
    
    int delta = 0;
    int inode_num = 0;
    int curr = 0;
    int temp = 0;

    for (int i = 0; i<amount_of_files; i++){
        inode_num = files[i].st_ino;
        delta = amount_of_files - i -1;
        for (int j = 1; j < delta; j++){

            curr = files[i+j].st_ino;
            
            if (curr = 0) continue;
            fprintf(fp, "%s", curr);
            
            if (inode_num == temp){
                fprintf(fp, "%s", dfiles[i+j].d_name);
            }
            
            files[i+j].st_ino = 0;           
        }
        fprintf(fp, "%s", "\n");
    }

    fclose(fp);
    return 0;
}
