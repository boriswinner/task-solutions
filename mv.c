#include <stdio.h>
#include <malloc.h>
#include <io.h>
#include <stdbool.h>
#include <windows.h>
#include <shlwapi.h>
#include "Shlwapi.h"
#include <WinDef.h>
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

/*void MoveFileToDir(int* s1, int* s2){
    char fname[9];
    char dir[64];
    char drive[3];
    char ext[5];
    _splitpath(s1,drive, dir, fname, ext);
    char* s1_clear = malloc(SIZE*sizeof(char));
    int i = 0;
    for (; s2[i] != '\0'; ++i){
        s1_clear[i] = s2[i];
    }
    for (; fname[i] != '\0'; ++i){
        s1_clear[i] = fname[i];
    }
    s1_clear[i+1] = '.';
    for (;ext[i] != '\0'; ++i){
        s1_clear[i] = ext[i];
    }
    s1_clear[i+1] = '\0';

    rename(s1,s1_clear);
}*/

int main(int argc, char **argv) {
    char* s1 = malloc(SIZE* sizeof(char));
    char* s2 = malloc(SIZE* sizeof(char));
    gets(s1);
    //extract file name
    char *lpStr1;
    lpStr1 = s1;
    printf("%s",     PathFindFileName(lpStr1));

    gets(s2);
    char *lpStr2;
    lpStr1 = s2;
    printf("%s",     PathFindFileName(lpStr2));

    //if (DirectoryExists(s2)){
        return(MoveFile(s1,s2));
        //MoveFileToDir(s1,s2);
        //MoveFile(s1,s2);
        //return(rename(s1,fnmerge(s2,PathFindFileName(s1)));
        //return(rename(s1,PathFindFileName(s1)));
   // }
   /* if (FileExists(s1) && (!DirectoryExists(s2))){
        return(rename(s1,s2));
    }*/
    /*if (PathFileExistsA(s2) == 0){
        rename(s1,s2);
    }*/
    printf("Hello, World!\n");
    return 0;
}
