// Bipartite graphs -> graphs in which you can group the nodes in to two independent and disjoint sets such that every edge (u,v)
// connects u to v for u --> SET A and v --> SET B. Every tree is a Bipartite graph.
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
vector <lld> A;
vector <lld> B;
set <lld> visit;
map <lld, lld> index;
void dfs (vector <lld> V[], lld x, lld c)
{
	visit.insert(x);
	if (c % 2 == 0){
		A.push_back(x);
	}
	else{
		B.push_back(x);
	}
	lld cnt = 0;
	for(lld i = 0; i < V[x].size(); i += 1){
		if (!visit.count(V[x][i])){
			dfs(V, V[x][i], c+1);
			cnt++;
		}
	}
	index[x] = cnt+1;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      vector <lld> V[n+1];
      for(lld i = 0; i < n-1; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	V[x].push_back(y);
      	V[y].push_back(x);
      }
      lld count  = 0;
      dfs(V,1,count);
      lld L = B.size();
      lld sum = 0;
      index[1]-=1;
      for(lld i = 0; i < A.size(); i += 1){
      	sum+= (L-index[A[i]]);
      }
      cout << sum;
      return 0;
}