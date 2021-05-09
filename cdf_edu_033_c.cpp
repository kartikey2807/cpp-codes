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
#define LEN 100001
lld vis[LEN];
void dfs_  (vector <lld> V[], lld x)
{
	vis[x] = 1;
	for(lld i = 0; i < V[x].size(); i += 1){
		if (vis[V[x][i]] != 1){
			dfs_(V, V[x][i]);
		}
	}
}
void psort (lld A[], lld B[], lld n)
{
	pair <lld, lld> P[n];
	for(lld i = 0; i < n; i += 1){
		P[i].first  = A[i];
		P[i].second = B[i];
	}
	sort(P,P+n);
	for(lld i = 0; i < n; i += 1){
		A[i] =  P[i].first;
		B[i] = P[i].second;
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      lld A[n];
      lld B[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	B[i] =  i+1;
      }
      psort(A,B,n);
      vector <lld> V[n+1];
      for(lld i = 0; i < m; i += 1){
      	lld x, y;
      	cin >> x >> y;
      	V[x].push_back(y);
      	V[y].push_back(x);
      }
      for(lld i = 0; i < LEN; i+=1){
      	vis[i] = 0;
      }
      lld sum = 0;
      for(lld i = 0; i < n; i += 1){
      	if (vis[B[i]] != 1){
      		sum += A[i];
      		dfs_(V, B[i]);
      	}
      }
      cout << sum;
      return 0;
}