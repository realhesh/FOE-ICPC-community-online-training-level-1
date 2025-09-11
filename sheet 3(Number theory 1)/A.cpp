#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //just factorize the number in O(sqrt(n)) and sort the factors in a vector and output the kth factor
    int n,k;cin>>n>>k;
    vector<int> div;
    for (int i=1;i*i<=n;i++) {
        if (n%i==0) {
            div.push_back(i);
            if (n/i != i){div.push_back(n/i);}
        }
    }
    sort(div.begin(),div.end());
    if (k > div.size()) {
        cout<<-1<<endl;
    }
    else {
        cout<<div[k-1];
    }
}