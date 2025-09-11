#include<bits/stdc++.h>
using namespace std;
#define int long long
/*
 it is always better to subtract 1,2,3.. and so on, and thus we try to do that till we can no longer subtract
 you might wonder, if we're talking about 5 ,and we try doing that
 we will end up subtracting 1,then 2 but then we can't subtract three, but that still means we can only subtract two numbers
 we just subtract 1 first then a number bigger than 2 then
 */
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<int> primes;
    for (int i=2;i*i<=n;i++) {
        int cnt=0;
        while (n%i==0) {
            cnt++;
            n/=i;
        }
        if (cnt!=0){primes.push_back(cnt);}
    }
    int ans=0;
    if (n != 1){primes.push_back(1);}
    for (auto i : primes) {
        int thing=i;
        for (int j=1;j<=i;j++) {
            if (thing-j >=0) {
                thing-=j;
                ans++;
            }
        }
    }
    cout<<ans;

}

/*

*/