#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //simply loop over all possible numbers, and check if they are almost prime by prime factorizing them
    //total complexity would be O(n * sqrt(n));
    int n;cin>>n;
    int cnt=0;
    for (int i=1;i<=n;i++) {
        set<int> st;
        int tmp=i;
        for (int j=2;j*j<=tmp;j++) {
            if (tmp%j==0) {
                while (tmp%j==0) {
                    tmp/=j;
                    st.insert(j);
                }
            }
        }
        if (tmp > 1) {
            st.insert(tmp);
        }
        if (st.size()==2) {
            cnt++;
        }
    }
    cout<<cnt;

}