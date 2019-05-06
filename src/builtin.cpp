#include <unistd.h>
#include <stdio.h>
#include <limits.h>

string currentDir()
{
	char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) 
   {
       string str(cwd);
       // cout<<"The string is "<<str<<endl;
       return str;
   }
    else 
    {
       perror("getcwd() error");
       // return 1;
   	}
}