#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 +8;
int freq[N]={};
int indicator[N]={};
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int arr[n];
    for (int i=0;i<n;i++) {
        cin>>arr[i];
        freq[arr[i]]++;
    }
    int ans=0;
    for (int i=1;i<N;i++) {
        if (freq[i]) {
            for (int j=i*2;j<N;j+=i) {
                indicator[j]=1;
            }
        }
    }
    for (int i=0;i<n;i++) {
        if (!(freq[arr[i]] > 1 || indicator[arr[i]] ==1)) {
            ans++;
        }
    }
    cout<<ans<<endl;

}

/*

 */