//Coded by Abhijay Mitra (AbJ) on 2020 / 12 / 28 in 09 : 10 : 03
//title - codechefABROADS.cpp
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator> 
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
// #include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec "<<endl;
#define deb(x) cout<<endl<<"["<<#x<<" = "<<x<<"]"<<endl;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, m, q, a[N], x[N], y[N], rem[N], pop_of_query[N], prnt[N];
int parent[N],ind[N];
multiset<int>s;
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ind[v] = a[v];
    s.insert(ind[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ind[a] < ind[b])
            swap(a, b);
        parent[b] = a;
        s.erase(s.find(ind[b]));
        s.erase(s.find(ind[a]));
        ind[a] += ind[b];
        ind[b] = 0;
        s.insert(ind[a]);
    }
}
void solve(){
    cin >> n >> m >> q;
    rep(i, 1, n)cin >> a[i];
    rep(i, 1, m){
        cin >> x[i] >> y[i];        
    }
    vvi Q(q);
    rep(i, 1, q){
        int Y, z;char X;
        cin >> X >> Y;
        if(X == 'P')cin >> z;
        if(X == 'P')Q[i - 1] = vi{Y, z}, pop_of_query[i - 1] = a[Y], a[Y] = z;
        else Q[i - 1] = vi{Y}, rem[Y] = 1;
    }
    rep(i, 1, n)make_set(i);
    rep(i, 1, m)if(rem[i] == 0){
        union_sets(x[i], y[i]);
    }
    reverse(all(Q));
    rep(i, 1, q){
        prnt[q - i] = *s.rbegin();
        if(Q[i - 1].size() != 2){
            union_sets(x[Q[i - 1][0]], y[Q[i - 1][0]]);
        }
        else{
            s.erase(s.find(ind[find_set(Q[i - 1][0])]));
            ind[find_set(Q[i - 1][0])] -= Q[i - 1][1] - pop_of_query[q - i];
            s.insert(ind[find_set(Q[i - 1][0])]);
        }
    }
    rep(i, 0, q - 1)cout << prnt[i] << "\n";
} 
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}