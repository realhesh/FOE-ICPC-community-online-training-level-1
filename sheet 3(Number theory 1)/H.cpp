#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
const int N = 2e6 +5;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;int cnt=0;
        for(int j=1;j*j<=x;j++){
            if(x%j==0){
                int o = x/j;
                if(j==o){
                    cnt++;
                }
                else{cnt+=2;}
            }
        }
        cout<<cnt<<endl;
    }
}
