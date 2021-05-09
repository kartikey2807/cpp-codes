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
set <lld> visit;
map <lld, lld> counter;
void dfs (vector <lld> V[], lld x)
{
	visit.insert(x);
	for(lld i = 0; i < V[x].size();i++){
		if (!visit.count(V[x][i])){
			counter[V[x][i]] += counter[x];
			dfs(V , V[x][i]);
		}
	}
}
int main ()
{
	#ifndef ONLINE_JUDGE
	freopen("inputf.in",  "r",   stdin);
	freopen("outputf.in", "w",  stdout);
	#endif
	FastIO
	lld n, q;
	cin >> n;
	cin >> q;
	lld i;
	vector <lld> V[n+1];
	foi(i , n-1) {
		lld x, y;
		cin >> x;
		cin >> y;
		V[x].push_back(y);
		V[y].push_back(x);
	}
	foi(i,q){
		lld r, x;
		cin >> r;
		cin >> x;
		counter[r] += x;
	}
	dfs(V,1);
	foi(i,n){
		cout << counter[i+1] << " ";
	}
	return 0;
}