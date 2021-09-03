#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
int a[10000000];
int32_t main()
{
  ibs;cti;
  rep(i, 0, 1e18){
	if(i * 2020 > (int)1e6)
		break;
		rep(j, 0, 1e18){
			if(j * 2021 + i * 2020 > (int)1e6)
				break;
			a[j * 2021 + i * 2020] = 1;
		}
  }
  int t;cin>>t;while(t--){
	int n;cin >> n;
	if(a[n] == 0)cout << "NO\n";
	else cout << "YES\n";
  }
  return 0;
}