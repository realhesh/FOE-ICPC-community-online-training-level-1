#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
   string s;cin>>s;
    int sz=s.size();
    int arr[sz]={};
    for (int i=0;i<sz;i++) {
        if (i+1 < sz && s[i] == s[i+1]) {
            arr[i]=1;
        }
        else{arr[i]=0;}
    }
    int prefix[sz]={};
    prefix[0]=arr[0];
    for (int i=1;i<sz;i++) {
        prefix[i]=prefix[i-1]+arr[i];
    }
    int q;cin>>q;
    while (q--) {
        int l,r;cin>>l>>r;l--;r--;
        if (l==0) {
            cout<<prefix[r-1]<<endl; //this is done because even if the last element in my range has the next character equal to it, it isn't counted
        }
        else {
            cout<<prefix[r-1]-prefix[l-1]<<endl;
        }
    }
    return 0;
}