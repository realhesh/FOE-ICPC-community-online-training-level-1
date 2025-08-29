#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    /* strategy is to always go left or right, i am going right i'll reverse the array for simplicity
     when working, put the fall damage at the destination for every jump and prefix sum on those
     */
    int n,m;cin>>n>>m;
    int arr[n],arr2[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        arr2[i]=arr[i];
    }
    int damageR[n]={};
    int damageL[n]={};
    for (int i=1;i<n;i++) {
        if (arr[i] < arr[i-1]){
            damageR[i]=abs(arr[i-1]-arr[i]);
        }
    }
    reverse(arr2,arr2+n);
    for (int i=1;i<n;i++) {
        if (arr2[i] < arr2[i-1]){
            damageL[i]=abs(arr2[i-1]-arr2[i]);
        }
    }
    int prefixR[n]={};
    prefixR[0]=damageR[0];
    for (int i=1;i<n;i++) {
        prefixR[i]=prefixR[i-1]+damageR[i];
    }
    int prefixL[n]={};
    prefixL[0]=damageL[0];
    for (int i=1;i<n;i++) {
        prefixL[i]=prefixL[i-1]+damageL[i];
    }
    while (m--) {
        int l,r;cin>>l>>r;
        l--;r--;
        if (l > r) {
            l=n-1-l;
            r=n-1-r;
            if (l==0){cout<<prefixL[r]-damageL[l]<<endl;}
            else {cout<<prefixL[r] -prefixL[l]<<endl;}
        }
        else {
            if (l==0){cout<<prefixR[r]-damageR[l]<<endl;}
            else {cout<<prefixR[r] -prefixR[l]<<endl;}
        }
        }
    return 0;
}