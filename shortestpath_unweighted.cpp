#include<bits/stdc++.h> 
using namespace std;

void addedge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

bool pathcal(vector<int>adj[],int s,int d,int v,vector<bool>&visited,vector<int>&distance,vector<int>&predicated)
{ 
    queue<int>q;
    visited[s] = true;
    distance[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto x : adj[u])
        {
            if(!visited[x])
            {
                visited[x] = true;
                predicated[x] = u;
                distance[x] = distance[u] + 1;
                q.push(x);

                if(x == d)
                return true;
            }
        }  
         
    }
     return false;  
}

void printpath(vector<int>adj[],int s,int d,int v)
{
     vector<bool>visited(v,false);
     vector<int>distance(v,INT_MAX);
     vector<int>predicated(v,-1);
     if(pathcal(adj,s,d,v,visited,distance,predicated) == false)
     {
         cout<<"-1"<<endl;
         return;
     }
     vector<int>path;
     int piche_wala = d;
     path.push_back(d);
     while(predicated[piche_wala] != -1)
    {
        path.push_back(predicated[piche_wala]);
        piche_wala = predicated[piche_wala];
    }

    for(int i = path.size()-1;i>=0;i--)
    {
        cout<<path[i]<<" ";
    }
}

int main() 
{
	int v;
	cin>>v;
	vector<int>adj[v];
        // int v1,v2;
        // cout<<"enter values till v1 != -1 and v2 != -1"<<endl;
	    // while(1){
	    //     cin>>v1>>v2;
        //     if(v1 == -1 && v2 == -1)
        //        break;
	    //     addedge(adj,v1,v2);
	    // }
    addedge(adj, 0, 1);
    addedge(adj, 0, 3);
    addedge(adj, 1, 2);
    addedge(adj, 3, 4);
    addedge(adj, 3, 7);
    addedge(adj, 4, 5);
    addedge(adj, 4, 6);
    addedge(adj, 4, 7);
    addedge(adj, 5, 6);
    addedge(adj, 6, 7);
    printpath(adj,0,7,v);
	return 0;
}


