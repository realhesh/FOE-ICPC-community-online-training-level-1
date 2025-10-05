#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int lim = 1e9;
const int N = 2e5 + 5;
int lcm(int a,int b) {
    return (a*b)/__gcd(a,b);
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    //t=1;
    while (t--) {
        int a,b;cin>>a>>b;
        if (b%a == 0) {
            /*
             imagine x is some number whose prime factors are : p1 *p1 * p2 * p3 ...
             b is equal to x/p1
             a is equal to x/(p1*p1)
             b/a is equal to p1
             so x is just p1*b
             */
            int p1=b/a;
            int x=p1*b;
            cout<<x<<endl;
        }
        else {
            /*
             here x is some number : p1 * p2 * p3 ...
             b = x/p1
             a=x/p2
             that means that they're both x but with a missing prime factor, so their lcm is X
             */
            int x= lcm(a,b);
            cout<<x<<endl;
        }
    }
}
/*

 */