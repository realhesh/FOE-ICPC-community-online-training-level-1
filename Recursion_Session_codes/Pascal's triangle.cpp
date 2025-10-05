#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int r,int c){
    if (c==0 || c==r) {
        return 1;
    }
    return f(r-1,c) + f(r-1,c-1);
}
int32_t main() {
    int r,c;cin>>r>>c;
    cout<<f(r,c);
    return 0;
}