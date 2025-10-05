#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n];
        int mxind[1005]={};
        for(int i=0;i<n;i++){cin>>arr[i];mxind[arr[i]]=i+1;}
        int mxans=-1;

        for(int i=1;i<=1000;i++){
            for(int j=1;j<=1000;j++){
                if(mxind[i] != 0 && mxind[j] != 0 && __gcd(i,j) ==1){
                    mxans=max(mxans,mxind[i]+mxind[j]);
                }
            }
        }
        cout<<mxans<<endl;
    }
}