#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int counter[N]={};
//the idea is to divide all prime factors present in the array equally among all elements, so i just count each occurence of them
//and check if it's divisible by n to know if i can distribute it
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while (t--) {
        int n;cin>>n;
        set<int> primes;
        memset(counter,0,sizeof(counter));
        for (int i=0;i<n;i++) {
            int x;cin>>x;
            for (int j=2;j*j<=x;j++) {
                if (x%j==0) {
                    primes.insert(j);
                    int cnt=0;
                    while (x%j==0) {x/=j;cnt++;}
                    counter[j]+=cnt;
                }
            }
            if (x>1){counter[x]++;primes.insert(x);}
        }
        bool y=1;
        for (auto i : primes) {
            if (counter[i]%n !=0){y=0;}
        }
        if (y==0){cout<<"NO"<<endl;}
        else{cout<<"YES"<<endl;}
    }
}

/*

 */