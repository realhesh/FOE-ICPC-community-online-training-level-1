#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9;
int n,l,r,x;
vector<int> v;
int f(int idx,int diff,int mn,int mx) {
    if (idx==n) {
        if (diff >= l && diff <= r && mx-mn >= x) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int ans = 0;
    ans+=f(idx+1,diff+v[idx],min(mn,v[idx]),max(mx,v[idx]));
    ans+=f(idx+1,diff,mn,mx);
    return ans;
}
int32_t main() {
    cin>>n>>l>>r>>x;
    for (int i=0;i<n;i++) {
        int d;cin>>d;
        v.push_back(d);
    }
    cout<<f(0,0,INF,-INF)<<endl;
return 0;
}
/*  .
0123456789
??????????

s.size = 10
 */