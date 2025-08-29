#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int n,q;cin>>n>>q;
    int p[n];
    for (int i=0;i<n;i++) {
        cin>>p[i];
    }//strategy is to target largest x elements and you'll profity from cheapest y
    //this if,if you make prefix sum, then your answer is the sums of the first x elements, and subtract from it the number of non free items.
    sort(p,p+n);
    reverse(p,p+n);
    int prefix[n]={};
    prefix[0]=p[0];
    for (int i=1;i<n;i++) {
        prefix[i]=prefix[i-1]+p[i];
    }
    while (q--) {
        int x,y;cin>>x>>y;
        int notfree=x-y;
        x--;
        if (notfree==0) {
            cout<<prefix[x]<<endl;
        }
        else {
            cout<<prefix[x]-prefix[notfree-1]<<endl;
        }
    }
    return 0;
}