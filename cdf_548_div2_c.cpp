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
#define MOD 1000000007
lld vis[LEN];
lld pow_ (lld a, lld n)
{
	if (n == 0) return 1;
	if (n == 1) return a;
	if (n%2==0) return ((pow_(a,n/2)%MOD)*(pow_(a,n/2)%MOD))%MOD;
	else return ((((pow_(a,n/2)%MOD)*(pow_(a,n/2)%MOD))%MOD)*(a%MOD))%MOD;
}
lld dfs (vector <lld> v[], lld pos)
{
	vis[pos] = 1;
	lld sum  = 1;
	for(lld i = 0; i < v[pos].size(); i += 1){
		if (vis[v[pos][i]] == -1)
			sum += dfs(v,v[pos][i]);
	}
	return sum;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, k;
      cin >> n >> k;
      vector <lld> v[n+1];
      for(lld i = 0; i < n-1; i += 1){
      	lld x, y, c;
      	cin >> x >> y >> c;
      	if (c == 0){
      		v[x].push_back(y);
      		v[y].push_back(x);
      	}
      }
      lld tot = pow_(n,k);
      lld acc = 0;
      memset(vis, -1, sizeof(vis));
      vector <lld> cat;
      for(lld i = 1; i <= n; i += 1){
      	if (vis[i] == -1)
      		cat.push_back(dfs(v,i));
      }
      for(lld i = 0; i < cat.size(); i += 1){
      	tot-= pow_(cat[i]%MOD,k)%MOD;
      	tot+= MOD;
      	tot%= MOD;
      }
      cout << tot;
      return 0;
}