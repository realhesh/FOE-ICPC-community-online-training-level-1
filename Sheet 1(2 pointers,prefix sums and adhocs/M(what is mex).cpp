#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5;
const int INF = 1e18;
int freq[N + 5]={};
int32_t main() {
    int n;cin>>n;
    set<int> st;
    for (int i=0;i<=N+1;i++) {
        st.insert(i); //represents elements not in my current window
    }
    int arr[n]={};
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int l=0,r=0;
    freq[arr[0]]++;
    st.erase(arr[0]);
    int mxans=1;
    int mxmex=*st.begin();
    while (r<n-1) {
        r++;
        while(freq[arr[r]]>=1) {
            freq[arr[l]]--;
            if (freq[arr[l]]==0)
                st.insert(arr[l]);
            l++;
        }
        freq[arr[r]]++;
        st.erase(arr[r]);
        if (*st.begin() > mxmex){
            mxans=r-l+1;
            mxmex=*st.begin();
        }
        else if (*st.begin() == mxmex){
            mxans=max(mxans,r-l+1);
        }
    }
    cout<<mxans<<endl;
}
/*
 1
 4 4 2
 2 2 3 3
 4 4 4 4
 */