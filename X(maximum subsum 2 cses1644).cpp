#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5;
const int INF = 1e18;
int32_t main() {
    /*
     as we discussed before, a subarray is a big prefix-some smaller prefix
     if i know the smaller prefixes i can delete to get a subarray whose length is bet.[L,R]
     i can just always try subtracting the smallest such prefix.
     let's call the set of possible prefixes to subtract s
     i'll work one based and put 0 in the 0th position to represent subtracting nothing from the very first big prefix
     i'll then keep inserting possible prefixes as i move and i delete the invalid prefixes(if you need clarification, check the video for visualization or try to draw and visualize yourself)
     */
    int n,a,b;cin>>n>>a>>b;
    int arr[n+1]={};
    for (int i = 1; i <= n; i++) {
        cin>>arr[i];
    }
    int prefix[n+1]={};
    for (int i=1;i<=n;i++) {
        prefix[i]=prefix[i-1]+arr[i];
    }
    multiset<int> s;
    int ans=-INF;
    for (int i=a;i<=n;i++) {
        s.insert(prefix[i-a]);
        if (i-b-1 >=0) {
            s.erase(s.find(prefix[i-b-1]));
        }
        ans=max(ans,prefix[i] - *s.begin());
    }
    cout<<ans<<endl;
    return 0;
}