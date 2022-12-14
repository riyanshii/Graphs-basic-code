#include<bits/stdc++.h> 
using namespace std;

void addedge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUTIL(vector<int>adj[],vector<bool>&visited,int s)
{
    visited[s] = true;
    cout<<s<<" -- ";
    for(auto x : adj[s])
    {
        if(!visited[x])
        DFSUTIL(adj,visited,x);
    }
}

void DFS (vector<int>adj[],int v)
{
    vector<bool>visited(v,false);

    for(int i = 0;i<v;i++)
    {
        if(!visited[i])
        {
            DFSUTIL(adj,visited,i);
        }
    }

}
int main() {
	//code
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
    addedge(adj, 0, 4);
    addedge(adj, 1, 2);
    addedge(adj, 1, 3);
    addedge(adj, 1, 4);
    addedge(adj, 2, 3);
    addedge(adj, 3, 4);
    DFS(adj, v);
        
	}
	return 0;
}


