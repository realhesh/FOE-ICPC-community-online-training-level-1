#include<bits/stdc++.h>
using namespace std;
#define int long long
string curr;
string s;
vector<string> ans;
void rec(int idx) {
    if (idx==s.size()) {
        ans.push_back(curr);
        return;
    }
    curr+=s[idx];
    rec(idx+1);
    curr.pop_back();
    rec(idx+1);
    return;
}
int32_t main() {
    cin>>s;
    rec(0);
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for (auto i : ans) {
        cout<<i<<endl;
    }
    return 0;
}