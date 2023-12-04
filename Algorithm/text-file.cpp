#include <iostream>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <fstream>

using namespace std;

int Checking_For_Text_Files()
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

    // Print the number of text files found
    if (txtFileCount == 0)
    {
        cout << "No text files found in the current directory." << endl;
    }
    else
    {
        cout << "Found " << txtFileCount << " text file(s) in the current directory." << endl
             << endl;
    }

    // Open the directory again to read the files
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
                        ifstream file(dir->d_name);
                        if (file.is_open())
                        {
                            cout << "Contents of " << dir->d_name << ":\n";
                            string line;
                            while (getline(file, line))
                            {
                                cout << line << '\n';
                            }
                            file.close();
                        }
                        else
                        {
                            cout << "Unable to open file " << dir->d_name << endl;
                        }
                    }
                }
            }
        }
        closedir(d);
    }

    return 0;
}
