#include<cstring>
#include<iostream>
using namespace std;

struct student
{
    char student_name[20];
    float SGPA;
    int rollno;
};
int n;
class student_data{
    private:
    struct student s1[8];

    public:
    void view_data(){
        cout<<"\n \n Student Name      Roll no      SGPA"<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<"    "<<i+1<<" . "<<s1[i].student_name;
            cout<<"\t \t"<<endl;
            cout<<s1[i].rollno<<endl;
            cout<<"\t \t"<<endl;
            cout<<s1[i].SGPA<<endl;
        }
        
    }


    void add(){
        cout<<"\n enter the number of students data to be addedd (max 8)"<<endl;
        cin>>n;
        cout<<"\n Filling data such as Student name , roll number and SGPA"<<endl;
        for (int i = 0; i < n; i++)
        {
            cout<<"\n Detail of student no."<<i+1<<"-\n \n ENTER THE NAME OF THE STUDENT : "<<endl;
            cin>>s1[i].student_name;
            cout<<"\n ENTER THE ROLL NO OF THE STUDENT"<<endl;
            cin>>s1[i].rollno;
            cout<<"\n ENTER THE SGPA OF THE STUDENT"<<endl;
            cin>>s1[i].SGPA;
        }
        cout<<"ADDITION CARRIED OUT SUCCESFULLY"<<endl;
        student_data::view_data();
    }

    void search_name()
        {
            cout<<"\n Enter student name to be searched : ";
            char search[10];
            cin>>search;
            cout<<"\n< Searching name using Binary Search...>";
            int lower = 0, upper, mid;
            upper = n - 1;
            mid = (lower + upper)/2;
            student_data :: sort_names();
            while (lower <= upper)
            {
                if(strcmp(s1[mid].student_name, search)<0)
                {
                    lower = mid + 1;
                }
                else if(strcmp(s1[mid].student_name, search)==0)
                {
                    cout<<"\n\n# Details of Student with name "<<s1[mid].student_name<<" -";
                    cout<<"\n\n Student        Name         SGPA        Roll\n    No.                                           No.\n--------------------------------------------------------------\n";
                    cout<<"    1.        "<<s1[mid].student_name;
                    cout<<"   \t  "<<s1[mid].SGPA<<"   \t  "<<s1[mid].rollno;
                    cout<<"\n--------------------------------------------------------------";
                    break;
                }
                else
                {
                    upper = mid - 1;
                    mid = (lower + upper)/2;
                }
            }
            if(lower > upper)
            {
                cout<<"\n Student '"<<search<<"' details not found or Input correct name";
            }
        }

    void sort_names()  //insertion sort for sorting names
        {
            for (int k=n-1; k>0; k--)
            {  
                struct student temp = s1[k];
                int j = k-1;
                while (j >= 0 && strcmp(temp.student_name, s1[j].student_name) < 0)  
                {
                    s1[j+1] = s1[j];
                    j = j-1;
                }
                s1[j+1] = temp;
            }
        }
};

int main(){
    student_data std;
    float r;
    cout<<"------------------------------------------\n \t \t-------- WELCOME TO SE IT STUDENTS DATA BASE --------\n \t \t------------------------------------------"<<endl;
    char stop;
    stop='Y';
    while(stop=='Y'){
        cout<<"\n \n Select action form the following : \n"<<endl;
        cout<<"\n 1. Add Records \t 2.Search SGPA\t 3.Sort Roll no"<<endl;
        cout<<"Enter choice(1,2,3)"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
            std.add();
            break;

            case 2:
            cin>>r;
            std.search_name();

            case 3:
            cout<<"<<sorting name alphabetically>>"<<endl;
            std.sort_names();

            default:
            cout<<"Aiyan.......Baigan"<<endl;
        }
        cout<<"Do you want to continue(Y/N)"<<endl;
        cin>>stop;
        if(stop=='N'| 'n'){
            cout<<"--------------------------END OF A NIGHTMARE---------------------------------"<<endl;
        }
    }
    return 0;
}
