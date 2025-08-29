#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    /*
    strategy is to put a stamp whenever you can and count the number of stamps on a point
     */
    int n,m;cin>>n>>m;
    int h,w;cin>>h>>w;
    int matrix[n+5][m+5]={};
    int stamps[n+5][m+5]={};
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin>>matrix[i][j];
        }
    }
    int prefixones[n+5][m+5]={};
    int prefixstamps[n+5][m+5]={};
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            prefixones[i][j]=prefixones[i-1][j]
            +prefixones[i][j-1]
            -prefixones[i-1][j-1]
            +matrix[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (matrix[i][j]==0) {
                int r1=i,c1=j,r2=i+h-1,c2=j+w-1;
                if (r2 <= n && c2 <=m) {
                    int ones= prefixones[r2][c2]
                    -prefixones[r2][c1-1]
                    -prefixones[r1-1][c2]
                    +prefixones[r1-1][c1-1];
                    if (ones==0) {
                        stamps[r1][c1]++;
                        stamps[r2+1][c2+1]++;
                        stamps[r2+1][c1]--;
                        stamps[r1][c2+1]--;
                    }
                }
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            prefixstamps[i][j]=prefixstamps[i-1][j]
            +prefixstamps[i][j-1]
            -prefixstamps[i-1][j-1]
            +stamps[i][j];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (prefixstamps[i][j] <=0 && matrix[i][j]==0) {
                cout<<"NO"<<endl;return 0;
            }
        }
    }
    cout<<"YES"<<endl;return 0;
    return 0;
}