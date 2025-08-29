#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
int32_t main() {
    /*
     keep the sorted array and the original array and do prefix sum on both
     */
    int n;cin>>n;
    int arr[3][n],arr2[n];
    for (int i=0;i<n;i++) {
        cin>>arr[1][i];
        arr[2][i]=arr[1][i];
    }
    sort(arr[2],arr[2]+n);
    int prefix[3][n];
    prefix[1][0]=arr[1][0];
    prefix[2][0]=arr[2][0];
    for (int i=1;i<=2;i++) {
        for (int j=1;j<n;j++) {
            prefix[i][j] =prefix[i][j-1] + arr[i][j];
        }
    }
    int q;cin>>q;
    while (q--) {
        int t,l,r;cin>>t>>l>>r;
        l--;r--;
        if (l==0) {
            cout<<prefix[t][r]<<endl;
        }
        else {
            cout<<prefix[t][r]-prefix[t][l-1]<<endl;
        }
    }


}
/*
 1
 4 4 2
 2 2 3 3
 4 4 4 4
 */