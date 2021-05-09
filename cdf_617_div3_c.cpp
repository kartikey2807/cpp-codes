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
      lld t, w;
      cin >> t;
      foi(w,t){
      	lld n;
      	cin >> n;
      	string s;
      	cin >> s;
      	lld x = 0, y = 0;
      	set <pair <lld, lld> > vis;
      	map <pair <lld, lld>, lld > idx;
      	vis.insert({0,0});
      	idx[{0,0}] = -1;
      	lld ans = MAX;
      	lld l, r;
      	for(lld i = 0; i < n; i += 1){
      		if (s[i] == 'L')
      			x--;
      		if (s[i] == 'R')
      			x++;
      		if (s[i] == 'U')
      			y++;
      		if (s[i] == 'D')
      			y--;
      		if (vis.count({x,y})){
      			lld prev = idx[{x,y}];
      			if ((i - prev) < ans){
      				ans = i-prev;
      				l = prev+2;
      				r = i+1;
      			}
      		}
      		idx[{x,y}] = i;
      		vis.insert({x,y});
      	}
      	if (ans == MAX) cout << "-1\n";
      	else cout << l << " " << r << "\n";
      }
      return 0;
}