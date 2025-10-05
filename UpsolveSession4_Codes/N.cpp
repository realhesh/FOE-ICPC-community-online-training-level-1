#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int lim = 1e9;
const int N = 2e5 + 5;
vector <int> spf(N + 1);
vector<int> primes;
int mul(int a,int b) {
    return a*b;
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
    int t;
    t=1;
    sieve();
    //cin>>t;
    while(t--){
        int n;cin>>n;
        map<int,vector<int>> primes;
        for (int i=0;i<n;i++) {
            int x;cin>>x;
            int tmp=x;
            while (tmp>1) {
                int cur=spf[tmp];
                int cnt=0;
                while (tmp%cur==0) {
                    tmp/=cur;
                    cnt++;
                }
                primes[cur].push_back(cnt);
            }

        }
        int ans=1;
        for (auto i : primes) {
            sort(i.second.begin(),i.second.end());
            if (i.second.size() == n)
                ans*=(fast_power(i.first,i.second[1]));//prime^(scnd_smallest_power)
            else if (i.second.size() ==n-1)
                ans*=(fast_power(i.first,i.second[0]));
            else {
                //i don't need to do anything
            }
        }
        cout<<ans<<endl;
    }
}