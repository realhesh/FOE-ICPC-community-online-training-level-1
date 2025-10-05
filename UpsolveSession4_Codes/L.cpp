#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int lim = 1e9;
const int N = 2e5 + 5;
vector <int> spf(N + 1);
vector<int> primes;
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
    //t=1;
    sieve();
    cin>>t;
    while(t--){
        int n;cin>>n;
        int almost_prime_with[N]={};
        //almost_prime_with[2] = 1
        int count_element[N]={};
        bool is_prime[N]={};
        bool is_almost_prime[N]={};
        vector<int> v(n);
        int primes=0;
        int almost_primes=0;

        for (int i=0;i<n;i++) {
            cin>>v[i];
            count_element[v[i]]++;
            int tmp=v[i];
            vector<int> prime_factors;
            int cur=2;
            int totcnt=0;
            while (tmp > 1) {
                int cnt=0;
                int cur = spf[tmp];
                while (tmp%cur==0) {
                    tmp/=cur;
                    cnt++;
                }
                prime_factors.push_back(cur);
                totcnt+=cnt;
            }
            if (totcnt==1) {
                primes++;
                is_prime[i]=1;
            }
            else if (totcnt==2) {
                almost_primes++;
                almost_prime_with[prime_factors[0]]++;
                /*
                 4 : 2*2
                 6 : 2*3

                 */
                if (prime_factors.size() == 2) {
                    almost_prime_with[prime_factors[1]]++;
                }
                is_almost_prime[i]=1;
            }
        }
        long long ans = (primes*(primes-1)/2ll)+almost_primes;
        bool handled_primes_subt[N]={};
        bool handled_almost_primes_add[N]={};
        for (int i=0;i<n;i++) {
            if (is_prime[i] ==1) {
                ans+=almost_prime_with[v[i]];
                if (handled_primes_subt[v[i]]==0) {
                    handled_primes_subt[v[i]]=1;
                    ans-=((count_element[v[i]] *(count_element[v[i]]-1))/2ll);
                }
            }
            if (is_almost_prime[i]==1 && handled_almost_primes_add[v[i]]==0) {
                handled_almost_primes_add[v[i]]=1;
                ans+=((count_element[v[i]]*(count_element[v[i]]-1))/2ll);
            }

        }
    cout<<ans<<endl;
    }
}