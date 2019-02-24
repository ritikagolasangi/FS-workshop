// Program to implement Write side.

#include <iostream>
#include <fstream>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
 
int main(int argc, char* argv[])
{
    int len, i;
 
    char buff[45];
 
    fstream fp;

    fp.open("student.txt", ios::out | ios::app);
    if(!fp){
		cout<<"Unable to open.\n";
    }

    strcpy(buff, argv[1]);
    strcat(buff, "|");
    strcat(buff, argv[2]);
    strcat(buff, "|");
    strcat(buff, argv[3]);
    strcat(buff, "|");
    strcat(buff, argv[4]);
    strcat(buff, "|");
    strcat(buff, argv[5]);

    len = strlen(buff);
    
    for(i=0; i<45-len; i++){
		strcat(buff, "#");
    }

    strcat(buff, "\n");
    
    fp<<buff;
    
    fp.close();
    
    return 0;
}
