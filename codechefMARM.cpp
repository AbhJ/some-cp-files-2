#include <bits/stdc++.h>
#define ll unsigned long long int
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
ll A[10000];
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti;
    int t=0,n=0;
    ll k=0;
    cin>>t;
    while(t--){
        cin>>n;cin>>k;
        for (int i = 0; i < n; ++i)
        {
            cin>>A[i];
        }
        // watch(n);watch(k);cout<<0%2;
        if (k>n){
            for(ll i=0;i<k%(3*n);i++){
                // int a=;int b=
                // cout<<A[i%N]<<"\t"<<A[N-(i%N)-1]<<"\n";
                A[i%n]=A[i%n]^A[n-(i%n)-1];
            }
            if (n%2)
            {
                A[(n/2)]=0;/* code */
            }
        }
        else{
            f(i,0,k-1){
            // int a=;int b=
            // cout<<A[i%N]<<"\t"<<A[N-(i%N)-1]<<"\n";
            A[i%n]=A[i%n]^A[n-(i%n)-1];
        }
        }
        // watch(A);

        for (int i = 0; i < n; ++i)
        {
            cout<<A[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}