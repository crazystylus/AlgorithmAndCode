#include<bits/stdc++.h>
// TimeComplexity O(n)
// SpaceComplexity O(n)
using namespace std;



int max_sum(int arr[], int n){
    int dp[n];
    dp[0] = arr[0];
    for(int i=1;i<n;i++)
        dp[i] = max(dp[i-1],0)+arr[i];
    int tmp;
    tmp = dp[0];
    for(int i=0;i<n;i++)
        if(tmp < dp[i])
            tmp = dp[i];
    return tmp;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<max_sum(arr,n)<<"\n";
    return 0;
}