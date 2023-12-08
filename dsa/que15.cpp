/*Problem Statement-
Represent a graph of city using adjacency matrix /adjacency list. Nodes should
represent the various landmarks and links should represent the distance between
them. Find the shortest path using Dijkstra's algorithm from single source to all
destination.*/

#include <limits.h>
#include <iostream>
using namespace std;
// Number of vertices in the graph means various landmarks in the city of Pune
#define V 7
string landmark[10]={"Vadgaon","Shivane","Pashan","Balewadi","PCMC","Shivajinagar","Warje"};
 
// A utility function to find the vertex with minimum distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the constructed distance array
void printSolution(int dist[], int n)
{
    cout<<"\nVertex   Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout<<landmark[i]<<"\t\t"<<dist[i]<<"\n";
        
}
 
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; 
 
    bool sptSet[V]; // sptSet[i] will be true if vertex i is
                    // included in shortest path tree or shortest distance from src to i is finalized
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
         int u = minDistance(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
 	{
            if (!sptSet[v] && graph[u][v]  && dist[u] != INT_MAX   && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 }
    // print the constructed distance array
    printSolution(dist, V);
}
 
int main()
{    
       int graph[V][V] = { { 0, 4, 0, 6, 0, 2, 0 },
                        { 4 ,0 ,0 ,0 ,0 ,0 ,1 },
                        { 0 ,0, 0, 8, 0, 5, 0 },
                        { 6, 0, 8, 0, 9, 0, 0 },
                        { 0, 0 ,0 ,9 ,0 ,3 ,6 },
                        { 2 ,0 ,5 ,0 ,3 ,0 ,0 }, 
                        { 0 ,1 ,0 ,0 ,6 ,0 ,0}};
                        
    cout<<"\n Source is : "<<landmark[0]<<"\n";                    
 
    dijkstra(graph, 0);
 
    return 0;
}
 /* Output :
 C:\New C++>g++ Exp8.cpp

C:\New C++>a.exe

 Source is : Vadgaon

Vertex   Distance from Source
Vadgaon         0
Shivane         4
Pashan          7
Balewadi        6
PCMC            5
Shivajinagar    2
Warje           5
 */
