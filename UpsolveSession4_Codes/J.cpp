#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int lim = 1e9;
string mult(string s,int num) {
    string org=s;
    string ans="";
    while (num--) {
        ans+=org;
    }
    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    t=1;
    cin>>t;
    while(t--){
        string s,t;cin>>s>>t;
        if (s.size() < t.size()){swap(s,t);}
        string ans = "";
        for (int i=1;i<=20;i++) {
            string currs=mult(s,i);
            for (int j=1;j<=20;j++) {
                string currt = mult(t,j);
                if (currs == currt && (currs.size() < ans.size() || ans == "")) {
                    ans=currs;
                }
            }
        }
        cout<<(ans.empty() ? "-1" : ans)<<endl;
    }
}