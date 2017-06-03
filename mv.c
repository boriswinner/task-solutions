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

bool FileExists(const char *fname)
{
    return(access(fname, 0) != -1);
}

BOOL DirectoryExists(LPCTSTR szPath)
{
    DWORD dwAttrib = GetFileAttributes(szPath);
    return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
            (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

int main(int argc, char **argv) {

    for (int i = 1; i < argc - 1; ++i){
        if (!PathFileExists(argv[i])){
            printf("error: file or directory doesn't exist");
            sleep(3);
            return -1;
        }
    }

    if (PathIsDirectory(argv[argc - 1])){
        for (int i = 1; i < argc - 1; ++i){
            char d [SIZE]; strcpy(d, argv[argc-1]);
            char* t = PathFindFileName(argv[i]);
            PathAppend(d,t);
            rename(argv[i],d);
        }
    } else if (argc == 3){
        int a = rename(argv[1],argv[2]);
        (a ? printf ("error") : printf("success!"));
        sleep(3);
    }

    /*if (DirectoryExists(s2)){
    //    return(MoveFile(s1,s2));
        //MoveFileToDir(s1,s2);
        //MoveFile(s1,s2);
        //return(rename(s1,fnmerge(s2,PathFindFileName(s1)));
        //return(rename(s1,PathFindFileName(s1)));
    }
    if (FileExists(s1) && (!DirectoryExists(s2))){
        return(rename(s1,s2));
    }
    /*if (PathFileExistsA(s2) == 0){
        rename(s1,s2);
    }*/
    return 0;
}
