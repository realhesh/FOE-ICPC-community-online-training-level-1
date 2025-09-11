#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 +8;
int freq[N]={};
int indicator[N]={};
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int color[n+5]={};
    int isprime[n+5]={};
    int used=0;
    for (int i=2;i<=n+1;i++) {
        if (color[i] ==0) {
            color[i]=1;if (used==0){used=1;}
            for (int j=i*2;j<=n+1;j+=i) {
                color[j]=2;
                if (used != 2){used=2;}
            }
        }
    }
    cout<<used<<endl;
    for (int i=2;i<=n+1;i++) {
        cout<<color[i]<<' ';
    }

}

/*

 */