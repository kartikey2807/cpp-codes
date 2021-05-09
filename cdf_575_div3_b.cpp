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
      	lld k, s;
      	cin >> n;
      	cin >> k;
      	lld A[n];
      	foi(i, n)
      	{
      		cin >> A[i];
      	}
      	s = 0;
      	lld c;
      	c = 0;
      	vector <lld>index;
      			index.push_back(n);
      	fod(i, n)
      	{
      		s = s+ A[i];
      		if (s%2!=0)
      		{
      			c+= 1;
      			s = 0;
      			index.push_back(i);
      		}
      	}
      	if (c < k)
      			cout<< "NO\n";
      	else
      	{
      		if ((c-k) % 2 ==  0)
      		{
      			cout<<"YES\n";
      			lld count = 0;
      			stack <lld> t;
      			lld Len = index.size();
      			for(lld j = 0; j < Len; j+=1)
      			{
      				t.push(index[j]);
      				count++;
      				if (count ==  k)
      					break;
      			}
      			while (!t.empty())
      			{
      				cout << t.top() << " ";
      				t.pop();
      			}
      			cout <<  "\n";
      		}
      		else
      			cout<< "NO\n";
      	}
      }
      return 0;
}