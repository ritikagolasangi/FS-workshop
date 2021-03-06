/*
	2. Write a C++ program to read and write student objects with fixed-length records and
	the fields delimited by “|”. Implement pack ( ), unpack ( ), modify ( ) and search ( )
	methods.
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
		
		char buffer[45];
}s;

fstream fp;

// spawn process that will write to the named pipe
void spawnWriter(student s1)
{
	if (fork() == 0)
		execlp("./writer", "writer", s1.name, s1.usn, s1.sem, s1.age, s1.branch, NULL); 
}

void pack(){

	int len = 0, i, j;

	cout<<"Name :\n";
	cin>>s.name;
	cout<<"USN :\n";
	cin>>s.usn;
	cout<<"Semester :\n";
	cin>>s.sem;
	cout<<"Age :\n";
	cin>>s.age;
	cout<<"Branch :\n";
	cin>>s.branch;

	spawnWriter(s);
}

void unpack(){
	int i, j, len=0, flag=-1;
	char usn[10];
	char extra[45];
	char buffer[45];
	student s[20];

	fp.open("student.txt", ios::in);
	if(!fp){
		cout<<"Unable to open.\n";
	}
	
	cout<<"Enter the USN: \n";
	cin>>usn;
	
	i=0;
	
	while(!fp.eof()){
		fp.getline(s[i].name, 10, '|');
		fp.getline(s[i].usn, 10, '|');
		fp.getline(s[i].sem, 5, '|');
		fp.getline(s[i].age, 5, '|');
		fp.getline(s[i].branch, 5, '#');
		fp.getline(extra, 45);
		i++;
	}
	i--;

	for(j=0; j<i; j++){
		if(strcmp(s[j].usn, usn) == 0){
			flag == 1;
			cout<<"USN Found ! \n";

			cout<<"Enter new name:\n";
			cin>>s[j].name;
			cout<<"Enter new usn:\n";
			cin>>s[j].usn;
			cout<<"Enter new sem:\n";
			cin>>s[j].sem;
			cout<<"Enter new age:\n";
			cin>>s[j].age;
			cout<<"Enter new branch:\n";
			cin>>s[j].branch;
			break;
		}
	}
	fp.close();
	if(flag == -1){
		cout<<"USN not found\n";
	}

	fp.open("student.txt", ios::out);
	if(!fp){
		cout<<"Unable to open.\n";
	}

	for(j=0; j<i; j++){
		strcpy(buffer, s[j].name);
		strcat(buffer, "|");
		strcat(buffer, s[j].usn);
		strcat(buffer, "|");
		strcat(buffer, s[j].sem);
		strcat(buffer, "|");
		strcat(buffer, s[j].age);
		strcat(buffer, "|");
		strcat(buffer, s[j].branch);
		len = strlen(buffer);
		for(int k=0; k<45-len; k++){
			strcat(buffer, "#");
		}
		strcat(buffer, "\n");
		fp<<buffer;
		fp.close();
	}
}

void search(){
	char usn[10];
	char extra[45];
	int i, j, flag=-1;

	cout<<"Enter the usn:\n";
	cin>>usn;

	fp.open("student.txt", ios::in);
	if(!fp){
		cout<<"Unable to open the file.\n";
	}
	while(!fp.eof()){
		fp.getline(s.name, 10, '|');
		fp.getline(s.usn, 10, '|');
		fp.getline(s.sem, 5, '|');
		fp.getline(s.age, 5, '|');
		fp.getline(s.branch, 5, '#');
		fp.getline(extra, 45);
		if(strcmp(s.usn, usn) == 0){
			flag = 1;
			cout<<"USN Found\n";
			cout<<"Name\tUSN\tSemester\tAge\tBranch\n";
			cout<<s.name<<"\t"<<s.usn<<"\t"<<s.sem<<"\t\t"<<s.age<<"\t"<<s.branch<<"\n";
			break;
		}
	}
	if(flag == -1){
		cout<<"Record not found\n";
	}
	fp.close();
}

void display(){
	int i;	
	char extra[45];
	fp.open("student.txt", ios::in);
	if(!fp){
		cout<<"Unable to open the file.\n";
	}

	cout<<"Name\tUSN\tSemester\tAge\tBranch\t";
	while(!fp.eof()){
		fp.getline(s.name,10,'|');
		fp.getline(s.usn,10,'|');
		fp.getline(s.sem,5,'|');
		fp.getline(s.age,5,'|');
		fp.getline(s.branch,5,'#');
		fp.getline(extra, 45);
		printf("\n%s\t%s\t%s\t\t%s\t%s\n",s.name,s.usn,s.sem,s.age,s.branch);
		i++;
	}
	fp.close();
}

int main(void){
	int choice;
	do{
		cout<<"1.Pack\n2.Unpack\n3.Search\n4.Display\n";
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
