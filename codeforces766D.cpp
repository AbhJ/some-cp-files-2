//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 11 in 08 : 30 : 39
//title - D_Mahmoud_and_a_Dictionary.cpp
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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, m, q, ty;
string s, t;map<string, int>mm;
int parent[N],ind[N];
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
        if (ind[a] < ind[b])
            swap(a, b);
        parent[b] = a;
    }
}
void solve(){
	cin >> n >> m >> q;
	rep(i, 1, 2 * n)
		make_set(i);
	rep(i, 1, n)
		cin >> s,
		mm[s] = i;
	rep(i, 1, m){
		cin >> ty >> s >> t;
		if(ty == 1){
			if(find_set(mm[s]) == find_set(mm[t] + n) or find_set(mm[s] + n) == find_set(mm[t]))
				cout << "NO";
			else
				cout << "YES",
				union_sets(mm[s], mm[t]),
				union_sets(mm[s] + n, mm[t] + n);
		}
		else{
			if(find_set(mm[s]) == find_set(mm[t]) or find_set(mm[s] + n) == find_set(mm[t] + n))
				cout << "NO";
			else
				cout << "YES",
				union_sets(mm[s], mm[t] + n),
				union_sets(mm[s] + n, mm[t]);
		}
		cout << "\n";
	}
	rep(i, 1, q){
		cin >> s >> t;
		if(find_set(mm[s]) == find_set(mm[t]) or find_set(mm[s] + n) == find_set(mm[t] + n))
			cout << 1;
		else if(find_set(mm[s]) == find_set(mm[t] + n) or find_set(mm[s] + n) == find_set(mm[t]))
			cout << 2;
		else
			cout << 3;
		cout << "\n";
	}
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}