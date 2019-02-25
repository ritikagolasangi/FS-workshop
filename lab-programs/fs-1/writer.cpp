// Program to implement Write side of the PIPE.

#include <iostream>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
 
int main(int argc, char* argv[])
{
    int fd;
 
    char buff[25];
 
    // FIFO file path
    char *myfifo = "myFifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);
    strcpy(buff,argv[1]);

    // Open FIFO for write only
    fd = open(myfifo, O_WRONLY);
 
    // Write the input string on the FIFO and close it
    write(fd, buff, strlen(buff)+1);
    cout<<"\n(1) Wrote \""<<buff<<"\" to FIFO file"<<endl;
    
    close(fd);
    
    return 0;
}
