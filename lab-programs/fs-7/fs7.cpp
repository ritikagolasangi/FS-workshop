/*
	7. Write a C++ program to read two lists of names and then match the names in the two lists
	using Consequential Match based on a single loop. Output the names common to both the
	lists.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>

using namespace std;

class student{
public:
	char name[10];
};

// spawn process that will write to the named pipe
void spawnWriter(char name[])
{
	if (fork() == 0)
		execlp("./writer", "writer", name, NULL); 
}

int main(void){
	int m = 0,n = 0,i,j;
	fstream f1,f2,f3;
	char list1[100][10], list2[100][10];
	
	f1.open("list1.txt", ios::in);
	f2.open("list2.txt", ios::in);
	f3.open("list3.txt", ios::out);
		
	cout<<"List 1 names:\n";
	while(!f1.eof()){
		f1.getline(list1[m], 10, '\n');
		cout<<list1[m]<<"\n";
		m++;
	}

	cout<<"List 2 names:\n";
	while(!f2.eof()){
		f2.getline(list2[n], 10, '\n');
		cout<<list2[n]<<"\n";
		n++;
	}
	f1.close();
	f2.close();
	

	m--;
	n--;

	i=0;
	j=0;

	cout<<"Common names:\n";
	while(i<m && j<n){
		if(strcmp(list1[i], list2[j]) == 0){
			cout<<list1[i]<<"\n";
			spawnWriter(list1[i]);
			i++;
			j++;
		}
		else if(strcmp(list1[i], list2[j]) < 0){
			i++;
		}
		else{
			j++;
		}
	}
	f3.close();
}
