#include <iostream>
#include<bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define mp make_pair
using namespace std;

int32_t main() {
// your code goes here
 //cout<<"Case #"<<x++<<":\n";
int n,m,i,j,k;
cin>>n;
vi a(n+1);
//for(i=1;i<=n;i++)
//cin>>a[i];
int l=1,h=n,mid;
while(1)
{
   int x,y=1e9,z=1e9;
mid=(h+l)/2;
cout<<"? "<<mid<<"\n";
cin>>x;
//x=a[mid];
if(mid>1)
{
     cout<<"? "<<mid-1<<"\n";
cin>>y;
 //y=a[mid-1];
}
if(mid<n)
 {cout<<"? "<<mid+1<<"\n";
cin>>z;
//z=a[mid+1];
}
// cout<<" y="<<y<<"\n";
//cout<<"z="<<z<<"\n";
if(x<y&&x<z)
{
    cout<<"! "<<mid<<"\n";
    break;
}
else if(x>y)
h=mid-1;
else if(x>z)
l=mid+1;
}



return 0;
}