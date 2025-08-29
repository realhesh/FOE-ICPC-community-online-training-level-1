#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
   int n,sum;cin>>n>>sum;
   int arr[n];
   map<int,vector<int>> indices;
   for (int i=0;i<n;i++) {
      cin>>arr[i];
      indices[arr[i]].push_back(i+1);
   }
   int ind1=-1,ind2=-1;
   for (int i=0;i<n;i++) {
      /*
       arr[i]+arr[j] = sum;
       we can bruteforce on arr[i] and check for existence of arr[j]
       that's because arr[j] = sum-arr[i]
       */
      int stillneed=sum-arr[i];
      if (stillneed == arr[i]){
         if (indices[arr[i]].size()>=2) {
            ind1=indices[arr[i]][0];
            ind2=indices[arr[i]][1];
         }
      }
      else if (indices[stillneed].size()!=0){
         ind1=i+1;
         ind2=indices[stillneed][0];
      }
   }
   if (ind1 == -1 || ind2==-1) {
      cout<<"IMPOSSIBLE"<<endl;
   }
   else {
      cout<<ind1<<' '<<ind2<<endl;
   }

}
