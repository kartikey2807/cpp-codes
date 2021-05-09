// みなさん私はカーティキー・シャルマです。LNMIITで勉強しています。私は2年目で、コロナパンデミックが発
// 生しています。世界は終わりそうだ。だから私はそれを最大限に生きたいと思っています。それはつまり、コー
// ドを最大限に意味しているのです。私の好きなアニメは「キメツノヤイバ」で、私の一番の男の子はゼニツで、
// 私の一番の女の子はネズコです。私の好きな呼吸スタイルは息吹です。私の最高の悪魔の血の芸術は、
// ククシボによって使用される月の息です。ムーザンは亡くなり、今ではタンジローがポップの新しい魔王です。
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
map <lld, lld> position;
set <lld> visited;
lld repeat;
void dfs1 (vector <lld> V[], lld x)
{
	visited.insert(x);
	for(lld i = 0; i < V[x].size(); i += 1){
		if (!visited.count(V[x][i])){
			dfs1(V , V[x][i]);
		}
		else  {
			repeat = V[x][i];
		}
	}
}
lld dfs2 (vector <lld> V[], lld x , lld dest)
{
	if (x == dest){
		return 0;
	}
	visited.insert(x);
	for(lld i = 0; i < V[x].size(); i += 1){
		if (!visited.count(V[x][i])){
			lld p = dfs2(V, V[x][i], dest) + 1;
			return p;
		}
	}
}
lld dfs3 (vector <lld> V[],lld x,lld k,lld c)
{
	if (c == k){
		return x;
	}
	visited.insert(x);
	for(lld i = 0; i < V[x].size(); i += 1){
		if (!visited.count(V[x][i])){
			lld y = dfs3(V, V[x][i], k, c + 1);
			return y;
		}
	}
}
void dfs4 (vector <lld> V[], lld x, lld c)
{
	position[c]  =  x;
	visited.insert(x);
	for(lld i = 0; i < V[x].size(); i += 1){
		if (!visited.count(V[x][i])){
			dfs4(V, V[x][i], c+1);
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
      lld n, k;
      cin >> n >> k;
     	vector <lld> V[n+1];
      for(lld i = 1; i <= n; i += 1){
      	lld r;
      	cin >> r;
      	V[i].push_back(r);
      }
      dfs1(V, 1);
      visited.clear();
      lld count = dfs2(V, 1, repeat);
      if (count > k){
      	visited.clear();
      	cout << dfs3(V, 1, k, 0);
      }
      else{
      	k-= count;
      	visited.clear();
      	dfs4(V, repeat, 0);
      	lld len=position.size();
      	cout << position[k%len];
      }
      return 0;
}