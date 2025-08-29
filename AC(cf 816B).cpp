#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
    int prefix[N]={};
int32_t main() {
    /*
     strategy is, increment in a range between [L....R] using the prefix sum update in a range trick(google it if you don't know it)
     after that you'll know for each temperature degree how many ranges it is present at
     after that, if a degree is present in less than k ranges, put 0 in it's index
     else put 1
     then prefix sum on that, that'll give you number of degrees that are present in k or more ranges between any L,R
     */
    int n,k,q;cin>>n>>k>>q;
    for (int i=0;i<n;i++) {
        int l,r;cin>>l>>r;
        prefix[l]++;
        prefix[r+1]--;
    }
    for (int i=1;i<N;i++) {
        prefix[i]=prefix[i-1]+prefix[i];
    }
    for (int i=0;i<N;i++) {
        if (prefix[i] <k){prefix[i]=0;}
        else{prefix[i]=1;}
    }
    for (int i=1;i<N;i++) {
        prefix[i]=prefix[i-1]+prefix[i];
    }
    while (q--) {
        int l,r;cin>>l>>r;
        int ans=prefix[r]-prefix[l-1];
        cout<<ans<<endl;
    }
    return 0;
}