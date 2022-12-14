// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int v,e;
//     cin>>v>>e;
//     vector<int>grapha[v];
//     cout<<"Enter values"<<endl;
//     for(int i = 0;i<e;i++)
//     {
//         int x,y;
//         cin>>x>>y;
//         grapha[x].push_back(y);
//         grapha[y].push_back(x);
//     }
//     for(int i = 0;i<v;i++)
//     {
//         cout<<i<<"-----";
//         for(auto x : grapha[i])
//         {
//             cout<<x<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h> 
using namespace std;

void addedge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printgraph(vector<int>adj[],int v){
    for(int i = 0;i<v;i++){
        cout<<i;
        for(auto x: adj[i])
          cout<<"-> "<<x;
        cout<<endl;  
    }
}

void BFS (vector<int>adj[],int v ,int s)
{
    int visited[v];
    for(int i =0;i<v;i++)
    {
        visited[i] = false;
    }
    queue<int>q1;
    visited[s] = true;
    q1.push(s);
    while(!q1.empty())
    {
        int x = q1.front();
        cout<<x<<" ";
        q1.pop();
        for(auto i : adj[x])
        {
            if(!visited[i]){
            visited[i] = true;
            q1.push(i);
            }
        }

    }

}
int main() {
	//code
	{
	    int v;
	    cin>>v;
	    vector<int>adj[v];
        int v1,v2;
        cout<<"enter values till v1 != -1 and v2 != -1"<<endl;
	    while(1){
	        cin>>v1>>v2;
            if(v1 == -1 && v2 == -1)
               break;
	        addedge(adj,v1,v2);
	    }
	    printgraph(adj,v);
        
	}
	return 0;
}


