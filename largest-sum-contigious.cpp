#include<bits/stdc++.h>
#include<limits.h>
//Kadane's Algorithm O(n)
using namespace std;

int max_cont(int arr[], int n){
    int max_sofar = INT_MIN;
    int max_ending_here = 0;
    for(int i=0;i < n; i++){
        max_ending_here += arr[i];
        if(max_ending_here > max_sofar)
            max_sofar = max_ending_here;
        if(max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_sofar;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Max sub-array contiguous sum is --> "<<max_cont(arr,n);
    return 0;
}