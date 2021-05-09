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
#define foi(i,n) for(lld i = 0; i < n; i+=1)
#define fod(i,n) for(lld i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LEN 100005
lld j;
lld vis[LEN];
map <pair <lld, lld>, lld> val;
void dfs (lld pos, vector <lld> v[])
{
	vis[pos] = 1;
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (vis[v[pos][i]] == -1){
			val[{pos,v[pos][i]}] = val[{v[pos][i],pos}] = j;
			j++;
		}
	}
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (vis[v[pos][i]] == -1){
			dfs(v[pos][i], v);
		}
	}
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
      vector <lld> v[n+1];
      pair <lld, lld> P[n-1];
      for(lld i = 0; i < n-1; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	P[i] = {x,y};
      	v[x].push_back(y);
      	v[y].push_back(x);
      }
      j = 0;
      memset(vis, -1, sizeof(vis));
      for(lld i = 1; i < n+1; i += 1){
      	if (v[i].size() == 1){
      		if (!val.count({v[i][0],i})){
      			val[{v[i][0],i}] = val[{i,v[i][0]}] = j;
      			j++;
      			vis[i] = 1;
      		}
      	}
      }
      for(lld i = 1; i < n+1; i += 1){
      	if (vis[i] == -1){
      		dfs(i,v);
      	}
      }
      for(lld i = 0; i < n-1; i += 1){
      	cout << val[P[i]] << "\n";
      }
      return 0;
}