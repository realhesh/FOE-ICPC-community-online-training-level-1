#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n;cin>>n;
    int na;cin>>na;
    set<int> st;
    for (int i=0;i<na;i++) {
        int x;cin>>x;st.insert(x);
    }
    int nb;cin>>nb;
    for (int i=0;i<nb;i++) {
        int x;cin>>x;st.insert(x);
    }
    if (st.size() == n) {
        cout<<"I become the guy.";
    }
    else {
        cout<<"Oh, my keyboard!";
    }
    return 0;
}