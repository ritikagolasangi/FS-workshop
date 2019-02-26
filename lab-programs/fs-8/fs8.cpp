#include <fstream>
#include<iostream>
#include <cstdlib>
#include <cstring>

void bufclear(char *buffer)
{	for(int i=0;i<99;i++) buffer[i]='\0';
}

void reverse(char str[], int length) 
{ 
    int start = 0; 
    int end = length -1; 
    while (start < end) 
    { 
        std::swap(*(str+start), *(str+end)); 
        start++; 
        end--; 
    } 
} 

char* itoa(int num, char* str, int base) 
{ 
    int i = 0; 
    bool isNegative = false; 
    if (num == 0) 
    { 
        str[i++] = '0'; 
        str[i] = '\0'; 
        return str; 
    } 
    if (num < 0 && base == 10) 
    { 
        isNegative = true; 
        num = -num; 
    } 
	    while (num != 0) 
    { 
        int rem = num % base; 
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/base; 
    } 
    if (isNegative) 
        str[i++] = '-';   
    str[i] = '\0';
    reverse(str, i);   
    return str; 
} 

using namespace std;

int main()
{       char filename[100], temp[3], stuff[9][100];
	int i, low;
	fstream data,srun[9];

	data.open("out.txt",ios::out);
	for(i=1;i<=8;i++)
	{       bufclear(filename);
		strcpy(filename,"srun");
		strcat(filename,itoa(i,temp,10));
		strcat(filename,".txt");
		srun[i].open(filename,ios::in);
		if (srun[i].fail())
		{	cout << "cannot open " << filename <<"\n";
			//getch();
			exit(0);
		}
		bufclear(stuff[i]);
		srun[i] >> stuff[i];
	}
	for(;;)
	{	low=1;
		for(i=2;i<=8;i++) if (strcmp(stuff[i],stuff[low]) < 0) low=i;
		if (strcmp(stuff[low],"~") == 0)
		{       data.close();
			for(i=1;i<=8;i++) srun[i].close();
			cout << "k-way merging complete\n";
			//getch();
			cin.get();
			exit(0);
		}
		else
		{	data << stuff[low] << '\n';
			bufclear(stuff[low]);
			srun[low] >> stuff[low];
			if (srun[low].fail()) strcpy(stuff[low],"~");
		}
	}
}
