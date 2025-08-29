#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5;
int32_t main() {
    map<int,int> ctr;
    //a subarray is just a prefix that got a smaller prefix removed from it
    //big_prefix - smaller_prefix should equal x
    //manipulating the equation, smaller_prefix = big_prefix - x
    //thus i can count the number of smaller prefixes that occured before the point i am at
    int n,x;cin>>n>>x;
    int arr[n]={};
    int prefix[n]={};
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    prefix[0]=arr[0];
    for (int i=1;i<n;i++) {
        prefix[i]=prefix[i-1]+arr[i];
    }
    int ans=0;
    ctr[0]=1; //this represents erasing nothing
    for (int i=0;i<n;i++) {
        ans+=ctr[prefix[i]-x];
        ctr[prefix[i]]++; // this is the second operation because i can't erase the enter prefix
                          //if i make it first any case with X = 0 gets messed up
    }
    cout<<ans<<endl;
    return 0;
}