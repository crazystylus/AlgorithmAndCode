#include<bits/stdc++.h>
/*
INPUT::

5
0 1
1
1 2
1
0 2
1
3 0
1
3 4
0


 */

using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> tin,low;
int timer;
int n;
int bridges;
void dfs(int v, int p = -1){
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for(int to:adj[v]){
        if(to == p) continue;
        if(visited[to]){
            low[v] = min(low[v], tin[to]);
        }
        else{
            dfs(to,v);
            low[v] = min(low[v], low[to]);
            if(low[v] < low[to]){
                bridges++;
            }
        }
    }
}

int main(){
    cin>>n;
    adj.resize(n);
    visited.resize(n);
    tin.resize(n);
    low.resize(n);
    timer = bridges = 0;
    int tmp,x,y;
    while(true){
        cin>>x>>y>>tmp;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if(tmp == 0)
            break;
    }
    /*for(auto i: adj){
        for(auto j: i)
            cout<<j<<" ";
        cout<<"\n";
    }*/
    for(int i=0;i<n;i++)
        if(!visited[i])
            dfs(i);
    cout<<"\n Total Bridges :-> "<<bridges<<"\n";
    return 0;
}