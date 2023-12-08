/*
PROBLEM STATEMENT: Represent a graph of your college campus using adjacency list /adjacency matrix.
Nodes should represent the various departments/institutes and links should
represent the distance between them. Find minimum spanning tree
b)Using Prims’s algorithm.
*/

#include<iostream>
#include<string>
#define SIZE 10
#define INFINITY 999
using namespace std;

class MST
{
   int graph[SIZE][SIZE],vertex,v1,v2;
   public:
      MST()
      {
        for(int i=0;i<SIZE;i++)  //initialise graph
         { for(int j=0;j<SIZE;j++)
             graph[i][j]=0;    }
       }
       
     void find_PrimsMST()
       {
         int select[SIZE],i,j,k,min_dist,total=0;
         for(i=0;i<vertex;i++)
             select[i]=0;
           cout<<"\n The Minimum Spanning Tree ";
           select[0]=1;
           for(k=1;k<vertex;k++)
           {
             min_dist=INFINITY;
             for(i=0;i<vertex;i++)
             {
               for(j=0;j<vertex;j++)
                {
                  if(graph[i][j] && ((select[i] && !select[j]) || (!select[i] && select[j])))
                     {
                       if(graph[i][j] <min_dist)
                         {
                           min_dist=graph[i][j];
                           v1=i;
                           v2=j;
                           }
                       }
                  }
              }
              cout<<" \n Edge (" <<v1 <<" " <<v2<<")"<<min_dist;
              select[v1]=select[v2]=1;
              total=total+min_dist;
            }
            cout<<"\n Total Distance: "<<total;
            cout<<"\n";
        }
       void get_data()
       { 
         int len,n;
         cout<<"\n Enter number of departments in the college ";
         cin>>vertex;
         cout<<"\n Enter number of edges :";
         cin>>n;
         cout<<"\n Enter edges and weights ";
         for(int i=0;i<n;i++)
          {
             cout<<"\n Enter Edge by V1 and V2: ";
             cin>>v1>>v2;
             cout<<"\n Enter Corresponding Distance between two vertex : ";
             cin>>len;
             graph[v1][v2]=graph[v2][v1]=len;
           }
        }   
        void printmatrix()
        {
         cout<<"\n Adjacency Matrix for departments in college :\n";
         for(int i=0;i<vertex;i++)
          {for(int j=0;j<vertex;j++)
            cout<<" "<<graph[i][j];
            cout<<"\n";
           } 
        }
          
     };
     
     int main()
     {
       MST mt;
       cout<<"\n\n Prim's Algorithm ";
       mt.get_data();
       mt.printmatrix();
       cout<<"\n \n";
       mt.find_PrimsMST();
      } 
               
                  
                           
            
/* output
C:\New C++>g++ prims.cpp

C:\New C++>a.exe


 Prim's Algorithm
 Enter number of departments in the college 5

 Enter number of edges :6

 Enter edges and weights
 Enter Edge by V1 and V2: 0 1

 Enter Corresponding Distance between two vertex : 7

 Enter Edge by V1 and V2: 0 2

 Enter Corresponding Distance between two vertex : 8

 Enter Edge by V1 and V2: 0 3

 Enter Corresponding Distance between two vertex : 5

 Enter Edge by V1 and V2: 3 4

 Enter Corresponding Distance between two vertex : 2

 Enter Edge by V1 and V2: 1 4

 Enter Corresponding Distance between two vertex : 6

 Enter Edge by V1 and V2: 2 4

 Enter Corresponding Distance between two vertex : 3

 Adjacency Matrix for departments in college :
 0 7 8 5 0
 7 0 0 0 6
 8 0 0 0 3
 5 0 0 0 2
 0 6 3 2 0



 The Minimum Spanning Tree
 Edge (0 3)5
 Edge (3 4)2
 Edge (2 4)3
 Edge (1 4)6
 Total Distance: 16
*/
