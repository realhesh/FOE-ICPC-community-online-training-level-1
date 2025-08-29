#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5;
const int INF = 1e18;
int32_t main() {
    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    map<int,int> freq;
    freq[arr[0]]=1;
    int l=0,r=0;
    int ans=1;

    while (r<n-1) {
        r++;
        freq[arr[r]]++;
        while (freq[arr[r]] > 1) {
            freq[arr[l]]--;
            l++;
        }
        ans+=(r-l+1);
        /*
         strategy is to sliding window, and for every valid window we increment the answer by it's size
         we can see why this is the case through visulaization
         if,for example we have 1,2 in our window, then adding a 3 will result in adding 3 new subarrays
         which are {3},{2,3},{1,2,3}
         */
    }
    cout<<ans<<endl;
    return 0;
}