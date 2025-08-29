#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int t;cin>>t;
    while (t--) {
        int n;cin>>n;
        int arr[n],revarr[n];
        for (int i=0;i<n;i++) {
            cin>>arr[i];
            revarr[i]=arr[i];
        }
        /*
         */
        reverse(revarr,revarr+n);
        int mxans=0;
        int prefix[n],revprefix[n];
        prefix[0]=arr[0];revprefix[0]=revarr[0];
            map<int,int> idx;
            map<int,int> seen;
            idx[revprefix[0]]=0;
            seen[revprefix[0]]=1;
        for (int i=1;i<n;i++) {
            prefix[i]=prefix[i-1]+arr[i];
            revprefix[i]=revprefix[i-1]+revarr[i];
            idx[revprefix[i]]=i;
            seen[revprefix[i]]=1;
        }
        int ans=0;
        for (int i=0;i<n;i++) {
            int numa=i+1;
            if (seen[prefix[i]] ==1) {
                int numb=idx[prefix[i]]+1;
                if (numa+numb <= n){
                    ans=max(ans,numa+numb);
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}