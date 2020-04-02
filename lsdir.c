#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// void printFolders(struct dirent *dir, DIR *dp);
// void openfolders(char *fileName)
// {
//     DIR *dp;
//     if ((dp = opendir(fileName)) == NULL || strcmp(fileName, "..") == 0)
//     {
//         /* code */
//         //printf("error openning folder %s\n", fileName);
//     }
//     else
//     {
//         printFolders(readdir(dp), dp);
//     }
// }
// void printFolders(struct dirent *dir, DIR *dp)
// {
//     if ((dir) != NULL)
//     {
//         // Skip removed files
//         if (dir->d_ino == 0)
//         {
//         }
//         else
//         {
//             char *fileName = dir->d_name;
//             printf("%s\n", fileName);
//             printFolders(readdir(dp), dp);
//             if (strcmp(fileName, "..") != 0)
//             {
//                 chdir(fileName);
//                 openfolders(fileName);
//             }
//         }
//     }
// }
int main(int argc, char *argv[])
{

    DIR *dp;
    struct dirent *dir;
    
    // if ((dp = opendir(".")) == NULL)
    // {
    //     fprintf(stderr, "cannot open directory.\n");
    //     exit(1);
    // }

    // // Read entries
    // while ((dir = readdir(dp)) != NULL)
    // {
    //     // Skip removed files
    //     if (dir->d_ino == 0)
    //     {
    //         continue;
    //     }

    //     printf("%s\n", dir->d_name);
    // }
    //openfolders(".");
  
    closedir(dp);

    return 0;
}