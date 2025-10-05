#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int mod = 1000000007;
const int N = 1e7+5;

vector <int> spf(N + 1);
vector<int> primes;
int mul(int a, int b) {
    return (a%mod * b%mod)%mod;
}
int fast_power(int base, int power) {
    int res = 1;
    while (power>0) {
        if (power&1) res = mul(res, base);
        base=mul(base, base);
        power/=2;
    }
    return res;
}
void sieve()
{
    for ( int i = 2 ; i <= N ; i++ )
    {
        if ( spf[i] == 0 )
        {
            spf[i] = i;
            primes.push_back(i);
        }

        for ( int j = 0 ; j < primes.size() && primes[j] <= spf[i] && i * primes[j] <= N ; j++ )
        {
            spf[ i * primes[j] ] = primes[j];
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    sieve();
    //idea to prime factorize all numbers and store the count of every prime factor across all numbers
    //if you have n of a prime factor and m of another prime factor
    //the number of unique factors is equal to (n+1)*(m+1)
    int n;cin>>n;
    map<int,int> cnt;
    while (n--) {
        int x;cin>>x;
        while (x>1) {
            cnt[spf[x]]++;
            x/=spf[x];
        }
    }
    int tot=1;
    for (auto i : cnt) {
        tot=mul(tot,i.second+1ll);
    }
    cout<<tot<<endl;
}