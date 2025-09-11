#include<bits/stdc++.h>
using namespace std;
#define int long long
//the idea is to try dividing by all primes till sqrt, then if the remaining number is larger than one, the remaining number must be a prime factor too
const int N = sqrt(1e9) + 4;
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
    vector<int> primes;
    for (int i=2;i<N;i++) {
        if (spf[i]==i){primes.push_back(i);}
    }
    while (t--) {
        int n;cin>>n;
        vector<int> v(n);
        map<int,int> seen;
        bool y=0;
        for (int i=0;i<n;i++) {
            cin>>v[i];
            if (y==0) {
                for (auto j : primes) {
                    if (spf[j]==j) {
                        if (v[i]%j==0) {
                            seen[j]++;
                            if (seen[j] ==2){y=1;}
                        }
                        while (v[i] % j ==0) {
                            v[i]/=j;
                        }
                    }
                }
                if (v[i] > 1) {
                    seen[v[i]]++;
                    if (seen[v[i]] ==2){y=1;}
                }
            }
        }

        if (y==0){cout<<"NO"<<endl;}
        else{cout<<"YES"<<endl;}
    }
}

/*

 */