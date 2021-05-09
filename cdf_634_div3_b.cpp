#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef char chr;
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
      	lld n, a;
      	lld b, i;
      	cin >> n;
      	cin >> a;
      	cin >> b;
      	chr C[n];
      	chr c;
      	lld j;
      	c =  'a';
      	foi(i, a)
      	{
      		C[i] = c;
      		c++;
      		b--;
      		if (b == 0)
      			break;
      	}
      	for(j = i + 1; j < a; j++)
      	{
      		C[j] = C[j-1];
      	}
      	for(i = a + 0; i < n; i++)
      	{
      		C[i] = C[i-a];
      	}
      	foi(i, n)
      	{
      		cout <<  C[i];
      	}
      		cout <<  "\n";
      }
      return 0;
}