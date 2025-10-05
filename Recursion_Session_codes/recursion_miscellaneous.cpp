#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int> v;
int fast_power(int base,int pow) {
    if (pow==0) {
        return 1;
    }
    int curr=fast_power(base,pow/2);
    if (pow%2==0) {
        return curr*curr;
    }
    else {
        return curr*curr*base;
    }
}
int prefix(int r) {
    if (r==-1) {
        return 0;
    }
    return v[r] + prefix(r-1);
}
int fact(int n) {
    if (n==1){return 1;}
    return n * fact(n-1);
}
void print(int i) { // from i till 5 right exclusive
    if (i == 5) {
        return;
    }
    cout<<i<<' ';
    print(i+1);
}
int32_t main() {
    print(2);
     cin>>n;
    for (int i=0;i<n;i++) {
        int x;cin>>x;v.push_back(x);
    }
    int r;cin>>r;
    cout<<prefix(r);
    return 0;
}