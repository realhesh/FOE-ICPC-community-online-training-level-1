#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5;
const int INF = 1e18;
int32_t main() {
   //strategy is to look at each window and compute it's sum and minimize the answer
   int n,k;cin>>n>>k;
   int sum=0;
   int arr[n]={};
   int mnans=INF;
   int ansind=-1;
   for (int i=0;i<n;i++) {
      cin>>arr[i];
      if (i<k){sum+=arr[i];}
   }
   if (sum < mnans) {
      mnans=sum;
      ansind=1;
   }
   mnans=max(mnans,sum);
   for (int i=k;i<n;i++) {
      sum+=arr[i];
      sum-=arr[i-k];
      if (sum < mnans) {
         mnans=sum;
         ansind=i-k+1;
      }
   }
   cout<<ansind+1<<endl;

}