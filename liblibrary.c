#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

int isdirectory(const char *path)
{
    struct stat stat1;
    stat(path, &stat1);
    return S_ISDIR(stat1.st_mode);
}

void directoryRemover(const char *folderpath)
{
    DIR *dir = opendir(folderpath);

    struct dirent *file;

    char path[1000];
    
    while((file = readdir(dir)) != NULL ){
        sprintf(path, "%s/%s", folderpath, file->d_name);

        if(strcmp(file->d_name, ".")!=0&&strcmp(file->d_name, "..")!=0)
        {
           if(isdirectory(path))
                directoryRemover(path);
           else
                remove(path);
        }
    }
    remove(folderpath);
    closedir(dir);
}
