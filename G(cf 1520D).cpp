#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
   int t;cin>>t;
   while (t--) {
      //a[j] - a[i] = j-i;
      //that is, a[j] - j = a[i] - i
      //then we can count each a[i]-i and see how many pairs we can make
      int n;cin>>n;
      int arr[n];
      map<int,int> freq;
      for (int i = 0; i < n; i++) {
         cin>>arr[i];
         freq[arr[i]-(i+1)]++;
      }
      int ans=0;
      for (auto i : freq) {
         int occ=i.second;
         ans+=((occ*(occ-1))/2);
      }
      cout<<ans<<endl;
   }

}
