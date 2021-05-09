// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA. Double cannot be used
// for comparisons use div and mod instead. 
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
#define foi(i,n) for(lld i = 0; i < n; i+=1)
#define fod(i,n) for(lld i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define auth set <lld> :: iterator
#define pb push_back
lld n, m, shit;
lld ans;
void rec (lld pos, lld x, lld sum, vector <lld> dda[])
{
	if (pos  == shit){
		if (x == 0){
			lld j;
			for(j = m+1; j > 0; j -= 1){
				if (dda[pos][j] == 1)
					break;
			}
			ans = min(ans,sum+j);
		}
		else{
			lld j;
			for(j = 0; j < m+1; j += 1){
				if (dda[pos][j] == 1)
					break;
			}
			ans = min(ans,sum+m+1-j);
		}
		return;
	}
	if (x == 0){
		lld j;
		for(j = m+1; j > 0; j -= 1){
			if (dda[pos][j] == 1)
				break;
		}
		rec(pos-1, m+1, sum+m+2, dda); rec(pos-1, (lld)0, sum+(2*j)+1, dda);
	}
	else{
		lld j;
		for(j = 0; j < m+1; j += 1){
			if (dda[pos][j] == 1)
				break;
		}
		rec(pos-1,(lld)0,sum+m+2,dda); rec(pos-1,m+1,sum+(2*(m+1-j))+1,dda);
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      cin >> n >> m;
      vector <lld> dda[n];
      for(lld i = 0; i < n; i += 1){
      	for(lld j = 0; j < m+2; j += 1){
      		char c;
      		cin >> c;
      		dda[i].pb((lld)c-48);
      	}
      }
      shit = n-1;
      for(lld i = 0; i < n; i += 1){
      	lld f = 0;
      	for(lld j = 0; j < m+2; j += 1){
      		if (dda[i][j] == 1)
      			f = 1;
      	}
      	if (f == 1){
      		shit = i;
      		break;
      	}
      }
      ans = MAX;
      rec(n-1,(lld)0,(lld)0,dda);
      cout << ans;
      return 0;
}