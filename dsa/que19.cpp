//Problem Statement:-Department maintains student’s database. The file contains roll number, name, division and address.
//Write a program to create a sequential file to store and maintain student data. It should allow the
//user to add, delete information of student. Display information of particular student. If record of
//student does not exist an appropriate message is displayed. If student record is found it should
//display the student details.

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class Student
{
	char name[30];
	int roll;
	char division;
	string address;;
public:
	void createdatabase(int);
	void display();
	void addrecord(int);
	int Delete();
	void search();
};

void Student::createdatabase(int n)
{
	Student temp;
	ofstream fout;
	fout.open("StudentData.txt");
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter Name\n";
		cin>>temp.name;
		cout<<"Enter Roll No\n";
		cin>>temp.roll;
		cout<<"Enter Division\n";
		cin>>temp.division;
		cout<<"Enter address\n";
		cin>>temp.address;
		fout.write((char*)&temp,sizeof(temp));
	}
	fout.close();
}

void Student::display()
{
	Student temp;
	ifstream fin;
	fin.open("StudentData.txt");
	cout<<"Roll No\t\tName\t\tDivision\t\tAddress\n";
	while(fin.read((char*)&temp,sizeof(temp)))
	{
		cout<<temp.roll<<"\t\t"<<temp.name<<"\t\t"<<temp.division<<"\t\t"<<temp.address<<"\n";
	}
	fin.close();
}

void Student::addrecord(int n)
{
	Student temp;
	ofstream fout;
	fout.open("StudentData.txt",ios::app);
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter Name\n";
		cin>>temp.name;
		cout<<"Enter Roll No\n";
		cin>>temp.roll;
		cout<<"Enter Division\n";
		cin>>temp.division;
		cout<<"Enter address\n";
		cin>>temp.address;
		fout.write((char*)&temp,sizeof(temp));
	}
	fout.close();
}
int Student::Delete()
{   Student temp;
    cout<<"\nEnter roll no. of the student : ";
    int rno, flag = 0;
    cin>>rno;
    fstream read_file("StudentData.txt", ios::in | ios::binary);  //open file in read mode
    fstream newFile("temp.txt", ios::out | ios::binary);  //create new temp file for temporary data storage
    read_file.read((char*)&temp, sizeof(temp));
    while(!read_file.eof())
        {
            if(temp.roll != rno)  
            {
                newFile.write((char*)&temp, sizeof(temp));  //write to the temp file
            }
            else  
            {
                cout<<"\nRecord Found and Deleted!\n";
                flag = 1;
            }
            read_file.read((char*)&temp, sizeof(temp));  //read next record from the
        }
        read_file.close();
        newFile.close();
        remove("StudentData.txt");
        rename("temp.txt", "StudentData.txt");
return flag;
   }

void Student::search()
{
	fstream read_file("StudentData.txt", ios::in | ios::binary);  //open file in reading mode
    Student temp;
    if(!read_file)
    {
        cout<<"\nFile Not Found !\nCheck local directory, or try creating the file first from Menu option\n";
        return;
    }
    else
    {
        bool flag = false;
        cout<<"\nEnter roll no. to be searched : ";
        int key;
        cin>>key;
        read_file.read((char*)&temp, sizeof(temp)); //read first record
        while(!read_file.eof())  //search till end of file
        {
            if(temp.roll == key)  //if key is equal to correct roll number
            {
                cout<<"\nRecord found !\n";
                flag = true;  //set flag
                cout<<"\nRoll No.\tName\t\tDivision\t\tAddress\n---------------------------------------------------------------------------";
                cout<<"\n"<<temp.roll<<"\t\t"<<temp.name<<"\t"<<temp.division<<"/"<<"\t\t"<<temp.address;  //display student details
                break;
            }
            else
            {
                read_file.read((char*)&temp, sizeof(temp)); //read next record
            }
        }
        if(!flag)  //if roll no. is not found
            cout<<"\nRecord not found !\n";
    }
}
int main()
{
	int n,ch,x,z=0;
	Student obj;
	cout<<"\nEnter how many records you want to enter\n";
	cin>>n;
	do
	{
		cout<<"\nEnter\n1.Create Database \n2.Display Database \n3.Add New Record \n4.Delete  a record \n5.Search a Record\n6.End\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
			obj.createdatabase(n);
			break;
			case 2:
			obj.display();
			break;
			case 3:
			cout<<"\nEnter how many records you want to Add\n";
			cin>>x;
			obj.addrecord(x);
			break;
			case 4:
			z=obj.Delete();
			if(z)
				cout<<"\nData has been deleted\n";
			else
				cout<<"\nRoll No not found\n";
			break;
			case 5:
			   obj.search();
			    break;
			case 6:
			break;
			default:
			cout<<"\nWrong value entered\n";
		}
	}while(ch!=6);
	return 0;
}

/*
Output:-
Enter how many records you want to enter
2
Enter
1.Create Database 
2.Display Database 
3.Add New Record 
4.Delete  a record 
5.Search a Record
6.End
1
Enter Name
GEETESH
Enter Roll No
73
Enter Division
A
Enter address
Warje
Enter Name
ASHUTOSH
Enter Roll No
19
Enter Division
A
Enter address
Shivajinagar
Enter
1.Create Database 
2.Display Database 
3.Add New Record 
4.Delete  a record 
5.Search a Record
6.End
2
Roll No		Name		Division		Address
73		       GEETESH		A		       Warje
19		       ASHUTOSH		A		       Shivajinagar

Enter
1.Create Database 
2.Display Database 
3.Add New Record 
4.Delete  a record 
5.Search a Record
6.End
3
Enter how many records you want to Add
1
Enter Name
Ayush
Enter Roll No
26
Enter Division
A
Enter address
Madhukosh
Enter
1.Create Database 
2.Display Database 
3.Add New Record 
4.Delete  a record 
5.Search a Record
6.End
2
Roll No		Name		Division		Address
73		       GEETESH		A		       Warje
19		       ASHUTOSH		A		       Shivajinagar
26		       Ayush		A		       Madhukosh
 
Enter
1.Create Database 
2.Display Database 
3.Add New Record 
4.Delete  a record 
5.Search a Record
6.End
4
Enter roll no. of the student : 26
Record Found and Deleted!
Data has been deleted

Enter
1.Create Database 
2.Display Database 
3.Add New Record 
4.Delete  a record 
5.Search a Record
6.End
2
Roll No		Name		Division		Address
73		       GEETESH		A		       Warje
19		       ASHUTOSH		A		       Shivajinagar

Enter
1.Create Database 
2.Display Database 
3.Add New Record 
4.Delete  a record 
5.Search a Record
6.End
5
Enter roll no. to be searched : 19
Record found !

Roll No.	Name		Division		Address
---------------------------------------------------------------------------
19	       ASHUTOSH		A		       Shivajinagar

Enter
1.Create Database 
2.Display Database 
3.Add New Record 
4.Delete  a record 
5.Search a Record
6.End
6

*/
