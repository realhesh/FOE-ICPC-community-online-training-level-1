#include<bits/stdc++.h>
using namespace std;

const int N = 1005;
int prefix[N][N][26]={};
int matrix[N][N][26]={};
int32_t main() {
      /*
       strategy is to make 26 2d prefix sums for each letter
       */
      int n,m;cin>>n>>m;
      for (int i=1;i<=n;i++) {
         string s;cin>>s;
         for (int j=1;j<=m;j++) {
            matrix[i][j][s[j-1]-'a']=1;
         }
      }

      for (int i=1;i<=n;i++) {
         for (int j=1;j<=m;j++) {
            for (int k=0;k<26;k++) {
               prefix[i][j][k]=prefix[i-1][j][k]
               +prefix[i][j-1][k]
               -prefix[i-1][j-1][k]
               +matrix[i][j][k];
            }
         }
      }
      int q;cin>>q;
      while (q--) {
         int r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;

         int as = prefix[r2][c2][0]
         -prefix[r2][c1-1][0]
         -prefix[r1-1][c2][0]
         +prefix[r1-1][c1-1][0];
         int cs= prefix[r2][c2]['c'-'a']
         -prefix[r2][c1-1]['c'-'a']
         -prefix[r1-1][c2]['c'-'a']
         +prefix[r1-1][c1-1]['c'-'a'];
         int es= prefix[r2][c2]['e'-'a']
         -prefix[r2][c1-1]['e'-'a']
         -prefix[r1-1][c2]['e'-'a']
         +prefix[r1-1][c1-1]['e'-'a'];
         int ans = min({as,cs,es});
         cout<<ans<<endl;
      }


}
/*
 1
 4 4 2
 2 2 3 3
 4 4 4 4
 */