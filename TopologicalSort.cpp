#include<bits/stdc++.h> 
using namespace std;

void addedge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

void topologicalsortutil(vector<int>adj[],vector<bool>&visited,stack<int>&s,int i)
{
    visited[i] = true;
    for(auto x : adj[i])
    {
        if(!visited[x])
         topologicalsortutil(adj,visited,s,x);
    }
    s.push(i);
}

void topologicalsort(vector<int>adj[],int v)
{
    stack<int>s;
    vector<bool>visited(v,false);
    for(int i = 0;i<v;i++)
    {
        if(!visited[i])
        topologicalsortutil(adj,visited,s,i);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
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
        addedge(adj,5, 2);
       addedge(adj,5, 0);
       addedge(adj,4, 0);
       addedge(adj,4, 1);
       addedge(adj,2, 3);
      addedge(adj,3, 1);
      topologicalsort(adj,v);
	}
	return 0;
}


