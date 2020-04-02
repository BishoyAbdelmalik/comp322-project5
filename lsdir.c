#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void openfolders(char *fileName)
{
    chdir(fileName);
    DIR *dp;
    struct dirent *dir;

    if ((dp = opendir(".")) == NULL)
    {
        printf("error openning folder %s\n", fileName);
    }

    while ((dir = readdir(dp)) != NULL)
    {
        char *fileName = dir->d_name;
        if (dir->d_ino == 0 || strcmp(fileName, ".") == 0 || strcmp(fileName, "..") == 0)
        {
            continue;
        }

        if (dir->d_type & DT_DIR)
        {

            printf("%s\n", fileName);

            openfolders(fileName);
            chdir("..");
        }
    }
}

int main(int argc, char *argv[])
{

    char *fileName;

    if (argc < 2)
    {
        /* code */
        fileName = ".";
    }
    else if (argc == 2)
    {
        fileName = argv[1];
    }
    else
    {
        printf("lsdir: too many files.\n");
        exit(1);
    }

    openfolders(fileName);

    return 0;
}