#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while (t--) {
        int n;cin>>n;
        int ans=1;
        for (int i=1;i<=n;i++) {
            for (int j=i*2;j<=n;j+=i) { //loop over multiples till n, if they exist then answer is atleast i
                ans=max(ans,i);
            }
        }
        cout<<ans<<endl;
    }
}