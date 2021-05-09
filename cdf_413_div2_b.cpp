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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld P[n], A[n], B[n];
      map <lld, pair<lld, lld> > cl;
      for(lld i = 0; i < n; i += 1){
      	cin >> P[i];
      }
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      for(lld i = 0; i < n; i += 1){
      	cin >> B[i];
      }
      set <lld> color[4];
      for(lld i = 0; i < n; i += 1){
      	cl[P[i]] = {A[i], B[i]};
      	color[A[i]].insert(P[i]);
      	color[B[i]].insert(P[i]);
      }
      lld m;
      cin >> m;
      for(lld i = 0; i < m; i += 1){
      	lld c;
      	cin >> c;
      	if (color[c].empty()){
      		cout << "-1 ";
      	}
      	else{
      		set <lld> :: iterator itr = color[c].begin();
      		lld price = *itr;
      		cout << price  << " ";
      		pair <lld,lld> p = cl[price];
      		color[p.first].erase (price);
      		color[p.second].erase(price);
      	}
      }
      return 0;
}