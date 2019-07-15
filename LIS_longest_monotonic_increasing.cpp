#include<bits/stdc++.h>
using namespace std;

// LIS O(n)
/*
19
3 100 200 9 10 15 30 300 1 1 1 350 1 1 1 400 1 1 40
 */
vector<int> memo,arr;
int n,maxall = 0;
int calls = 0;
int recur(int curr){
    int maxi = 0;
    calls++;
    if(memo[curr] != 0)
       return memo[curr];
   
    int flag = 0;
    for(int i=curr+1;i<n;i++){
        if(memo[i] == 0)
            recur(i);
        if(arr[i]>= arr[curr]){
            flag = 1;
            //cout<<arr[curr]<<" "<<memo[i]<<"\n";
            maxi = max(maxi,memo[i]+1);
        }
    }
    if(flag == 0)
        maxi = 1;
    memo[curr] = maxi;
    maxall = max(maxall,maxi);
    return maxi;
}

int main(){
    cin>>n;
    memo.resize(n,0);
    arr.resize(n,0);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    recur(0);
    for(int i:memo)
        cout<<i<<" ";
    cout<<"\nANS --> "<<maxall;
    cout<<"\nCalls -->"<<calls<<"\n";
    return 0;
}