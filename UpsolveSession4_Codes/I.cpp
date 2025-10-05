#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int lim = 1e9;
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    t=1;
    //cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        vector<int> v(n);
        for (int i=0;i<n;i++) {
            cin>>v[i];
        }
        v.push_back(x);
        sort(v.begin(),v.end());
        int ans = 0;
        for (int i=0;i<v.size()-1;i++) {
            ans=__gcd(ans,v[i+1]-v[i]);
        }
        cout<<ans<<endl;

    }
}