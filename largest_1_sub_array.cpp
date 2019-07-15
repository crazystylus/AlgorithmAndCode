#include<bits/stdc++.h>
using namespace std;

void print_arr(vector<vector<int>> arr){
    for(auto i: arr){
        for(auto j: i)
            cout<<j<<" ";
        cout<<"\n";
    }
}

int main() {
    int n,m,tmp;
    cin>>n>>m;
    vector<vector<int>> arr;
    arr.resize(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            cin>>tmp;
            arr[i].push_back(tmp);
        }
    print_arr(arr);// Before

    for(int i=0;i<n-1;i++)
        for(int j=0;j<m-1;j++)
            if(arr[i][j]!=0 && arr[i+1][j]!=0 && arr[i][j+1]!=0 && arr[i+1][j+1]!=0)
                arr[i+1][j+1] = min(arr[i][j],min(arr[i+1][j],arr[i][j+1]))+1;
    cout<<"\nAfter\n";
    print_arr(arr);//After
    return 0;
}