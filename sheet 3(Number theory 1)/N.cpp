#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 +8;
/*
 */
vector <bool> isprime(N+1, true);
vector <int> primes;
bool prime_check(int x) {
    if (x<=1){return false;}
    for (int j=2;j*j<=x;j++) {
        if (x%j==0){return false;}
    }
    return true;
}
void sieve()
{
    for (int i = 2 ; i <= N ; i++ )
    {
        for (int j = 2 * i ; j <= N ; j += i )
        {
            isprime[j] = false;
        }
        if ( isprime[i] ) primes.push_back(i);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    sieve();
    int n;
    cin>>n;
    if (prime_check(n)){cout<<1<<endl<<n;}
    else if (n%2==0) {
        for (auto i : primes) {
            if (prime_check(n-i)) {
                cout<<2<<endl<<i<<' '<<n-i<<endl;break;
            }
        }
    }
    else {
        for (auto i : primes) {
            if (prime_check(n-3-i)) {
                cout<<3<<endl<<3<<' '<<i<<' '<<n-3-i<<endl;break;
            }
        }
    }

}

/*

 */