#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
/*

INPUT:
5
0 1 10
1 2 20
0 2 15
3 0 22
3 4 40

*/
struct Edge{
    int u,v,weight;
    bool operator<(Edge const& other){
        return weight < other.weight;
    }
};

int n;
vector<Edge> edges,result;
int cost = 0;
vector<int> treeid;

int main(){
    cin>>n;
    Edge tmp;
    int oldid,newid;
    for(int i=0;i<n;i++){
        cin>>tmp.u>>tmp.v>>tmp.weight;
        edges.push_back(tmp);
    }
    for(int i=0;i<n;i++)
        treeid.push_back(i);
    sort(edges.begin(), edges.end());
    for(Edge e: edges){
        if(treeid[e.u] != treeid[e.v]){
            cost += e.weight;
            result.push_back(e);
            oldid = treeid[e.u];
            newid = treeid[e.v];
            //printf("Edge (%d,%d) with tid(%d,%d)--> ",e.u,e.v,treeid[e.u],treeid[e.v]);
            for(int i=0;i<n;i++)
                if(treeid[i] == oldid){
                    printf("%d,",i);
                    treeid[i] = newid;
                }
            cout<<"\n";
        }
    }
    printf("Total Cost  %d \n",cost);
    for(Edge e: result){
        printf("(%d,%d) weight = %d\n",e.u,e.v,e.weight);
    }
    return 0;
}