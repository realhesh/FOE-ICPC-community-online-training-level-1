#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int lim = 1e9;
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v(n);
        int curr=0;
        for(int i=0;i<n;i++) {
            cin>>v[i];
            curr=__gcd(curr,v[i]);
        }
        if (curr==1) {
            cout<<n<<endl;
        }
        else {
            cout<<-1<<endl;
        }

    }
}