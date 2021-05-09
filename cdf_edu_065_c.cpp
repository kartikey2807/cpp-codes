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
#define LEN 500005
vector <lld> friends;
lld vis[LEN];
lld cnt[LEN];
void dfs (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	for(lld i = 0; i < v[pos].size(); i++){
		if (vis[v[pos][i]] == -1){
			dfs(v,v[pos][i]);
		}
	}
	friends.push_back(pos);
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
      vector <lld> v[n+1];
      for(lld i = 0; i < m; i += 1){
      	lld l, r;
      	cin >> l;
      	if (l == 0)
      	continue;
      	cin >> r;
      	for(lld j = 1; j < l; j += 1){
      		lld x;
      		cin >> x;
      		v[r].push_back(x);
      		v[x].push_back(r);
      	}
      }
      for(lld i = 0; i < LEN; i += 1){
      	vis[i] = -1;
      	cnt[i] = -1;
      }
      for(lld i = 1; i <=  n; i += 1){
      	if (vis[i] == -1){
      		friends.clear();
      		dfs(v,i);
      		lld len = friends.size();
      		for(lld j = 0; j < friends.size(); j += 1){
      			cnt[friends[j]] = len;
      		}
      	}
      }
      for(lld i = 1; i <=  n; i += 1){
      	cout << cnt[i] << " ";
      }
      return 0;
}