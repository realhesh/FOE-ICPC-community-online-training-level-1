#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
int spf[N];
int prfx[11][N]={};
/*
 the key is noticing how you can easily compute the answer for a single testcase by just looping over the numbers from a to b and factorizing them
 but the problem is that there're many testcases, and doing this for every test case would lead to a time limit
 so to avoid that, we can make a prefix sum that counts for every n, how many numbers between a and b are n-factorful
 to calculate that we can loop over all possible numbers and figure out how many distinct divisors each number has
 once we have counted that, we can say that each value[n][i] equals to 1 if the i is n factorful
 if we make a prefix sum over this value[n] array, we can answer how many numbers are n factorful between a and b
 */
void SPF() {
    for (int i=1;i<N;i++) {
        spf[i]=i;
    }
    for (int i=2;i*i<N;i++) {
        if (spf[i]==i) {
            for (int k=i*i;k<N;k+=i) {
                if (spf[k]==k) {
                    spf[k]=i;
                }
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    SPF();
    for (int i=1;i<N;i++) {
            int curr=i;
            int cnt=0;
            while (curr > 1) {
                cnt++;
                int currprime=spf[curr];
                while (curr%currprime ==0) {
                    curr/=currprime;
                }
            }
            prfx[cnt][i]=1; //1
        }
    for (int n=0;n<=10;n++) {
        for (int i=1;i<N;i++) {
            prfx[n][i] = prfx[n][i] + prfx[n][i-1];
        }
    }
    while (t--) {
        int a,b,n;cin>>a>>b>>n;
        int ans = prfx[n][b]-prfx[n][a-1];
        cout<<ans<<endl;
    }
}

/*

 */