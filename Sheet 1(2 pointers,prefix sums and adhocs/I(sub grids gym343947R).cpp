#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
   int t;cin>>t;
   while (t--) {
      int w,h,n;cin>>w>>h>>n;
      int matrix[h+2][w+2]={};

      for (int i=0;i<n;i++) {
         int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
         if (x1 > x2) swap(x1, x2);
         if (y1 > y2) swap(y1, y2);
         //when i prefix sum
         matrix[y1][x1]++;
         matrix[y2+1][x1]--;
         matrix[y1][x2+1]--;
         matrix[y2+1][x2+1]++;


      }
      int prefix[h+2][w+2]={};
      for (int i=1;i<=h;i++) {
         for (int j=1;j<=w;j++) {
            prefix[i][j]=prefix[i-1][j]
            +prefix[i][j-1]
            -prefix[i-1][j-1]
            +matrix[i][j];
         }
      }
      int ans=0;
      for (int i=1;i<=h;i++) {
         for (int j=1;j<=w;j++) {
            //cout<<i<<' '<<j<<' '<<matrix[i][j]<<' '<<prefix[i][j]<<endl;
            if (prefix[i][j] == 0){ans++;}
         }
      }
      cout<<ans<<endl;

   }
}
/*
 1
 4 4 2
 2 2 3 3
 4 4 4 4
 */