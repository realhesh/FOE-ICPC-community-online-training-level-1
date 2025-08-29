#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
   //just count all characters and loop over them and make sure no character occurs zero times
   int n,q;cin>>n>>q;
   int prefix[n];
   int arr[n];
   for(int i=0;i<n;i++) {
      cin>>arr[i];
   }
   prefix[0]=arr[0];
   for (int i=1;i<n;i++) {
      prefix[i]=(prefix[i-1]^arr[i]);
   }
   while (q--) {
      int l,r;cin>>l>>r;l--;r--;
      if (l==0) {
         cout<<prefix[r]<<endl;
      }
      else {
         cout<<(prefix[r]^prefix[l-1])<<endl;
      }
   }

}