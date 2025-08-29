#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5;
const int INF = 1e18;
int32_t main() {
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int currsum=arr[0];
    int ans=-INF;
    ans=max(ans,currsum);
    for (int i=1;i<n;i++) {
        //my strategy is, keep taking elements as long as it's "beneficial"
        //it stops being beneficial if my accumulated sum is now negative,
        //that is because i can just abandon the previous elements and start with a zero instead
        ans=max(ans,currsum);
        if (currsum<0){currsum=arr[i];}
        else {
            currsum+=arr[i];
        }
        ans=max(ans,currsum);
    }
    cout<<ans<<endl;
    return 0;
}