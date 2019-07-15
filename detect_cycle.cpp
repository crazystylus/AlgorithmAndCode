#include<bits/stdc++.h>
using namespace std;
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

int n;
vector<vector<int>> adj;
vector<int> visited,cycle;

bool dfs(int u,int p=-1){
    visited[u] = 1; //Entry Colour
    for(int v: adj[u])
        if(visited[v] == 1 && v != p){
            cycle.push_back(u);
            return true;
        }
        else if(visited[v]==0){
            if(dfs(v,u)){
                cycle.push_back(u);
                return true;
            }
        }
    visited[u] == 2; // Exit colour
    return false;
}

int main(){
    cin>>n;
    adj.resize(n);
    visited.resize(n);
    int tmp,x,y;
    while(true){
        cin>>x>>y>>tmp;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if(tmp == 0)
            break;
    }
    dfs(0);
    reverse(cycle.begin(),cycle.end());
    for(int i:cycle)
        cout<<"--> "<<i;
    return 0;
}