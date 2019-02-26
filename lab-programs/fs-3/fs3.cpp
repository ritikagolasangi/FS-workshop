/*
	3. Write a C++ program to read and write student objects with Variable - Length
	records using any suitable record structure. Implement pack ( ), unpack ( ), modify ( )
	and search ( ) methods.
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <unistd.h>

using namespace std;

class student{
public:
	char name[10];
	char usn[10];
	char sem[5];
	char age[5];
	char branch[5];
	char buffer[100];
}s;

fstream fp;

// spawn process that will write to the named pipe
void spawnWriter()
{
	if (fork() == 0)
		execlp("./writer", "writer", s.name, s.usn, s.sem, s.age, s.branch, NULL); 
}

int pack(){
	
	cout<<"Enter the name";
	cin>>s.name;
	cout<<"Enter the usn";
	cin>>s.usn;
	cout<<"Enter the sem";
	cin>>s.sem;
	cout<<"Enter the age";
	cin>>s.age;
	cout<<"Enter the branch";
	cin>>s.branch;

	spawnWriter();
}

int unpack(){
	//pack
	student s[10];
	int i, j;
	int flag = -1;
	char usn[10];

	cout<<"Enter the usn\n";
	cin>>usn;

	fp.open("student.txt", ios::in);
	if(!fp){
		cout<<"Unable to oepn the file\n";
	}
	i=0;
	while(!fp.eof()){
		fp.getline(s[i].name, 10, '|');
		fp.getline(s[i].usn, 10, '|');
		fp.getline(s[i].sem, 5, '|');
		fp.getline(s[i].age, 5, '|');
		fp.getline(s[i].branch, 5, '\n');
		i++;
	}
	i--;

	for(j=0; j<i; j++){
		if(strcmp(s[j].usn, usn) == 0){
			flag = 1;
			cout<<"USN found\n";

			cout<<"Enter new name\n";
			cin>>s[j].name;
			cout<<"Enter new usn\n";
			cin>>s[j].usn;
			cout<<"Enter new sem\n";
			cin>>s[j].sem;
			cout<<"Enter new age\n";
			cin>>s[j].age;
			cout<<"Enter new branch\n";
			cin>>s[j].branch;
			break;
		}
	}
	fp.close();

	if(flag == -1){
		cout<<"USN not found\n";
	}
	
	fp.open("student.txt", ios::out);

	for(j=0; j<i; j++){
		fp<<s[j].name<<"|"<<s[j].usn<<"|"<<s[j].sem<<"|"<<s[j].age<<"|"<<s[j].branch<<"\n";

	}
	fp.close();
}

int search(){
	//pass
	int flag = -1;
	char usn[10];
	cout<<"enter the usn\n";
	cin>>usn;

	fp.open("student.txt", ios::in);

	while(!fp.eof()){
		fp.getline(s.name, 10, '|');
		fp.getline(s.usn, 10, '|');
		fp.getline(s.sem, 5, '|');
		fp.getline(s.age, 5, '|');
		fp.getline(s.branch, 5, '\n');

		if(strcmp(s.usn, usn) == 0){
			flag = 1;
			cout<<"Usn found\n";
			cout<<"Name\tUSN\tSemester\tAge\tBranch\n";
			printf("\n%s\t%s\t%s\t%s\t%s\n",s.name,s.usn,s.sem,s.age,s.branch);
			break;
		}
	}
	if(flag == -1){
		cout<<"USN not found\n";
	}
	fp.close();
}

int display(){
	//pass

	fp.open("student.txt", ios::in);
	cout<<"Name\tUSN\tSemester\tAge\tBranch\n";
	while(!fp.eof()){
		fp.getline(s.name, 10, '|');
		fp.getline(s.usn, 10, '|');
		fp.getline(s.sem, 5, '|');
		fp.getline(s.age, 5, '|');
		fp.getline(s.branch, 5, '\n');
		printf("\n%s\t%s\t%s\t%s\t%s\n",s.name,s.usn,s.sem,s.age,s.branch);
	}
	fp.close();
}

int main(void){
	int choice;
	do{
		cout<<"1. Pack\n2. Unpack\n3. Search\n4. Display\n";
		cout<<"Enter your choice\n";
		cin>>choice;
		switch(choice){
			case 1:
				pack();
				break;
			case 2:
				unpack();
				break;
			case 3:
				search();
				break;
			case 4:
				display();
				break; 
			default:
				cout<<"Invalid Entry\n";
				break;
		}
	}while(choice>0 && choice <5);
}
