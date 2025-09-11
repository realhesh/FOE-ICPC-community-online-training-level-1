#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
 dividing is always good option so we always divide if we can
 otherwise we quikcly figure out how many times we need to divide to become divisible by k
 the number of times is n%k
 */
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while (t--) {
        int n,k;cin>>n>>k;
        int ans=0;
        while (n!=0) {
            if (n%k==0){n/=k;ans++;}
            else{ans+=(n%k);n-=(n%k);}
        }
        cout<<ans<<"\n";
    }
}

/*

 */