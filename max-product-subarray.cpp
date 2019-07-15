#include<bits/stdc++.h>
#include<limits.h>
#include<math.h>
// Doubtfull
using namespace std;

int max_prod(int arr[], int n){
    int curr_min = arr[0];
    int curr_max = arr[0];
    int prod = arr[0];
    int pre_prod = arr[0];
    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            curr_max = curr_max*arr[i];
            curr_min = min(1,curr_min*arr[i]);
        }
        else if(arr[i] == 0){
            curr_max = 0;
            curr_min = 1;
        }
        else if (arr[i] < 0){
            int tmp_min = curr_max*a[i];
            int tmp_max = curr_min*a[i];
            curr_max = tmp_max;
            curr_min = tmp_min;
        }
        
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Max Product is --> "<<max_prod(arr,n)<<"\n";
    return 0;
}