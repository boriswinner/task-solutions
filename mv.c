#include <stdio.h>
#include <malloc.h>
#include <io.h>
#include <stdbool.h>
#include <windows.h>
#include <shlwapi.h>
#include "Shlwapi.h"
#include <WinDef.h>
#include <unistd.h>

#define SIZE 255

//gcc -o test test.c -lshlwapi

int moveFileFolderToFileFolder(int argc, char** argv, int s, int d, bool force, bool interactive){
    int res = 0;
    if (force){
        res = MoveFileEx(argv[s],argv[d],MOVEFILE_REPLACE_EXISTING);
    }else if (interactive){
        printf("replace file %s with file %s ?[y/n] \n",argv[d],argv[s]);
        char treplace; scanf("%c",&treplace);
        if (treplace == 'y'){
            res = MoveFileEx(argv[s],argv[d],MOVEFILE_REPLACE_EXISTING);
        } else{
            printf("didn't replace file %s with file %s \n",argv[d],argv[s]);
            return 0;
        }
    } else{
        res = MoveFile(argv[s],argv[d]);
    }
    (res ? printf("Success! \n") : printf ("Error: can't move file or folder #%d to  destination #%d\n",s,d));
}

int moveFileToFolder(int argc, char** argv, int s, int d, bool force, bool interactive){
    int resRename = 0, resAppend = 1;
    char dest [SIZE]; strcpy(dest, argv[d]);
    char* t = PathFindFileName(argv[s]);
    resAppend = PathAppend(dest,t);
    if (force){
        resRename = MoveFileEx(argv[s],dest,MOVEFILE_REPLACE_EXISTING);
    } else if (interactive){
        printf("replace file %s with file %s ?[y/n] \n",dest,argv[s]);
        char treplace; scanf("%c",&treplace);
        if (treplace == 'y'){
            resRename = MoveFileEx(argv[s],dest,MOVEFILE_REPLACE_EXISTING);
        } else{
            printf("didn't replace file %s with file %s \n",dest,argv[s]);
        }
    } else{
        resRename = MoveFile(argv[s],dest);
    }
    if (!(resAppend)){
        printf("Error: can't append path at file or directory #%d \n",s);
    } else if  (!resRename){
        printf("Error: can't move file or directory #%d to destination $%d \n",s,d);
    } else{
        printf("Success! \n");
    }
}

int main(int argc, char **argv) {
    bool force = 0, interactive = 0;
    int fileargs = 0;
    for (int i = 1; i < argc; ++i){
        if (argv[i][0] == '-'){
            if (argv[i][1] == 'f'){
                force = 1;
            } else if (argv[i][1] == 'i'){
                interactive = 1;
            }
        } else {
            fileargs++;
        }
    }
    for (int i = 1; i < fileargs; ++i){
        if(!(PathFileExists(argv[i]))){
            printf("Error: file or directory #%d doesn't exist", i);
            return -1;
        }
    }

    if (argc == 2){
        printf("Error: destination is not provided");
        return -1;
    } else if (PathIsDirectory(argv[fileargs])){
        for (int i = 1; i < fileargs; ++i){
            if (PathIsDirectory(argv[i])){
                moveFileFolderToFileFolder(argc, argv, i, argc-1,force,interactive);
            } else{
                moveFileToFolder(argc, argv, i, argc-1,force,interactive);
            }
        }
    } else if (fileargs == 2){
        moveFileFolderToFileFolder(argc,argv,1,2,force,interactive);
    } else{
        printf("Error \n");
    }
    return 0;
}
