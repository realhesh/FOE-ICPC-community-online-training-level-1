#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;cin>>t;
    while (t--) {
        int a,b;cin>>a>>b;
        int ans = b-(a%b); // this calculates how much you need to add until you become divisible
        //except if a is already divisibe, the value calculated is b, so i take mod b again when outputting
        cout<<ans%b<<endl;
    }
}