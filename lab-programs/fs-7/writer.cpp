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
 
    fstream fp;

    fp.open("list3.txt", ios::out | ios::app);
    if(!fp){
	cout<<"Unable to open.\n";
    }

    fp<<argv[1]<<"\n";
    fp.close();
    
    return 0;
}
