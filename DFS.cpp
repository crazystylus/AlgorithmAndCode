#include<bits/stdc++.h>
using namespace std;
/*
INPUT:
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


vector<vector<int>> adj;
int n;
vector<bool> visit;
void dfs(int u){
    visit[u] = true;
    cout<<u<<"-->";
    bool flag = 0;
    for(auto v:adj[u])
        if(!visit[v]){
            flag = 1;
            dfs(v);
        }
    return;
}

int main(){
    cin>>n;
    adj.resize(n);
    visit.resize(n);
    int tmp,i,j;
    while(true){
        cin>>i>>j>>tmp;
        adj[i].push_back(j);
        adj[j].push_back(i);
        if(tmp == 0)
            break;
    }
    dfs(0);
    cout<<"\n";
    return 0;
}