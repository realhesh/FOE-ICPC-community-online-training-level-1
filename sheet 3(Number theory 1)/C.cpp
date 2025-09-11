#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    /*
     for this problem, we notice that the only case where the number is t prime is if it is a perfect square
     and it's square root is a prime
     this is because if the number isn't a perfect square, then it's either prime or composed of 4 factors or more
     and if it's square root isn't prime, then it can still consist of more than 3 primes(try to notice why 100 is not a t prime for example)
     */
    int n;cin>>n;
    for (int i=0;i<n;i++) {
        int x;cin>>x;
        int o=sqrt(x);// a way of checking if the number is a perfect square, get it's sqrt and multiply it by itself and see if it gives the original number
        int isprime=1;
        for (int j=2;j*j<=o;j++) {
            if (o%j ==0){isprime=0;}
        }
        if (o*o ==x && x!=1 && isprime) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }

}

/*

 */