/******************************************************************************************************************
Write a C++ program to read series of names, one per line, from standard input and write these names spelled in reverse order to the standard output using I/O redirection and pipes. Repeat the exercise using an input file specified by the user instead of the standard input and using an output file specified by the user instead of the standard output.
*******************************************************************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>

using namespace std;

// Input and output file streams.
fstream f1, f2;

// Input and output buffers.
char fname1[25], fname2[25];	

// spawn a process that will write to the named pipe.
void spawnWriter(const char str[]){

	if(fork() == 0)
		execlp("./writer", "writer", str, NULL); 
		
}

// spawn a process that will read from the named pipe.
void spawnReader(char* fout){

	if(fork() == 0)
		execlp("./reader","reader", fout, NULL); 
		
}

int main(void){

	char name[25];
	int choice, n, i, j, len=0;

	cout<<"1. Console I/O \n2. File I/O \n";
	cout<<"Enter your choice:\n";
	cin>>choice;

	switch(choice){

		case 1:
			cout<<"Enter the number of students: \n";
			cin>>n;
				
			for(i=1; i<=n; i++){
			
				cout<<"Enter "<< i <<" student name: \n";
				cin>>name;
				
				spawnWriter(name);
				spawnReader("stdout");

			}

			break;

		case 2:
			cout<<"Enter the file name, from which you want to read the names:\n";
			cin>>fname1;
			cout<<"Enter the file name, from which you want to write the reversed names:\n";
			cin>>fname2;

			f1.open(fname1, ios::in);

			if(!f1){
				cout<<"Unable to open the file.\n";
				break;
			}

			while(1){
			
				f1.getline(name, 25);
				
				if(f1.fail()){
					break;
				}
			
				spawnWriter(name);
				spawnReader(fname2);
				
			}

			f1.close();
			f2.close();
			break;

		default: 
			cout<<"Invalid Entry";
	}
}
