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
typedef string  str;
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
      str s, t;
      cin >> s >> t;
      set <char> ch;
      map <char, lld> count;
      for(lld i = 0; i < t.length(); i += 1){
      	ch.insert(t[i]);
      	count[t[i]]++;
      }
      set <lld> vis;
      lld c1 = 0;
      for(lld i = 0; i < s.length(); i += 1){
      	if (ch.count(s[i])){
      		c1++;
      		vis.insert(i);
      		count[s[i]]--;
      		if (count[s[i]] == 0){
      			ch.erase(s[i]);
      		}
      	}
      }
      lld c2 = 0;
      for(lld i = 0; i < s.length(); i += 1){
      	if (vis.count(i)){
      		continue;
      	}
      	lld x = (lld)s[i];
      	if (x >= 65 && x <= 90)
      		x += 32;
      	else
      		x -= 32;
      	char y = (char)x;
      	if (ch.count(y)){
      		c2++;
      		count[y]--;
      		if (count[y] == 0){
      			ch.erase(y);
      		}
      	}
      }
      cout << c1 << " " << c2;
      return 0;
}