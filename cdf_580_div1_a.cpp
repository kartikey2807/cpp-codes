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
      if (n % 2 == 0)
      {
      	cout <<  "NO\n";
      }
      else
      {
      	cout << "YES\n";
      	set <lld> vis;
      	lld Arr [2*n];
      	lld a, b, c;
      	a = 1;
      	b = 2;
      	c = 0;
      	while (c < n)
      	{
      		if (c % 2 == 0)
      		{
      			if (!vis.count(a))
      			{
      				Arr[c] = a;
      				Arr[c+n] = a+1;
      				vis.insert(a);
      				vis.insert(a+1);
      				c+=1;
      			}
      			else
      			{
      				a+=2;
      			}
      		}
      		else
      		{
      			if (!vis.count(b))
      			{
      				Arr[c] = b;
      				Arr[c+n] = b-1;
      				vis.insert(b);
      				vis.insert(b-1);
      				c+=1;
      			}
      			else
      			{
      				b+=2;
      			}
      		}
      	}
      	cout << Arr[0] <<  " ";
      	for(i=(2*n)-1;i>0;i-=1)
      	{
      		cout << Arr[i] << " ";
      	}
      }
      return 0;
}