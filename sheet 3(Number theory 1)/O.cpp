#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 +8;
/*
 this problem also depends on GoldBach's conjecture
 which states that any even number can be made into two prime numbers

 so at first, if our n is prime already, our answer is 1
 if our n is an even number, then according to goldbach, the answer is 2
 if our n is odd, we have two possibilities
 since n is odd then it is composed of = even + odd , or odd+odd+odd
 if its even + odd the even part must be 2 since 2 is the only prime number, so we just check if the odd part is prime and if it's prime then our answer is 2
 else our answer is 3 since after getting the first odd part in the three odd parts the remaining part would be positive and it can again be distributed into two primes
 */
bool prime_check(int x) {
    if (x<=1){return false;}
    for (int j=2;j*j<=x;j++) {
        if (x%j==0){return false;}
    }
    return true;
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    if (prime_check(n)) {
        cout<<1<<endl;
    }
    else if (n%2==0 || prime_check(n-2)) {
        cout<<2<<endl;
    }
    else {

        cout<<3<<endl;
    }
}

/*

 */