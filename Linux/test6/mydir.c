#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>


void  printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;

    if ((dp=opendir(dir)) == NULL)
    {
         fprintf(stderr, "cannot open directory:%s\n", dir);
         return;
    }

    chdir(dir);
    while ((entry=readdir(dp)) != NULL)
    {
        lstat(entry->d_name, &statbuf);
        if (S_ISDIR(statbuf.st_mode))
        {
           if (strcmp(".", entry->d_name) ==  0 || strcmp("..", entry->d_name) == 0)
              continue;
           printf("%*s%s\n", depth, "", entry->d_name);
           printdir(entry->d_name, depth+4);
        }
        else
           printf("%*s%s\n", depth, " ", entry->d_name);

    }

    chdir("..");
    closedir(dp);
    return;

}


int main(int argc, char *argv[])
{
    int i;
    if (argc == 1)
    {
        printf("Scan Current Directory:\n");
        printdir(".", 0);
    }
    else
    { 
        for (i=1; i <= argc; i++)   
        {
          printf("Scan Dirctory %s:\n", argv[i]);
          printdir(argv[i], 0);
        }
    }
    printf("done\n");
    return 0;
}
