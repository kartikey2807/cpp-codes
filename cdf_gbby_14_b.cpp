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
#define LEN 1000
lld vis[LEN];
vector <lld> orz;
void dfs (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	orz.pb(pos);
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (vis[v[pos][i]] == -1)
			dfs(v,v[pos][i]);
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      char dda[n][n];
      for(lld i = 0; i < n; i += 1){
      	for(lld j = 0; j < n; j += 1){
      		cin >> dda[i][j];
      	}
      }
      vector <lld> v[n];
      for(lld i = 0; i < n; i += 1){
      	for(lld j = 0; j < n; j += 1){
      		if (dda[i][j] == '1')
      			v[i].pb(j);
      	}
      }
      memset(vis, -1, sizeof(vis));
      for(lld i = 0; i < n; i += 1){
      	if (vis[i] == -1){
      		orz.clear();
      		dfs(v,i);
      		vector <lld> temp;
      		for(lld j = 0; j < orz.size(); j += 1){
      			temp.pb(A[orz[j]]);
      		}
      		sort(temp.begin(),temp.end());
      		sort(orz.begin() , orz.end());
      		for(lld j = 0; j < orz.size(); j += 1){
      			A[orz[j]] = temp[j];
      		}
      	}
      }
      for(lld i = 0; i < n; i += 1){
      	cout << A[i] << " ";
      }
      return 0;
}