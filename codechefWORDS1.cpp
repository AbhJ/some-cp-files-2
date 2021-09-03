//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 14 in 00 : 01 : 55
//title - a.cpp
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
int n;string s[N];
vi a, b;vvi g;
int parent[26],ind[26];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ind[v] = rand();
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
    }
}
void solve(){
	cin >> n;
	if(a.size() == 0)a.resize(26);
	g.clear();
	if(g.size() == 0)g.resize(26, vi(26));
	rep(i, 0, 25)make_set(i);
	fill(all(a), 0LL);
	if(b.size() == 0)b.resize(26);
	fill(all(b), 0LL);
	rep(i, 1, n)cin >> s[i];
	int odd_out = 0, in_out = 0, cnt_src = 0, cnt_snk = 0;
	rep(i, 1, n){
		a[s[i][0] - 'a']++;
		b[s[i].back() - 'a']++;
		g[s[i][0] - 'a'][s[i].back() - 'a'] |= 1;
		union_sets(s[i][0] - 'a', s[i].back() - 'a');
	}
	set<int>s;
	bool F = 0;
	rep(i, 0, 25){
		odd_out += (a[i] & 1);
		in_out += (b[i] & 1);
		if(a[i] != 0 or b[i] != 0)s.insert(find_set(i));
		if(a[i] == b[i] + 1)cnt_src++;
		if(a[i] == b[i] - 1)cnt_snk++;
		if(abs(a[i] - b[i]) <= 1)continue;
		F = 1;
	}
	if(cnt_src == cnt_snk and cnt_src < 2 and (int)s.size() == 1 and F == 0)
		cout << "Ordering is possible.";
	else
		cout << "The door cannot be opened.";
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}