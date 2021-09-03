//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 01 in 10 : 45 : 45
//title - D_Fedor_and_Essay.cpp
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
#include <bits/stdc++.h>
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
int n, m, pos[N], koita_r[N], tot_sum, koita_size[N], b[N], vis[N];set<vi>q;vvi a;map<string, int>ma;
string s[N];
int g(string S){
	if(ma.count(S) == 1);
	else ma[S] = (int)++tot_sum,
	koita_r[ma[S]] = count(all(S), 'r'),
	koita_size[ma[S]] = (int)S.length();
	return ma[S];
}
void solve(){
	cin >> n;
	a.resize(N);
	rep(i, 1, n){
		cin >> s[i];
		transform(all(s[i]), s[i].begin(),[](unsigned char c){ return std::tolower(c); });
	}
	rep(i, 1, n){
		if(ma.count(s[i]) == 1);
		else ma[s[i]] = (int)++tot_sum,
		koita_r[ma[s[i]]] = count(all(s[i]), 'r'),
		koita_size[ma[s[i]]] = (int)s[i].length();
	}
	cin >> m;
	rep(i, 1, m){
		string S, T;
		cin >> S >> T;
		transform(all(S), S.begin(),[](unsigned char c){ return std::tolower(c); });
		transform(all(T), T.begin(),[](unsigned char c){ return std::tolower(c); });
		int ba = g(S), da = g(T);
		a[da].pb(ba);
		b[ba]++;
	}
	rep(i, 1, tot_sum){
		q.insert(vi{koita_r[i], koita_size[i], i});
	}
	while(q.empty() == 0){
		int r = (*q.begin())[0];
		int siz = (*q.begin())[1];
		int val = (*q.begin())[2];
		int i = val;
		for(int &j: a[val]){
			if((koita_r[j] > koita_r[val]) or (koita_r[j] == koita_r[i] and
					koita_size[j] > koita_size[i])){
				if(q.count(vi{koita_r[j], koita_size[j], j}) == 1)q.erase(vi{koita_r[j], koita_size[j], j});
				koita_r[j] = koita_r[i], koita_size[j] = koita_size[i], q.insert(vi{koita_r[j], koita_size[j], j});
			}
		}
		q.erase(vi{koita_r[i], koita_size[i], i});
	}
	int l = 0, r = 0;
	rep(i, 1, n){
		l += koita_r[ma[s[i]]];
		r += koita_size[ma[s[i]]];
	}
	cout << l << " " << r;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}