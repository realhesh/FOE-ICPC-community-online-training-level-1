#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;
int32_t main() {
    int n,q;cin>>n>>q;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    set<int> st;
    int ans[n+1]={};
    for (int i=n-1;i>=0;i--) {
        st.insert(arr[i]);
        ans[i+1]=st.size();
    }
    while (q--) {
        int x;cin>>x;
        cout<<ans[x]<<endl;
    }

}
/*
 1
 4 4 2
 2 2 3 3
 4 4 4 4
 */