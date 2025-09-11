#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 +8;
/*
 n and m are small enough so we can loop over each row and try to make it primes and try each column
 we can quickly get how many increases we need to do for an element to reach next element by lower_bounding on it on a primes vector
 */
vector <bool> isprime(N+1, true);
vector <int> primes;

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
    int n,m;cin>>n>>m;
    int grid[n][m];
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin>>grid[i][j];
        }
    }
    //trying to convert rows
    int mn = INT64_MAX;
    for (int i=0;i<n;i++){
        int curans=0;
        for (int j=0;j<m;j++) {
            int closest_number=*lower_bound(primes.begin(),primes.end(),grid[i][j]);
            curans+=(closest_number - grid[i][j]);
        }
        mn=min(mn,curans);
    }
    //now columns
    for (int j=0;j<m;j++) {
        int curans=0;
        for (int i=0;i<n;i++) {
            int closest_number=*lower_bound(primes.begin(),primes.end(),grid[i][j]);
            curans+=(closest_number - grid[i][j]);
        }
        mn=min(mn,curans);
    }
    cout<<mn<<endl;

}

/*

 */