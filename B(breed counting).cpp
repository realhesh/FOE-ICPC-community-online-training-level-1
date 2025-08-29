#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5;
const int INF = 1e18;
int32_t main() {
   int n,q;cin>>n>>q;
    //simply make 3 prefix sums and assume arr[i][cow] equals one if a breed of that cow exists in this place
    int arr[n][3]={};
    for (int i=0;i<n;i++) {
        int x;cin>>x;x--;
        arr[i][x]=1;
    }
    int prefix[n][3]={};
    prefix[0][0]=arr[0][0];
    prefix[0][1]=arr[0][1];
    prefix[0][2]=arr[0][2];
    for (int i=1;i<n;i++) {
        for (int j=0;j<3;j++) {
            prefix[i][j]=prefix[i-1][j]+arr[i][j];
        }
    }
    while (q--) {
        int l,r;cin>>l>>r;l--;r--;
        if (l==0) {
            cout<<prefix[r][0]<<' '<<prefix[r][1]<<' '<<prefix[r][2]<<endl;
        }
        else {
            cout<<prefix[r][0] - prefix[l-1][0]<<' '<<prefix[r][1]-prefix[l-1][1]<<' '<<prefix[r][2]-prefix[l-1][2]<<endl;
        }
    }

    return 0;
}