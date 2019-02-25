#include<cstring>
#include<istream>
#include<ostream>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

using namespace std;

int count=0,count1=0;
char Nebuf[200]="",SNebuf[200]="",knodes[100][100];

class Stud;

class IOBUFFER
{
   public:
    
    void initialize()
	{
	    Nextbyte=0;Buffersize=75;Buffer[0]=0;
	}

	virtual int Read(istream &,int)=0;
	virtual int Write(ostream &)=0;
	virtual int pack(Stud &,fstream &)=0;
	virtual int unpack(Stud &,fstream &)=0;

   protected:
	char Buffer[100];
	int Buffersize;
	int Nextbyte;
};

class FixedLengthBuffer:public IOBUFFER
{
	public:
		int Read(istream &,int);
		int Write(ostream &);
};

class VariableFieldBuffer:public FixedLengthBuffer
{
    public:
		int pack(Stud &,fstream &);
		int unpack(Stud &,fstream &);
};

/*Student class*/

class Stud
{
	public:
	
		char urn[30],name[30],address[30],semester[30],branch[30];
	
		Stud()
	    {
		   urn[0]=0;
		   name[0]=0;
		   address[0]=0;
		   semester[0]=0;
		   branch[0]=0;
		}
		 
		void Input();
		void Modify();
		void Assign1(Stud &);
		void Assign();
		void Display();
		void Secondary();
		int  Binary(char *);
		void SecondSort();
		void Index();
		void del();
		void KeySort();
		void Indexdisplay(int);
		void Secondsearch(char *);
		void Invertprimary();
		void Invertsecondary();
		void Invertsecondarysort();
		void CheckDup();
		void InvertSecondarySort();
		int  InvertSecondSearch(char *);
};

class fsearch
{
	 public:
	 	int Search(char *);
};

int Stud::Binary(char *key)
{
	 int mid=0,k,ptr1,low,high,i=0;
	 low=0;
	 high=count-1;
	 char nname[20]="",recaddr[10],*endptr;
	 int l=strlen(key);
	 
    while(1)
    {         
      	for(int j=0;j<15;j++)
			nname[j]='\0';
		
		mid=(low+high)/2;

		if(low>high)
			return -1;

		for(i=0;knodes[mid][i]!='|';i++)
			nname[i]=knodes[mid][i];
		
		i++;

		for(int n=0;knodes[mid][i]!='|';i++)
			recaddr[n++]=knodes[mid][i];

		int num=strtol(recaddr,&endptr,10);
		ptr1 = strcasecmp(nname,key);

		if (ptr1 > 0)
		      high=mid-1;
		else if (ptr1 < 0)
		       low=mid+1;
		else if(ptr1==0)
		
		return num;
	}
}

Stud s1,s2;
void Stud::Modify()
{
	char key[20],Buff[100];
	int size=0,found=0,asize=75,Next=0;
	cout<<"\n\tENTER THE SEARCH KEY: ";
	cin>>key;
	VariableFieldBuffer b;
	fstream file("list.txt",ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0,ios::beg);
	while(b.unpack(*this,file))
	  {
	    if(strcasecmp(urn,key)==0)
	      {
		found=1;
		break;
	      }
	     size=size+75;
	  }
	if(found==1)
	 {
		char choice[10];
		cout<<"\n\n\t\t\t\tRecord is found ...."<<endl<<endl;
		cout<<"\n\t\t\tDetails Of Record";
		cout<<"\n\t\n\n";
		cout<<"\n\t\t\tURN      :"<<urn<<endl;
		cout<<"\n\t\t\tNAME     :"<<name<<endl;
		cout<<"\n\t\t\tADDRESS  :"<<address<<endl;
		cout<<"\n\t\t\tSEMESTER :"<<semester<<endl;
		cout<<"\n\t\t\tBRANCH   :"<<branch<<endl;
		cout<<"\n\n\t\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\n\n";
		cout<<"\nDo You Want To Update USN(Y/N)       :";
		cin>>choice;
	   if(choice[0]=='y'||choice[0]=='Y')
	    {
		cout<<"\n\t\tENTER THE URN            :";
		cin>>urn;
	    }
	    cout<<"\nDO You Want To Update NAME(Y/N)      :";
	    cin>>choice;
	    if(choice[0]=='y'||choice[0]=='Y')
	     {
		 cout<<"\n\t\tENTER THE NAME           :";
		 cin>>name;
	     }

	    cout<<"\nDO You Want To Update ADDRESS(Y/N)   :";
	    cin>>choice;

	    if(choice[0]=='y'||choice[0]=='Y')
	      {
		  cout<<"\n\t\tENTER THE ADDRESS        :";
		  cin>>address;
	      }
	     cout<<"\nDO You Want To Update SEMESTER(Y/N)  :";
	    cin>>choice;

	    if(choice[0]=='y'||choice[0]=='Y')
	      {
		  cout<<"\n\t\tENTER THE SEMENSTER      :";
		  cin>>semester;
	      }
	    cout<<"\nDO You Want To Update BRANCH(Y/N)    :";
	    cin>>choice;

	    if(choice[0]=='y'||choice[0]=='Y')
	      {
		  cout<<"\n\t\tENTER THE BRANCH         :";
		  cin>>branch;
	      }

	      for(int i=0;i<75;i++)
	       {
		  Buff[i]=' ';
	       }

	       this->Assign1(s1);
	       memcpy(&Buff,&asize,sizeof(asize));
	       strcpy(Buff,s1.urn); strcat(Buff,"|");
	       strcat(Buff,s1.name);strcat(Buff,"|");
	       strcat(Buff,s1.address);strcat(Buff,"|");
	       strcat(Buff,s1.semester);strcat(Buff,"|");
	       strcat(Buff,s1.branch);strcat(Buff,"|");
	       Next=strlen(Buff);

	       if(Next>asize)
		  cout<<"\n\n\t\t\tRecord Overflow .... \n";
	       else
		 {
		   file.seekp(size);
		   file.write(Buff,asize);
		   cout<<"\n\n\t\t\t\tRecord Is Updated ....\n";
		 }

	 }

    else
		cout<<setw(40)<<"\n\n\n\t\t\tRecord Not Found ....\n";

     file.close();
     
}

void Stud::Assign1(Stud &s1)
{
	strcpy(s1.urn,urn);
	strcpy(s1.name,name);
	strcpy(s1.address,address);
	strcpy(s1.semester,semester);
	strcpy(s1.branch,branch);
}

void Stud::Input()
{
	int k,value;
	char usn[30];
	Stud a;
	fsearch v;
	VariableFieldBuffer b;
	fstream file;
	cout<<"\n\t--------------------------------------------------\n\n";
	cout<<"\n\tENTER THE URN     :";;
	cin>>urn;
	while(v.Search(urn)==1)
	 {
		cout<<"\n\nDuplicate Entry Re-Enter The URN Value: ";;
		cin>>urn;
	 }
	 cout<<"\n\tENTER THE NAME    :";
	 cin>>name;
	 cout<<"\n\tENTER THE ADDRESS :";
	 cin>>address;
	 cout<<"\n\tENTER THE SEMESTER:";
	 cin>>semester;
	 cout<<"\n\tENTER THE BRANCH  :";
	 cin>>branch;
	 file.open("list.txt",ios::app);
	 k=b.pack(*this,file);
	 file.close();
	 if(k==1)
	 cout<<"\n\n\t\t\tRecord Inserted ....\n\n";
	else
	 cout<<"some problem";
}

/*Display function*/

void Stud :: Display()
{
	VariableFieldBuffer c;
	fstream file("list.txt",ios::in);
	file.seekg(0,ios::beg);
	while(c.unpack(*this,file))
	 {
		 int i;
	   cout<<endl<<endl<<endl;
	   cout<<setw(25)<<" "<<"DISPLAYING RECORD'S"<<endl<<endl<<endl<<endl;
	   for(i=0;i<80;i++)   cout<<"*";   cout<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" UNIVERSITY REG NO :  "<<urn<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" NAME              :  "<<name<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" ADDRESS           :  "<<address<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" SEMESTER          :  "<<semester<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" BRANCH            :  "<<branch<<endl<<endl<<endl<<endl;
	   for(i=0;i<80;i++) cout<<"*";
	   cout<<endl<<endl<<setw(39)<<" ";
	   
	 }
      if(!(c.unpack(*this,file)))
       {
	 cout<<endl<<endl<<endl<<endl<<setw(40)<<"NO RECORDS FOUND ....";
	 
	 return;
       }

    file.clear();
    file.close();
}

/*Assign function*/

void Stud::Assign()
{
	char key[20],Buff[100];
	int size=0,found=0,asize=75,Next=0;
	cout<<"\n\tENTER THE SEARCH KEY  :";
	cin>>key;
	VariableFieldBuffer b;
	fsearch v;
	fstream file("list.txt",ios::app|ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0,ios::beg);
	while(b.unpack(*this,file))
	  {
	    if(strcasecmp(urn,key)==0)
	      {
		found=1;
		break;
	      }
	     size=size+75;
	  }
	if(found==1)
	 {
	  char choice[10];
	  cout<<"\n\n\t\t\t\tRecord is found ...."<<endl<<endl;
	  cout<<"\n\t\t\tDetails Of Record";
	  cout<<"\n\t\n\n";
	  cout<<"\n\t\t\tURN      :"<<urn<<endl;
	  cout<<"\n\t\t\tNAME     :"<<name<<endl;
	  cout<<"\n\t\t\tADDRESS  :"<<address<<endl;
	  cout<<"\n\t\t\tSEMESTER :"<<semester<<endl;
	  cout<<"\n\t\t\tBRANCH   :"<<branch<<endl;
	  cout<<"\n\n\t\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\v\vs\v\v\v\v\v\v\v\v\v\v\v\v\v\n\n";

	  cout<<"\n\t\tENTER THE URN            :";
	  cin>>urn;

		while(v.Search(urn)==1)
		{
			cout<<"\n\nDuplicate Entry Re-Enter The URN Value  :";
			cin>>urn;
		}
	  cout<<"\n\t\tENTER THE NAME           :";
	  cin>>name;

	  cout<<"\nDO You Want To Update ADDRESS(Y/N)   :";
	  cin>>choice;

		if(choice[0]=='y'||choice[0]=='Y')
		{
		  cout<<"\n\t\tENTER THE ADDRESS        :";
		  cin>>address;
		}

	  cout<<"\nDO You Want To Update SEMESTER(Y/N)  :";
	  cin>>choice;

		if(choice[0]=='y'||choice[0]=='Y')
		{
		  cout<<"\n\t\tENTER THE SEMENSTER      :";
		  cin>>semester;
		}

	    cout<<"\nDO You Want To Update BRANCH(Y/N)    :";
	    cin>>choice;

		if(choice[0]=='y'||choice[0]=='Y')
		{
		  cout<<"\n\t\tENTER THE BRANCH         :";
		  cin>>branch;
		}

		for(int i=0;i<75;i++)
		{
		  Buff[i]=' ';
		}

	       this->Assign1(s1);
	       memcpy(&Buff,&asize,sizeof(asize));
	       strcpy(Buff,s1.urn); strcat(Buff,"|");
	       strcat(Buff,s1.name);strcat(Buff,"|");
	       strcat(Buff,s1.address);strcat(Buff,"|");
	       strcat(Buff,s1.semester);strcat(Buff,"|");
	       strcat(Buff,s1.branch);strcat(Buff,"|");
	       Next=strlen(Buff);

	       if(Next>asize)
		  cout<<"\n\n\t\t\tRecord Overflow .... \n";
	      else
		 {
		   file.write(Buff,asize);
		   cout<<"\n\n\t\t\t\tRecord Is Updated ....\n";
		 }

	 }

    else
	cout<<setw(40)<<"\n\n\n\t\t\tRecord Not Found ....\n";

     file.close();
     
}

/*Delete function*/

void Stud::del()
{
char key[20],Buff[100];
	int size=0,asize=75,found=0;
	cout<<"\nENTER THE RECORD KEY TO BE DELETED  :";
	cin>>key;
	fsearch u;
	found=u.Search(key);
	if(found==1)
	cout<<"\n\n\n\t\t\tRecord Is Found ....";
	else
	cout<<"\n\n\n\t\t\tRecord Is Not Found ....";

	VariableFieldBuffer b;
	fstream file,file1;
	if(found==1)
	{
	file.open("list.txt",ios::app|ios::in|ios::out|ios::ate|ios::binary);
	file.seekg(0,ios::beg);
	file1.open("llist.txt",ios::out);
	file1.seekg(0,ios::beg);
	 while(b.unpack(*this,file))
	 {
	    if(strcmp(urn,key)==0)
	      {
	      cout<<"\n\n\n\n\t\tRecord Is Deleted ....\n";
	       size=size+75;
	      }
	      else
	      {
	       for(int i=0;i<75;i++)
	       {
		  Buff[i]=' ';
	       }
	       this->Assign1(s1);
	       memcpy(&Buff,&asize,sizeof(asize));
	       strcpy(Buff,s1.urn); strcat(Buff,"|");
	       strcat(Buff,s1.name);strcat(Buff,"|");
	       strcat(Buff,s1.address);strcat(Buff,"|");
	       strcat(Buff,s1.semester);strcat(Buff,"|");
	       strcat(Buff,s1.branch);strcat(Buff,"|");
	       file1.write(Buff,asize);
	       size=size+75;
	      }
	  }
	}
	  if(found==1)
	  {
	  unlink("list.txt");
	  rename("llist.txt","list.txt");
	   }


	 file1.close();
	 file.close();
	 
}

/*Key sorting*/

void Stud::KeySort()
{
char Buffer[15],str1[15]="",str2[15]="";
int length=15,ptr,i=0;
int j, m;
fstream file("index.txt",ios::in);
file.seekg(0,ios::beg);

while(1)
{
	file.read(Buffer,length);
		if(file.fail())
			break;
		for(j=0;j<15;j++)
			knodes[i][j]=Buffer[j];
		i++;
}

for(j=0;j<15;j++)
knodes[i][j]=Buffer[j];
file.close();

for(i=0;i<count;i++)
{
	for(m=0;m<15;m++)
	str1[m]=knodes[i][m];
	j=i-1;
	a:
	for(m=0;m<15;m++)
	str2[m]=knodes[j][m];
	ptr=strcasecmp(str1,str2);
	while(j>=0&&ptr<0)
	{
	     for(m=0;m<15;m++)
	     knodes[j+1][m]=knodes[j][m];
	     j--;
	 goto a;
	}

	for(m=0;m<15;m++)
	knodes[j+1][m]=str1[m];
}

knodes[i][j]=Buffer[j];
}

void  Stud::Index()
{
	int size=0,length=75,i;
	char uns[15]="0",IBuff[75]="";
	count=0;
	ifstream ofile("list.txt",ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("index.txt",ios::out);
	if(ofile.fail())
		 cout<<"file not exist";
	else
		 while(1)
		  {
			 ofile.read(IBuff,length);
			 if(ofile.fail())
			 break;
			 for(i=0;IBuff[i]!='|';i++)
			 uns[i]=IBuff[i];
			 count++;
			 nfile.seekp(size);
			 nfile<<uns<<"|"<<count<<"|";
			 size=size+15;
		  }
	 nfile.close();
	 ofile.close();
}

void Stud::Secondary()
{
	int size=0,length=75, i;
	char uns[20]="0",name[20]="0",Buffer[75]="";
	count=0;
	ifstream ofile("list.txt",ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("Second.txt",ios::out);
	if(ofile.fail())
		 cout<<"file not exist";
	else
		 while(1)
		  {
			 ofile.read(Buffer,length);
			 if(ofile.fail())
			  break;
	       int j=0;

	       for(i=0;Buffer[i] != '|';i++)
			uns[j++]=Buffer[i];
	       uns[j]='\0';
	       i++;

	       for(j=0;Buffer[i]!='|' ;i++)
		       name[j++]=Buffer[i];
	       name[j]='\0';

			 count++;
			 nfile.seekp(size);
			 nfile<<name<<"|"<<uns<<"|";
			 size=size+30;
		  }
	 nfile.close();
	 ofile.close();
}

void Stud::SecondSort()
{
char Buffer[30],str1[30]="",str2[30]="";
int length=30,ptr,i=0,m,j;
fstream file("second.txt",ios::in);
file.seekg(0,ios::beg);
while(1)
{
	file.read(Buffer,length);
		if(file.fail())
			break;

		for(j=0;j<30;j++)
			knodes[i][j]=Buffer[j];
		i++;
}

for(j=0;j<30;j++)
	knodes[i][j]=Buffer[j];

file.close();

for(i=0;i<count;i++)
{     j=0;
	for(m=0;m<30;m++)
		str1[m]=knodes[i][m];
	j=i-1;
	a:

	for(m=0;m<30;m++)
		str2[m]=knodes[j][m];
	ptr=strcasecmp(str1,str2);

	while(j>=0&&ptr<0)
	{
	     for(m=0;m<30;m++)
	     knodes[j+1][m]=knodes[j][m];
	     j--;
	 goto a;
	}

	for(m=0;m<30;m++)
		knodes[j+1][m]=str1[m];
}

knodes[i][j]=Buffer[j];
}

void Stud :: Indexdisplay(int size)
{
	VariableFieldBuffer c;
	int i;
	fstream file("list.txt",ios::in);
	file.seekg(size,ios::beg);
	c.unpack(*this,file);
	   cout<<endl<<endl<<endl;
	   cout<<setw(25)<<" "<<"DISPLAYING RECORD'S"<<endl<<endl<<endl<<endl;

	   for(i=0;i<80;i++)   cout<<"*";   cout<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" UNIVERSITY REG NO :  "<<urn<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" NAME              :  "<<name<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" ADDRESS           :  "<<address<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" SEMESTER          :  "<<semester<<endl<<endl<<endl;
	   cout<<setw(20)<<" "<<" BRANCH            :  "<<branch<<endl<<endl<<endl<<endl;
	   for(i=0;i<80;i++) cout<<"*";
	   cout<<endl<<endl<<setw(39)<<" ";
	   
    file.clear();
    file.close();
}

  void Stud::Secondsearch(char *key)
  {
  char nname[20]="",unn[20]="";
  int l,ptr1, n, i, k;
  Stud ss;

    while(1)
    {
		for(k=0;k<count;k++)
		{
		for(i=0;knodes[k][i]!='|';i++)
		nname[i]=knodes[k][i];
		i++;
		l=strlen(key);
		for( n=0;knodes[k][i]!='|';i++)
		unn[n++]=knodes[k][i];
		ptr1 = strcasecmp(nname,key);
		if(ptr1==0)
		{
		  ss.Index();
		  ss.KeySort();
		  int a=ss.Binary(unn);

			if(a==-1)
			cout<<"Record not found.......!";
			else
			{
				//int b=a;
					a=a-1;
					a=a*75;
				ss.Indexdisplay(a);
				cout<<"\n\n\nRecord found successfull ....  ";
				ss.Secondary();
				ss.SecondSort();
			}
		   }
		if(count-1==k)
		break;
	      }
	      break;

   }


}


void Stud::Invertprimary()
{
int size=0,length=75;
	char uns[20]="0",IBuff[75]="";
	count=0;
	ifstream ofile("list.txt",ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("index1.txt",ios::out);
	if(ofile.fail())
		 cout<<"file not exist";
	else
		 while(1)
		  {
			 ofile.read(IBuff,length);
			 if(ofile.fail())
			  break;
			 for(int i=0;IBuff[i]!='|';i++)
			 uns[i]=IBuff[i];
			 count++;
			 nfile.seekp(size);
			 nfile<<count<<"|"<<uns<<"|"<<-1<<"|";
			 size=size+25;
		  }

	 nfile.close();
	 ofile.close();
}

void Stud::Invertsecondary()
{
int size=0,length=75, i, k;
	char uns[20]="0",IBuff[75]="",name[20]="";
      count=0;
      Stud as;
	ifstream ofile("list.txt",ios::in);
	ofile.seekg(0,ios::beg);
	fstream nfile("second1.txt",ios::out);
	if(ofile.fail())
		 cout<<"file not exist";
	else
		 while(1)
		  {
			 ofile.read(IBuff,length);
			 if(ofile.fail())
				  break;

			 for(i=0;IBuff[i]!='|';i++)
				 uns[i]=IBuff[i];
			 i++;

			 for(k=0;IBuff[i]!='|';i++)
				name[k++]=IBuff[i];
			 name[k]='\0';
			 count++;
			 nfile.seekp(size);
			 nfile<<name<<"|"<<count<<"|";
			 size=size+25;
		  }
	 nfile.close();
	 ofile.close();
}

void Stud::Invertsecondarysort()
{
char Buffer[25],str1[30]="",str2[30]="";
int length=25,ptr,i=0, j, m;
fstream file("second1.txt",ios::in);
file.seekg(0,ios::beg);
for(j=0;j<25;j++)
knodes[i][j]='\0';
while(1)
{
	for(j=0;j<25;j++)
		Buffer[j]='\0';
	file.read(Buffer,length);

	if(file.fail())
		break;

	for( j=0;j<25;j++)
		knodes[i][j]=Buffer[j];
	i++;
}

for( j=0;j<25;j++)
	knodes[i][j]=Buffer[j];

file.close();

for(i=0;i<count;i++)
{      j=0;
	for(m=0;m<25;m++)
		str1[m]=knodes[i][m];
	j=i-1;
	a:
	for(m=0;m<25;m++)
		str2[m]=knodes[j][m];
		ptr=strcasecmp(str1,str2);

	while(j>=0&&ptr<0)
	{
	     for(m=0;m<25;m++)
		    knodes[j+1][m]=knodes[j][m];
	     j--;
	goto a;
	}

	for(m=0;m<25;m++)
		knodes[j+1][m]=str1[m];
}

knodes[i][j]=Buffer[j];
}

void Stud::CheckDup()
{
	  int found,size=0,length=75, m ,j, n;
	  char nname[25]="",kname[20]="",klen[5]="",*endptr,Buffer[75]="",ukk[15]="";
	  Stud sss;
	  fstream qfile("second3.txt",ios::out);
	  qfile.seekp(0,ios::beg);
	  fstream ffile("second2.txt",ios::out);
	  ffile.seekp(0,ios::beg);
	  fstream file("second1.txt",ios::in|ios::out);
	  file.seekg(0,ios::beg);
	   found=count;
	  int i=0;
	  while(i<count)
	  {
	  int l=0;
		 for( m=0;m<20;m++)
			 kname[m]='\0';
		 for(j=0;knodes[i][j]!='|';j++)
			 kname[j]=knodes[i][j];
		 j++;

		for(n=0;knodes[i][j]!='|';j++)
			 klen[n++]=knodes[i][j];


		int p=strlen(kname);
		int  ptr=strcasecmp(kname,nname);

		if(ptr==0)
		{
		ffile<<klen<<"|";
			fstream nfile("list.txt",ios::in);
			nfile.seekg(0,ios::beg);
			int i;
			int  num=strtol(klen,&endptr,10);
			num=num-1;
			num=num*75;
			nfile.seekg(num);
			nfile.read(Buffer,length);
			 for(i=0;Buffer[i] != '|';i++)
				ukk[l++]=Buffer[i];
			 ukk[l]='\0';
			 qfile<<ukk<<"|";

		found=found+1;
		nfile.close();
		}

	       if(ptr>0)
		 {
			ffile.seekp(size);
			strcpy(nname,kname);
			ffile<<kname<<"|"<<klen<<"|";
			fstream nfile("list.txt",ios::in);
			nfile.seekg(0,ios::beg);
			int  num=strtol(klen,&endptr,10);
			num=num-1;
			num=num*75;
			nfile.seekg(num);

			nfile.read(Buffer,length);

			for(int i=0;Buffer[i] != '|';i++)
				ukk[l++]=Buffer[i];

			ukk[l]='\0';
			qfile.seekp(size);
			qfile<<kname<<"|"<<ukk<<"|";
			nfile.close();
			size=size+30;
		 }

		i++;
	     found--;
	}
  ffile.close();
  file.close();
}


void Stud::InvertSecondarySort()
{
char Buffer[30],str1[30]="",str2[30]="";
int length=30,ptr,i=0, m, j;
fstream file("second3.txt",ios::in);
file.seekg(0,ios::beg);

while(1)
{
	file.read(Buffer,length);
	if(file.fail())
		break;

	for(int j=0;j<30;j++)
		knodes[i][j]=Buffer[j];
	i++;
}

	for(j=0;j<30;j++)
		knodes[i][j]=Buffer[j];
	file.close();

for(i=0;i<count;i++)
{     j=0;
	for(m=0;m<30;m++)
		str1[m]=knodes[i][m];
	j=i-1;
	a:

	for(m=0;m<30;m++)
		str2[m]=knodes[j][m];
	ptr=strcasecmp(str1,str2);

	while(j>=0&&ptr<0)
	{
	     for(m=0;m<30;m++)
		     knodes[j+1][m]=knodes[j][m];
	     j--;
	 goto a;
	}

	for(m=0;m<30;m++)
		knodes[j+1][m]=str1[m];
}

knodes[i][j]=Buffer[j];

for(i=0;i<count;i++)
	 for(j=0;j<30;j++)
		cout<<knodes[i][j];
}

int  Stud::InvertSecondSearch(char *key)
{
char str1[30]="";
int found=0, j;
char Buffer[30];
int length=30,ptr,i=0;
fstream file("second3.txt",ios::in);
file.seekg(0,ios::beg);

while(1)
{
	file.read(Buffer,length);
	if(file.fail())
	break;
	for(j=0;j<30;j++)
		knodes[i][j]=Buffer[j];
	i++;
}

for(j=0;j<30;j++)
knodes[i][j]=Buffer[j];

for( i=0;i<count;i++)
{
 for(j=0;knodes[i][j]!='|';j++)
     str1[j]=knodes[i][j];
     str1[j]='\0';
     int l=strlen(key);
     int ptr=strcasecmp(str1,key);
     if(ptr==0)
     {
	found=1;
	break;
     }
 }

if(found==1)

{
	for(int j=0;j<30;j++)
		cout<<knodes[i][j];
return 1;
}
	else
		return -1;
}

int FixedLengthBuffer::Read(istream &stream,int size)
{
stream.read(Buffer,Buffersize+size);
return stream.good();
}

int FixedLengthBuffer::Write(ostream &stream)
{
stream.write(Buffer,Buffersize);
return stream.good();
}
//3333333333333333
//class Stud;
//class fsearch;

//---------------------------------------
/*Pack Function*/
void normal();
void screen();
void screen1();

int VariableFieldBuffer::pack(Stud &s,fstream &file)
{
	int value;
	initialize();

	for(int i=0;i<75;i++)
	{
	   Buffer[i]=' ';
	}

	memcpy(&Buffer[0],&Buffersize,sizeof(Buffersize));
	strcpy(Buffer,s.urn); strcat(Buffer,"|");
	strcat(Buffer,s.name);strcat(Buffer,"|");
	strcat(Buffer,s.address);strcat(Buffer,"|");
	strcat(Buffer,s.semester);strcat(Buffer,"|");
	strcat(Buffer,s.branch);strcat(Buffer,"|");
	Nextbyte=strlen(Buffer);

	if(Nextbyte>Buffersize)
	  return 0;

	else
	  value=Write(file);
	  return value;
}

/*Unpack Function*/

int VariableFieldBuffer::unpack(Stud &s,fstream &file)
{
	initialize();
	Nextbyte=0;
	int i;
	int value = Read(file,Nextbyte);
	if(value==0) return 0;
	if(Buffersize > 0)
	{
	int j=0;
	      for(i=0;Buffer[i] != '|';i++)
	       s.urn[j++]=Buffer[i];
	       s.urn[j]='\0';
	       i++;

	      for(j=0;Buffer[i]!='|' ;i++)
	       s.name[j++]=Buffer[i];
	       s.name[j]='\0';
	       i++;

	      for(j=0;Buffer[i]!= '|';i++)
		s.address[j++]=Buffer[i];
		s.address[j]='\0';
		i++;

	      for(j=0;Buffer[i]!= '|';i++)
		s.semester[j++]=Buffer[i];
		s.semester[j]='\0';
		i++;

	      for(j=0;Buffer[i]!= '|';i++)
		 s.branch[j++]=Buffer[i];
		 s.branch[j]='\0';
		 i++;

	       Nextbyte=Buffersize+75;
	       return 1;
	}
return 0;
}

/*Function to search a key*/

int fsearch::Search(char *key)
{
	  int found=0;
	  Stud s1;
	  VariableFieldBuffer b;
	  fstream file("list.txt",ios::in|ios::out);
	  file.seekg(0,ios::beg);
	  while(b.unpack(s1,file))
	     if(strcasecmp(s1.urn,key)==0)
		  found=1;
	     file.close();
	  return found;
}


/*Main function*/

int main()
{

int choice,ch,cho,a;
char key[15];
Stud s;

do
{
     screen();

     cout<<"     PLEASE ENTER YOUR CHOICE [1-3]  :   ";
     cin>>ch;
	  
	switch(ch)
	{
	case 1:
		do
		{
			cout<<"        STUDENT RECORDS       ";
			cout<<"B  M A I N    M E N U B";
			cout<<"1.>  INSERT";
			cout<<"2.>  UPDATE";
			cout<<"3.>  DISPLAY ALL";
			cout<<"4.>  ASSIGN";
			cout<<"5.>  DELETE";
			cout<<"6.>  QUIT";
			cout<<"     PLEASE ENTER YOUR CHOICE [1-6]  : ";
			cin>>choice;

			switch(choice)
			{
				case 1:s.Input();
					break;

				case 2:s.Modify();
					break;

				case 3:s.Display();
					break;

				case 4:s.Assign();
					break;

				case 5:s.del();
					break;

				case 6:
					screen();
					break;

				default:
					break;
			}
		}while(choice!=6);
	break;

	case 2:
	do
	{
		screen1();
		cout<<"     PLEASE ENTER YOUR CHOICE [1-4]  : ";
		cin>>cho;

		switch(cho)
		{
			case 1:
			cd:
			s.Index();
			s.KeySort();
			cout<<"Enter the Primary key: ";
			cin>>key;
			a=s.Binary(key);
			if(a==-1)
			{
				cout<<"Record not found....!";
			}
			else
			{
				//int b=a;
				a=a-1;
				a=a*75;
				s.Indexdisplay(a);
				cout<<"\n\n\nSuccessfull search......  :";
			}
			
			break;

			case 2:
			s.Secondary();
			s.SecondSort();
			cout<<"Enter the Secondary key: ";
			cin>>key;
			a=s.Binary(key);
			if(a==-1)
			{
				cout<<"Record not found....!";
			}
			s.Secondsearch(key);
			
			break;

			case 3: {
			s.Invertprimary();
			s.Invertsecondary();
			s.Invertsecondarysort();
			s.CheckDup();
			cout<<"Enter the Secondary key: ";
			cin>>key;
			a=s.Binary(key);
			if(a==-1)
			{
				cout<<"Reco	rd not found....!";
			}
			s.InvertSecondarySort();
			int b=s.InvertSecondSearch(key);
			if(b==1)
				goto cd;
			else
			{
				cout<<"Record not found...!";
			}
			}break;

			case 4:
			break;
		}
	}while(cho!=4);
	screen();
	break;

	case 3:
		exit(0);

	default:
		break;
	} 
	}while(ch!=3);

	return 0;
}

void screen()
{
     
     cout<<"        FILE STRUCTURE       ";
     
     cout<<"M A I N    M E N U ";
     
     cout<<"STUDENT RECORD";
     
     cout<<"INDEXING";
     
     cout<<"QUIT";
     
}


void screen1()
{
     int b,g=19,h=10;
	 cout<<"        INDEXING      ";
     
	 cout<<"M A I N    M E N U ";
     
     cout<<"SIMPLE INDEX";
     
     cout<<"SECONDARY KEY";
     
     cout<<"INVERTED LIST";
     
     cout<<"QUIT";
}
