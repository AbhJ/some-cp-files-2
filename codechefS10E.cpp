#include <bits/stdc++.h>
#define ll long long int
#define N 100000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
    // ll n[1001],r[1001];
    // double a[1001],p[1001];
int a[1000];
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti;
    int t,n,min=0,ans=1;
    cin>>t;
    while(t--){
    	cin>>n;
    	// // int a[n];
    	// for(int i=0;i<n;i++){
    	// 	cin>>a[i];
    	// }
    	vector<int> P;
        P.assign(5,1000);
        for(int i = 0;i!=n;++i){
            int x;
            cin >> x;
            P.push_back(x);
        }
        int good = 0;
        for(int i = 5;i!=P.size();++i){
            bool flag = true;
            for(int j = i-5;j!=i;++j){
                if(P[j] <= P[i]){
                    flag = false;
                    break;
                }
            }
            if(flag == true) good++;
        }
        cout << good << endl;
    }

    
    return 0;
}