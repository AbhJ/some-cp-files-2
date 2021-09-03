#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
int32_t main()
{
  ibs;cti;
//   int t;cin>>t;while(t--){
	  int n, q, k;
	  cin >> n >> q >> k;
	  int a[n + 1], p[n + 2];
	  rep(i, 0, n + 1)p[i] = 0;
	  rep(i, 1, n)cin >> a[i];
	  rep(i, 2, n - 1){
		  if(a[i - 1] >= a[i] and a[i + 1] >= a[i])
		  	p[i] = a[i] - min(a[i - 1], a[i + 1]) - 1;
		  else if(a[i - 1] <= a[i] and a[i + 1] <= a[i])
		  	p[i] = max(a[i - 1], a[i + 1]) - a[i] - 1;
		  else
		  	p[i] = max(a[i - 1], a[i + 1]) - min(a[i - 1], a[i + 1]) - 2;
	  }
	  p[1] = abs(a[2] - a[1]) - 1;
	  p[n] = abs(a[n] - a[n - 1]) - 1;
	  rep(i, 1, n)p[i] = max(p[i], 0LL);
	  rep(i, 1, n)p[i] = p[i - 1] + p[i];
	  rep(i, 1, q){
		  int l, r;
		  cin >> l >> r;
		  cout << p[r] - p[l - 1];
		  cout << "\n";
	  }
//   }
  return 0;
}