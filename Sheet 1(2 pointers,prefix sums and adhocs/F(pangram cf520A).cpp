#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
   //just count all characters and loop over them and make sure no character occurs zero times
   int n;cin>>n;
   string s;cin>>s;
   map<char,int> freq;
   for(int i=0;i<s.size();i++) {
      freq[tolower(s[i])]++;
   }
   bool yes=1;
   for (char i = 'a' ;i<='z';i++) {
      if (freq[i]==0){yes=0;break;}
   }
   if (yes) {
      cout<<"YES"<<endl;
   }
   else {
      cout<<"NO"<<endl;
   }
}