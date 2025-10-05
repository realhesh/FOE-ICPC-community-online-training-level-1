#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int lim = 1e9;
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    t=1;
    cin>>t;
    while(t--){
        int l,r;cin>>l>>r;
        int cntbet = max(r-l+1-2,0ll);
        int ans=0;
        if (l != r) {
            ans = cntbet + __gcd(l,r) + r;
        }
        else if (l==r) {
            ans=l;
        }
        cout<<ans<<endl;
    }
}