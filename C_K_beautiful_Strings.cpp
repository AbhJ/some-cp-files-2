#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
using vi = std::vector<int>;
using vvi = std::vector<vi>;
int32_t main()
{
  ibs;cti;
  int t;cin>>t;while(t--){
	  string s;
	  int n, k;
	  cin >> n >> k;
	  cin >> s;
	  vi a(26);vvi tmp(26);
	  rep(i, 0, (int)s.length() - 1){
		  tmp[s[i] - 'a'].push_back(i);
	  }
	  rep(i, 0, 25){
		  if(i + 'a' != 'z' and ((int)tmp[i + 'a' - 'a'].size() + (int)tmp[i + 'a' - 'a' + 1].size()) % k == 0){
			  for(auto &j: tmp[i + 'a' - 'a' + 1])
			  	s[j]++;
				tmp[i + 'a' - 'a'].clear(),
				tmp[i + 'a' - 'a' + 1].clear();
		  }
		  if(i + 'a' != 'a' and ((int)tmp[i + 'a' - 'a'].size() + (int)tmp[i + 'a' - 'a' + 1].size()) % k == 0){
			  for(auto &j: tmp[i + 'a' - 'a' - 1])
			  	s[j]++;
				tmp[i + 'a' - 'a'].clear(),
				tmp[i + 'a' - 'a' - 1].clear();
		  }
		rep(j, 0, 25)
	 	if((int)tmp[j].size() == 0){
			//  cout << - 1LL;
			 goto F;
		 }
	  }
	//  rep(i, 0, 25)
	//  	if((int)tmp[i].size() != 0){
	// 		 cout << - 1LL;
	// 		 goto F;
	// 	 }
	 cout << "" << s;
	 F:;
	 cout << "\n";
  }
  return 0;
}