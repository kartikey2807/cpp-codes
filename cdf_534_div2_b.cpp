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
#define PI 3.14159265358979323
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
      string s;
      cin >> s;
      lld c, i;
	lld n = s.length();
	lld B[n];
      foi(i, n)
      {
      	if (i  == 0)
      		B[i] =  -1;
      	else
      		B[i] = i-1;
      }
      c = 0;
      for(i = 1; i < n; i++){
      	if (B[i] >= 0 && s[i] == s[B[i]])
      	{
      		c++;
      		B[i+1]=B[B[i]];
      	}
      }
      if (c % 2 == 0)
      	cout <<  "No\n";
      else
      	cout << "Yes\n";
      return 0;
}