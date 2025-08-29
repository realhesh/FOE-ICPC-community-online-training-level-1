#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5;
int prefix[MAXN]={};
int sum(int l,int r) {
    if (l==0) {
        return prefix[r];
    }
    else {
        return prefix[r]-prefix[l-1];
    }
}
int32_t main() {
    int n,x;cin>>n>>x;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    prefix[0]=arr[0];
    for (int i=1;i<n;i++) {
        prefix[i]=prefix[i-1]+arr[i];
    }
    int l=0,r=0;
    int currsum=arr[0];
    int ans=0;
    while (l<n) {
        if (currsum == x) { //if the sum is what we're looking for, move the left bound
            ans++;
            currsum-=arr[l];
            l++;
            if (l>r){r=l;currsum=arr[l];} //if l overtakes r, make r equal to l
        }
        else if (currsum < x) {//if it's less we need more elements, move right bound
            r++;
            currsum+=arr[r];
        }
        else if (currsum > x) {//if it's more, we need less elements, move left
            currsum-=arr[l];
            l++;
            if (l>r){r=l;currsum=arr[l];} //if l overtakes r, make r equal to l
        }
    }
    cout<<ans<<endl;
    return 0;
}