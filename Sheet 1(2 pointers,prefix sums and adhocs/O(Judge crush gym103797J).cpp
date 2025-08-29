#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    int matrix[n+2][m+2]={};
    //suppose the contestants are rows and problems are columns
    int sub;cin>>sub;
    bool accepted[n+2][m+2]={};
    while (sub--) {
        int c,p;string s;
        cin>>c>>p>>s;
        int val=1;
        if (s == "AC") {
            val=0;
            accepted[c][p]=1;
        }
        matrix[c][p]+=val;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (accepted[i][j] ==0) {
                matrix[i][j]=0; //if a problem never gets accepted then nothing counts from the wrong submissions
            }
        }
    }
    int q;cin>>q;
    int prefix[n+2][m+2]={};
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            prefix[i][j]=prefix[i-1][j]
            +prefix[i][j-1]
            -prefix[i-1][j-1]
            +matrix[i][j];
        }
    }
    while (q--) {
            int r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;
            int ans = prefix[r2][c2]
            -prefix[r2][c1-1]
            -prefix[r1-1][c2]
            +prefix[r1-1][c1-1];
            cout<<ans<<endl;
    }
    return 0;
}