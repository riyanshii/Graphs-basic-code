#include<bits/stdc++.h>
using namespace std;

#define v 5

void printMST(vector<int>&parent,int graph[v][v])
{
      for (int i = 1; i < v; i++) 
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
}

int minkey(vector<bool>&visited,vector<int>&key)
{
    int min = INT_MAX,min_index;
    for(int i = 0;i<v;i++)
    {
        if(!visited[i] && key[i]<min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void PrimMST(int graph[v][v])
{
    vector<int>parent(v);
    vector<bool>visited(v,false);
    vector<int>key(v,INT_MAX);
    key[0] = 0;
    parent[0] = -1;
    for(int i =0;i<v-1;i++)
    {
        int u = minkey(visited,key);
        visited[u] = true;
        for(int j = 0;j<v;j++)
        {
            if(graph[i][j] && !visited[j] && graph[i][j] < key[j])
            {
                parent[j] = u;
                key[j] = graph[i][j];
            }
        }
    }
    printMST(parent,graph);
}

int main() 
{ 
    /* Let us create the following graph 
        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | / \ | 
    (3)-------(4) 
            9     */
    int graph[v][v] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
  
    // Print the solution 
    PrimMST(graph); 
  
    return 0; 
} 