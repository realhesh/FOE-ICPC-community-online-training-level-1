#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5;
const int INF = 1e18;
int32_t main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    map<int,int> freq;
    freq[arr[0]]=1;
    int l=0,r=0;
    set<int> st;
    st.insert(arr[0]);
    int ans=1;
    while (r<n-1) {
        r++;
        freq[arr[r]]++;
        st.insert(arr[r]);
        while (st.size() > k) {
            freq[arr[l]]--;
            if (freq[arr[l]]==0){st.erase(arr[l]);}
            l++;
        }
        ans+=(r-l+1);
        /*
            strategy is very similar to previous problem, i just move the window according to
            number of distinct elements i have
         */
    }
    cout<<ans<<endl;
    return 0;
}