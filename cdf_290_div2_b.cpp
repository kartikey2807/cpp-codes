// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA.
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
#define LEN 10000
lld vis[LEN];
char co[LEN];
lld f;
lld eval (lld a, lld b) {return (((a+b)*(a+b+1))/2)+b;}
void dfs (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	lld c = 0;
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] != -1 && co[v[pos][i]] == co[pos])
			c++;
	if (c > 1)
		f = 1;
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1 && co[v[pos][i]] == co[pos])
			dfs(v,v[pos][i]);
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      for(lld i = 1; i <= n; i += 1){
      	for(lld j = 1; j <= m; j += 1){
      		cin >> co[eval(i,j)];
      	}
      }
      vector <lld> v[LEN];
      for(lld i = 2; i <= n; i += 1){
      	for(lld j = 1; j <= m; j += 1){
      		v[eval(i,j)].push_back(eval(i-1,j));
      		v[eval(i-1,j)].push_back(eval(i,j));
      	}
      }
      for(lld j = 2; j <= m; j += 1){
      	for(lld i = 1; i <= n; i += 1){
      		v[eval(i,j)].push_back(eval(i,j-1));
      		v[eval(i,j-1)].push_back(eval(i,j));
      	}
      }
      f = 0;
      memset(vis,-1,sizeof(vis));
      for(lld i = 1; i <= n; i += 1){
      	for(lld j = 1; j <= m; j += 1){
      		if (vis[eval(i,j)] ==-1){
      			dfs(v, eval(i,j));
      			if (f == 1)
      				{cout << "Yes"; return 0;}
      		}
      	}
      }
      cout << "No";
      return 0;
}