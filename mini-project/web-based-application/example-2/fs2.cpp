#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>

#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace cgicc;

/****************************
Forward declaring FixedLengthBuffer since its a member of class Person
******************************/
class FixedLengthBuffer;

/******************************************************************************
* Class               : Person
*
* Members             : usn[] character array, to hold student's usn
*                       name[] character array to hold student's name
*                       address[] character array to hold student's address
*                       branch[] character array to hold student's branch
*                       college[] character array to hold student's college
*
* Methods             : input() to accept user input
*                       output() to display all records
*                       search() to search a record
*                       modify() to modify a given record
******************************************************************************/
class Person {
private:
    char usn[30];
    char name[30];
    char address[30];
    char branch[30];
    char college[30];

public:
    void input();
    void output();
    void search(char *filename);
    void modify(char * filename);
    friend class FixedLengthBuffer;
};


/******************************************************************************
* Class               : FixedLengthBuffer
*
* Members             : buffer[] character array, the buffer
*                       delim character, delimiter character
*
* Methods             : pack() to pack student details into a fixed length buffer
*                       unpack() (vice-versa)
*                       read() to read from the file
*                       write() to write to a file
******************************************************************************/
class FixedLengthBuffer {
private:
    char buffer[160];
    char delim;

public:
    void unpack(Person &p);
    void pack(Person &p);
    void read(fstream &fs);
    void write(char *filename);
    FixedLengthBuffer();
};

/*****************************************************************************
* Takes student details from standard input
*****************************************************************************/
void Person::input()
{
    /*cout << "Enter USN: "<<endl;
    gets(usn);
    cout << "Enter the Name"<<endl;
    gets(name);
    cout << "Enter the Address"<<endl;
    gets(address);
    cout << "Enter the Branch"<<endl;
    gets(branch);
    cout << "Enter college"<<endl;
    gets(college);*/
    
    cout << "<form action=\"/cgi-bin/fixed-length-buffer\" method=\"POST\">\n";
   	cout << "Enter USN: <input type=\"text\" name=\"usn\" value=\"usn\""<< "/>";
   	cout << "</p>\n";
   	cout << "Enter the Name: <input type=\"text\" name=\"name\" value=\"name\""<< "/>";
   	cout << p();
   	cout << "Enter the Address: <input type=\"text\" name=\"address\" value=\"address\""<< "/>";
   	cout << p();
   	cout << "Entern the Branch: <input type=\"text\" name=\"branch\" value=\"branch\"" << "/>";
   	cout << p();
   	cout << "Enter College: <input type=\"text\" name=\"college\" value=\"college\""<< "/>";
   	cout << p();
   	cout << p();
   	cout << "<input type=\"submit\" name=\"insubmit\" value=\"submit\"/>";
   	cout << "</form>";
   	
   	try {
   	
		Cgicc formData1;
   		form_iterator iname = formData1.getElement("name");
	   	form_iterator iusn = formData1.getElement("usn");
	   	form_iterator iadd = formData1.getElement("address");
	   	form_iterator ibranch = formData1.getElement("branch");
	   	form_iterator icoll = formData1.getElement("college");
	   	
		if( !iname->isEmpty() && iname != (*formData1).end()) {
		  strcpy(name,iname->getValue().c_str());
		}
	
		if( !iusn->isEmpty() && iusn != (*formData1).end()) {
		  strcpy(usn,iusn->getValue().c_str());
		}
	
		if( !iadd->isEmpty() && iadd != (*formData1).end()) {
		  strcpy(address,iadd->getValue().c_str());
		}
	
		if( !ibranch->isEmpty() && ibranch != (*formData1).end()) {
		  strcpy(branch,ibranch->getValue().c_str());
		}
	
		if( !icoll->isEmpty() && icoll != (*formData1).end()) {
		  strcpy(college,icoll->getValue().c_str());
		}
	}
    catch(exception& e) {
       cout << "ERROR!!" << endl;
    } 	
}

/*****************************************************************************
* Displays student details to standard output
*****************************************************************************/
void Person::output()
{
    cout << "USN: ";
    puts(usn);
    cout << "Name: ";
    puts(name);
    cout << "Address: ";
    puts(address);
    cout << "Branch:";
    puts(branch);
    cout << "College: ";
    puts(college);
}

/*****************************************************************************
* Constructor : Initializes the buffer and sets vertical bar as the default
                delimiter
*****************************************************************************/
FixedLengthBuffer::FixedLengthBuffer()
{
    for(int i = 0; i < 160; i++)
    buffer[i] = '\0';
    delim = '|';
}

/*****************************************************************************
* Method : Packs the fields into a fixed length buffer
*****************************************************************************/
void FixedLengthBuffer::pack(Person &p)
{
    strcpy(buffer, p.usn); strcat(buffer,"|");
    strcat(buffer, p.name); strcat(buffer,"|");
    strcat(buffer, p.address); strcat(buffer,"|");
    strcat(buffer, p.branch); strcat(buffer,"|");
    strcat(buffer, p.college); strcat(buffer,"|");
}

/*****************************************************************************
* Method: Unpacks the character data from the fixed length buffer into the student 
*         class
*****************************************************************************/
void FixedLengthBuffer::unpack(Person &p)
{
    char *ptr = buffer;
    while(*ptr) {
        if(*ptr == '|')
            *ptr = '\0';
        ptr++;
    }
    ptr = buffer;
    strcpy(p.usn, ptr);
    ptr = ptr + strlen(ptr)+1;
    strcpy(p.name, ptr);
    ptr = ptr+strlen(ptr) + 1;
    strcpy(p.address, ptr);
    ptr = ptr + strlen(ptr) + 1;
    strcpy(p.branch, ptr);
    ptr = ptr + strlen(ptr) + 1;
    strcpy(p.college, ptr);
}

/*****************************************************************************
* Method : reads a record from the file
*****************************************************************************/
void FixedLengthBuffer::read(fstream& fs)
{
    fs.read(buffer, sizeof(buffer));
}

/*****************************************************************************
* Method : Writes a record into the file
*****************************************************************************/
void FixedLengthBuffer::write(char *filename)
{
    fstream os(filename, ios::out|ios::app);
    os.write(buffer,sizeof(buffer));
    os.close();
}

/*****************************************************************************
* Method : Searches for a record in the file with USN as the key and displays
           displays its contents if found. 
*****************************************************************************/
void Person::search(char *filename)
{
    int found = 0;
    char key[30];
    FixedLengthBuffer b;
    Person p;
    fstream is(filename,ios::in);
    
    
    //cout << "Enter the usn of the record to be searched:" << endl;
    //cin >> key;
    
    cout << "<form action=\"/cgi-bin/fixed-length-buffer\" method=\"POST\">\n";
    cout << "</p>";
   	cout << "Enter the usn of the record to be searched: <input type=\"text\" name=\"key\" "<< "/>";
    cout << "</p>";
   	cout << "<input type=\"submit\" name=\"searchsubmit\" value=\"submit\"/>";
   	cout << "</form>";
   	
   	try {
   	
		Cgicc formData2;
   		form_iterator ikey = formData2.getElement("key");
	   	
		if( !ikey->isEmpty() && ikey != (*formData2).end()) {
		  strcpy(key,ikey->getValue().c_str());
		}
	}
    catch(exception& e) {
       cout << "ERROR!!" << endl;
    } 
    
    while(is && !found) {
        b.read(is);
        if(is.eof())
        break;
        b.unpack(p);
        if(strcmp(p.usn,key) == 0) {
            cout << "Record found!!!" << endl;
            p.output();
            found = 1;
        }
    }
    if(!found)
    cout << "Record not found!!!" << endl;
    is.close();
}

/*****************************************************************************
* Method : Modifies a file by searching a record, and if found updates it
*****************************************************************************/
void Person::modify(char* filename)
{
    char key[30];
    cout << "Enter the usn of the record to be modified:"<<endl;
    gets(key);
    FixedLengthBuffer b;
    Person p;
    char tempfile[] = "temp.txt";
    int found = 0;
    fstream is(filename, ios::in);
    fstream tfile(tempfile, ios::out|ios::app);
    while(is) {
        b.read(is);
        if(is.eof())
        break;
        b.unpack(p);
        if(strcmp(p.usn,key) == 0) {
            cout<<"\n Enter the new entry:"<<endl;
            p.input();
            b.pack(p);
            b.write(tempfile);
            found = 1;
        }
        else {
            b.pack(p);
            b.write(tempfile);
        }
    }
    if(!found)
    cout << "The record with the given usn does not exist" << endl;
    remove(filename);
    rename(tempfile, filename);
    is.close();
}

/*****************************************************************************
* Function    : main()
* Parameters  : none
*****************************************************************************/
int main()
{
    int choice = 1;
    Person ob;
    FixedLengthBuffer b;
    char filename[] = "data.txt";
    
    /*while(choice < 4)
    {
        cout<<"1: Insert a record"<<endl;
        cout<<"2: Search for a record"<<endl;
        cout<<"3: Modify a record"<<endl;
        cout<<"4: Exit"<<endl;
        cout<<"Enter the choice  ";
        cin>>choice;
        cin.get();
        switch(choice)
        {
            case 1: ob.input();
                b.pack(ob);
                b.write(filename);
                break;
            case 2: ob.search(filename);
                break;
            case 3: ob.modify(filename);
                break;
        }
        
    }*/
    
    try {
	   Cgicc formData;
	   
       cout << HTTPHTMLHeader() << endl;
       cout << HTMLDoctype(HTMLDoctype::eStrict) << endl;
       cout << html().set("lang", "EN").set("dir", "LTR") << endl;
       cout << html() << head() << title("Student Record Application") << head() << endl;
       cout << body().set("bgcolor","#cccccc").set("text","#000000").set("link","#0000ff").set("vlink","#000080") << endl;

       cout << h1("Student Record Application using Fixed Length Buffers") << endl;

       form_iterator fvalue1 = formData.getElement("v1");
       if( !fvalue1->isEmpty() && fvalue1 != (*formData).end()) {
          cout << "Operation: " << **fvalue1 << endl;
          
          if(strcmp(fvalue1->getValue().c_str(), "insert") == 0){
          		ob.input();
                b.pack(ob);
                b.write(filename);
          }
          else if(strcmp(fvalue1->getValue().c_str(), "search") == 0){
          		ob.search(filename);
          }
          else{
          		ob.modify(filename);
          }
       }

       cout << p();

       cout << body() << html();
    }
    catch(exception& e) {
       cout << "ERROR!!" << endl;
    }
    return 0;
}
