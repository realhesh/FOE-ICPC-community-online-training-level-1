#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
const int N = 1e5 + 5;
vector<int> divi[N];
int32_t main() {
    //different query numbers are 10^5 but test cases are 10^6, so precompute divisors at first to save time
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for (int i=1;i<N;i++) {
        for (int j=1;j*j<=i;j++) {
            if (i%j ==0) {
                divi[i].push_back(j);
                if (i/j != j){divi[i].push_back(i/j);}
            }
        }
        sort(divi[i].begin(), divi[i].end());
    }
    int t;cin>>t;
    while (t--) {
        int n;cin>>n;
        for (auto i : divi[n]) {
            cout<<i<<' ';
        }cout<<endl;
    }
}