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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      vector <lld> v;
      set <lld> visited;
      map <lld, pair <lld, lld> > idx;
      for(lld i = 2; i <= 2*n; i += 1){
      	for(lld j = 1; j <= i-1; j += 1){
      		lld r;
      		cin >> r;
      		idx[r] = {i,j};
      		v.push_back(r);
      	}
      }
      map <lld, lld> comp;
      sort(v.begin()  , v.end());
      reverse(v.begin(),v.end());
      for(lld i = 0;  i < v.size();  i += 1){
      	if (!visited.count(idx[v[i]].first) && !visited.count(idx[v[i]].second)){
      		visited.insert(idx[v[i]].first);
      		visited.insert(idx[v[i]].second);
      		comp[idx[v[i]].first] = idx[v[i]].second;
      		comp[idx[v[i]].second] = idx[v[i]].first;
      	}
      }
      for(lld i = 1; i <= 2*n; i += 1){
      	cout << comp[i] << " ";
      }
      return 0;
}