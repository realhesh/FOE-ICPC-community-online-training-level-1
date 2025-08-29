#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n,q;cin>>n>>q;
    int matrix[n+1][n+1]={};
    for (int i=1;i<=n;i++){
        string s;cin>>s;
        for (int j=0;j<s.size();j++){
            char x=s[j];
            if (x=='.') {
                matrix[i][j+1]=0;
            }
            else {
                matrix[i][j+1]=1;
            }
        }
    }
    int prefix[n+1][n+1]={};
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
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