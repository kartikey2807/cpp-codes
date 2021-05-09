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
lld get_diff (set <lld> index)
{
	set <lld> :: iterator itr = index.begin();
	set <lld> :: iterator pos = index.end(); pos--;
	return ((*pos)-(*itr));
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
      set <lld> index;
      map <lld, lld> count;
      map <lld, queue <lld> > id;
      for(lld i = 0; i < n; i += 1){
      	lld r;
      	cin >> r;
      	count[r]++;
      	index.insert(r);
      	id[r].push(i);
      }
      vector <pair <lld, lld> > vec_p;
      lld cnt = 0;
      while(true){
      	set <lld> :: iterator itr = index.begin();
      	set <lld> :: iterator pos = index.end(); pos--;
      	lld a = (*itr);
      	lld b = (*pos);
      	lld diff = b-a;
      	if (cnt == k || diff == 0 || diff == 1){
      		break;
      	}
      	count[a]--; if (count[a] == 0) index.erase(a);
      	count[b]--; if (count[b] == 0) index.erase(b);
      	lld i_pos = id[b].front();
      	lld j_pos = id[a].front();
      	vec_p.push_back({i_pos, j_pos});
      	id[b].pop();
      	id[a].pop();
      	b--;
      	a++;
      	index.insert(a); count[a]++;
      	index.insert(b); count[b]++;
      	id[b].push(i_pos);
      	id[a].push(j_pos);
      	cnt++;
      }
      cout << get_diff(index) << " " << cnt << "\n";
      for(lld i = 0; i < vec_p.size(); i += 1){
            pair <lld, lld> p = vec_p[i];
            cout << p.first+1 << " " << p.second+1 << "\n";
      }
      return 0;
}