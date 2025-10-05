#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<string> g;
int n,m;
/*
 sample :
4 4
....
....
.#.#
#...
 */
string cur;
void print_paths(int r,int c) {
    if (r==n-1 && c==m-1) {
        cout<<cur<<endl;
        return;
    }
    if (r+1 < n && g[r+1][c] != '#') {
        cur+='D';
        print_paths(r+1,c);
        cur.pop_back();
    }
    if (c+1<m && g[r][c+1] != '#') {
        cur+='R';
        print_paths(r,c+1);
        cur.pop_back();
    }
}
int count_paths(int r,int c) {
    if (r==n-1 && c==m-1) {
        return 1;
    }
    int ans=0;
    if (r+1 < n && g[r+1][c] != '#') {
        ans+=count_paths(r+1,c);
    }
    if (c+1<m && g[r][c+1] != '#') {
        ans+=count_paths(r,c+1);
    }
    return ans;
}
int32_t main() {
    cin>>n>>m;
    for (int i=0;i<n;i++) {
        string s;cin>>s;
        g.push_back(s);
    }
    cout<<count_paths(0,0)<<endl;
    print_paths(0,0);

return 0;
}