#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 1e7 + 4;
int spf[N];
void SPF() {
    for (int i=1;i<N;i++) {
        spf[i]=i;
    }
    for (int i=2;i*i<N;i++) {
        if (spf[i]==i) {
            for (int k=i*i;k<N;k+=i) {
                if (spf[k]==k) {
                    spf[k]=i;
                }
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    SPF();
    while (t--) {
        int n;cin>>n;
        int oddnum=0,evennum=0;
        while (n>1) {
            int currfactor=spf[n];
            int cnt=0;
            while (n%currfactor==0) {
                n/=currfactor;
                cnt++;
            }
            if (cnt%2==1){oddnum++;}
            if (cnt%2==0){evennum++;}
        }
        if (evennum > oddnum){cout<<"Psycho Number"<<endl;}
        else{cout<<"Ordinary Number"<<endl;}
    }
}

/*

 */