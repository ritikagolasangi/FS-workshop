// Program to implement read side of the FIFO

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;
 
char rstr[25];

void reverse(int l, char s[])
{
    int j, i;
    
    for(j=l-1, i=0; j>=0; j--, i++){
		rstr[i]=s[j];
    }
} 

int main(int argc, char* argv[])
{
    int fd, len, j, mode;
 
    char str[25];
 
    // FIFO file path
    char *myfifo = "myFifo";
     
    // Creating the named file(FIFO)
    // mkfifo(<pathname>,<permission>)
    mkfifo(myfifo, 0666);

    // Open in read only mode and perform the read operation
    fd = open(myfifo, O_RDONLY);
    read(fd, str, 25);
    cout<<"\n(2) Read \""<<str<<"\" from FIFO file"<<endl;

    len = strlen(str);

    reverse(len,str);
    
    if(strcmp(argv[1], "stdout") == 0){
    	cout<<"\n(3) Reversed Name is: "<<rstr<<endl;
    }
    else{
    	// Open the output file in append mode    
   		fstream f;
   		f.open(argv[1], fstream::app|fstream::out);
    	
    	f<<rstr<<endl;
    	cout<<"\n(3) Wrote \""<<rstr<<"\" to "<<argv[1]<<" file"<<endl;
    	
    	f.close();
    }
    
    close(fd);
    //f.close();

    return 0;
}

