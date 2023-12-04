#include <iostream>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
    int txtFileCount = 0;
    DIR *d;
    struct dirent *dir;
    struct stat fileStat;
    d = opendir(".");

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (strstr(dir->d_name, ".txt") != NULL)
            {
                if (stat(dir->d_name, &fileStat) == 0)
                {
                    if (S_ISREG(fileStat.st_mode))
                    {
                        txtFileCount++;
                    }
                }
            }
        }
        closedir(d);
    }

    // Print the result
    if (txtFileCount == 0)
    {
        std::cout << "No text files found in the current directory." << std::endl;
    }
    else
    {
        std::cout << "Found " << txtFileCount << " text file(s) in the current directory." << std::endl;
    }

    return 0;
}
