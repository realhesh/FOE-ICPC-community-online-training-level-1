#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
   //just a sliding window
   int n;cin>>n;
   map<int,int> freq;
   int mxans=1;
   int arr[n];
   for (int i=0;i<n;i++) {
      cin>>arr[i];
   }
   int l=0,r=0;
   freq[arr[l]]++;
   while (r<n-1) {
      r++;
      freq[arr[r]]++;
      while(freq[arr[r]]>1) {
         freq[arr[l]]--;
         l++;
      }
      mxans=max(mxans,r-l+1);
   }
cout<<mxans<<endl;
}