#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n, i;
      cin >> n;
      lld A[n];
      lld o, t;
      o = 0;
      t = 0;
      foi(i, n)
      {
      	cin >> A[i];
      	if (A[i]==1)
      		o +=1;
      	else
      		t +=1;
      }
      if (t > 0)
      {
      	cout <<"2 ";
      	t--;
      }
      if (o > 0)
      {
      	cout <<"1 ";
      	o--;
      }
      while (t != 0)
      {
      	cout <<"2 ";
      	t--;
      }
      while (o != 0)
      {
      	cout <<"1 ";
      	o--;
      }
      return 0;
}