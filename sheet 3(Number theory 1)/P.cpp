#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 +8;
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while (t--) {
        int n;cin>>n;
        string s;cin>>s;
        bool proper[n+1]={};
        int ans=0;
        for (int i=1;i<=n;i++) {
            for (int j=i;j<=n;j+=i) {
                if (s[j-1] =='0' && proper[j-1] == 0) {
                    proper[j-1]=1;
                    ans+=i;
                }
                else if (s[j-1]=='1') {
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
}

/*
1 2 3 4 5 6 7
1 2 - 4 - - 7
6+5
 */