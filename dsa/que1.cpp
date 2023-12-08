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

    void search(float key){
        cout<<"searching the student using linear search"<<endl;
        int flag=0;
        for (int i = 0; i < n; i++)
        {
            if (s1[i].SGPA==key)
            {
                cout<<"\n \n #"<<flag<<"deatils of the student with SGPA"<<s1[i].SGPA<<endl;
                cout<<"\n \n Student      Name      Roll no      SGPA.\n"<<endl;
                cout<<"\n-----------------------------------------------------------"<<endl;
                flag++;
                continue;
            }
            if(flag==0){
                cout<<"Student"<<key<<"not found or Input correct SGPA"<<endl;
            }
            
        }
    }

    void sort_rollno(){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n-1; i++)
            {
                if ((s1[j].rollno)>(s1[j+1].rollno))
                {
                    struct student temp;
                    {
                        temp=s1[j];
                        s1[j]=s1[j+1];
                        s1[j+1]=temp;
                    }
                    
                }
                
            }
            
        }
        student_data::view_data();
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
        cout<<"\n 1. Add Records \t 2.Search SGPA\t 3.Sort Roll no\t 4.View record"<<endl;
        cout<<"Enter choice(1,2,3,4)"<<endl;
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
            std.add();
            break;

            case 2:
            cout<<"<<enter the SGPA of the student>>"<<endl;
            cin>>r;
            std.search(r);

            case 3:
            cout<<"<<sorting roll call using bubble sort>>"<<endl;
            std.sort_rollno();

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
