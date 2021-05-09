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
      lld T, l;
      cin >> T;
      foi(l, T)
      {
      	lld n, i;
      	cin >> n;
      	lld A[n];
      	foi(i, n)
      	{
      		cin >> A[i];
      	}
      		sort(A,A+n);
      	set <lld>distinct;
      	foi(i, n)
      	{
      		distinct.insert(A[i]);
      	}
      	lld x = distinct.size();
      	lld c = 0;
      	lld m = 0;
      	for(i = 1; i < n; i+=1)
      	{
      		if (A[i]==A[i-1])
      			c += 1;
      		else
      		{
      			if (c >  m)
      				m= c;
      			c  = 0;
      		}
      	}
      			if (c >  m)
      				m= c;
      	lld a = x < m ?  x : m;
      	x-=1;
      	m+=1;
      	lld b = x < m ?  x : m;
      	cout <<(a>b?a:b)<<"\n";
      }
      return 0;
}