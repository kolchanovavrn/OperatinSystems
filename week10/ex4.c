#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    
    DIR *dirp = opendir("./tmp");
    struct dirent *dp;
    struct stat  *buffer = malloc(sizeof(struct stat)); 
    
    int amount_of_files = 0;
    int index = 0;

    while ( (dp = readdir(dirp)) != NULL){
        stat(dp.d_name,buffer);
        if (*(buffer).st_nlink >=2){
            amount_of_files++;
        }
    }    
    
    struct stat files[amount_of_files];
    struct dirent dfiles[amount_of_files];

    dirp = opendir("./tmp");
    while ( (dp = readdir(dirp)) !=NULL ) {
        //идем по файлам в папке
       
        stat(dp,buffer);
        if (buffer->st_nlink >= 2){
            files[index] = *buffer;
            dfiles[index] = *dp;
            index++;
        }
    }

    for (int i = 0; i<amount_of_files; i++){
        inode_num = files[i].st_ino;
        delta = amount_of_files - i -1;
        for (int j = 1; j < delta; j++){
            
            curr = files[i+j].st_ino;
            
            if (curr = 0) continue;
            print(curr);
            if (inode_num == temp){
                printf(dfiles[i+j]->d_name);
            }
              
            
            files[i_j].st_ino = 0;
            //jnode_num = files[j].st_ino;
            


        }
    
    }

    return 0;
}
