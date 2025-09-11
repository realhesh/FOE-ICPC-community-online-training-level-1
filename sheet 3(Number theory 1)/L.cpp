#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
/*
 notice how if we prime factorize x,our answer is always going to be one of it's prime factors raised to some power
 however that power must be bigger than the power present in the a[i] we're computing the answer for
 so if and only if the power in a[i] is less than the power in x,we're going to consider making our answer equal to the prime factor raised to (the power in a[i]+1)
 */
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x;cin>>n>>x;
    vector<pair<int,int>> prime_factors;
    for (int i=2;i*i<=x;i++) {
        if (x%i==0) {
            int cnt=0;
            while (x%i==0){x/=i;cnt++;}
            prime_factors.push_back({i,cnt});
        }
    }
    if (x>1) {
        prime_factors.push_back({x,1});
    }
    for (int i=0;i<n;i++) {
        int a;cin>>a;
        int mini=INT64_MAX;
        for (int j=0;j<prime_factors.size();j++) {
            int cntina=0;
            int powerednum=1;
            while (a%prime_factors[j].first==0) {
                cntina++;
                powerednum*=prime_factors[j].first;
                a/=prime_factors[j].first;
            }
            if (cntina < prime_factors[j].second) {
                mini=min(mini,powerednum*=prime_factors[j].first);
            }
        }
        if (mini==INT64_MAX) {cout<<-1<<endl;}
        else{cout<<mini<<endl;}

    }
}

/*

 */