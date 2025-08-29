#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
int32_t main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) {cin>>arr[i];}
    int l=0,r=0;
    int ans=0;
    int cur=arr[l];
    while (r<n) {
        while (cur > k) {
            cur-=arr[l];
            l++;
            if (l>r){r=l;cur=arr[r];}
        }
        if (r<n)
            ans=max(ans,r-l+1);
        r++;
        if (r<n) {
            cur+=arr[r];
            if (cur <=k){ans=max(ans,r-l+1);}
        }
    }
    cout<<ans<<endl;
    return 0;
}