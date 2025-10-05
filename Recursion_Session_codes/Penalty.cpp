#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e9;
string s;
int f(int idx,int g1,int g2) {
    int rem=s.size()-idx;
    int rem1,rem2;
    //0123
    //????
    if (rem%2==0) {
        rem1=rem/2;
        rem2=rem/2;
    }
    else{
        rem1 = (rem/2);
        rem2=(rem/2)+1;
    }
    if ((g2 + rem2 < g1 )||(g1 + rem1 < g2)){
        return idx;
    }
    else if (idx==s.size()) {
        return idx;
    }
    int ans=INF;
    if (idx%2==0){
        if (s[idx] == '0') {
            ans=f(idx+1,g1,g2);
        }
        else if (s[idx] == '1') {
            ans=f(idx+1,g1+1,g2);
        }
        else {
            ans=min(f(idx+1 ,g1+1,g2),f(idx+1,g1,g2));
        }
    }
    else {
        if (s[idx] == '0') {
            ans=f(idx+1,g1,g2);
        }
        else if (s[idx] == '1') {
            ans=f(idx+1,g1,g2+1);
        }
        else {
            ans=min(f(idx+1 ,g1,g2+1),f(idx+1,g1,g2));
        }
    }
    return ans;
}
int32_t main() {
    int t;cin>>t;
    while (t--) {
        cin>>s;
        cout<<f(0,0,0)<<endl;
    }
    return 0;
}
/*  .
0123456789
??????????

s.size = 10
 */