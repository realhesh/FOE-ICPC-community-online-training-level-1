#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int sum(int n) {
    int ans=0;
    while (n>0) {
        ans+=(n%10);
        n/=10;
    }
    return ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while (t--) {
        int x,k;cin>>x>>k;
        /*
         the key of the solution is that K is only 10
         therefore if we have 10 numbers that only differ in one integer, then we must go over a number whose digits sum is divisible by k
         and we only need to go over 18 numbers at most to over 10 numbers that differ in one integer,
         best case scenario is that i start with a number whose last digits equals 0, then i will just go over the numbers whose last digit equals zero till last digit equals 9
         worse case scenario is that i start with a number whose last digits equals 1,then i need to make it's last digit equal zero then i am back at the best case sceanrio, and this is where i need to go over 18 numbers
         */
        for (int y=x;y<=x+18;y++) {
            if (sum(y)%k==0) {
                cout<<y<<endl;break;
            }
        }
    }
}

/*

 */