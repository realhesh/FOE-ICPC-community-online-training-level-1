#include<bits/stdc++.h>
using namespace std;
#define int long long
//the idea is that, if the number is even, then we will only keep subtracting by 2
//if it's not even, then only after one subtraction of the smallest prime factor(which is guranteed to be odd), it'll become even
//that's since odd-odd = even
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int org=n;
    vector<int> primefactor;
    for (int j=2;j*j<=n;j++) {
        if (n%j==0) {
            primefactor.push_back(j);
            while (n%j==0) {
                n/=j;
            }
        }
    }

    if (n>1){primefactor.push_back(n);}
    sort(primefactor.begin(),primefactor.end());
    int ans=1+((org-primefactor[0])/2);
    cout<<ans<<endl;
}

/*

 */