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
int n,s;
vector<bool> visit;
vector<int> d,p;
queue<int> q;
int main(){
    cin>>n;
    adj.resize(n);
    visit.resize(n);
    d.resize(n);
    p.resize(n);
    int tmp,x,y;
    while(true){
        cin>>x>>y>>tmp;
        adj[x].push_back(y);
        adj[y].push_back(x);
        if(tmp == 0)
            break;
    }
    s = 4;
    d[s] = 0;
    p[s] = -1;
    q.push(s);
    visit[s] = true;
    while(!q.empty()){
        int v = q.front();
        cout<<" --> "<<v;
        q.pop();
        for(auto u: adj[v])
            if(!visit[u]){
                visit[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
    }
    cout<<"\n Path to Vertice 4 \n";
    int fin = 1;
    if(visit[fin] == 0){
        cout<<"No path to vertex";
    }
    else{
        vector<int> path;
        for(auto i=fin; i != -1; i = p[i])
            path.push_back(i);
        reverse(path.begin(),path.end());
        for(auto i: path)
            cout<<i<<" --> ";
    }
    return 0;
}