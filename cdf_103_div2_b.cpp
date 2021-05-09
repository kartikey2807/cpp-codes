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
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld xA, yA, xB, yB;
      cin >> xA >> yA >> xB >> yB;
      map <pair<lld, lld>, lld> c;
      for(lld i = min(xA,xB); i <= max(xA,xB); i += 1){
            c[{i,yA}] = 1;
            c[{i,yB}] = 1;
      }
      for(lld i = min(yA,yB); i <= max(yA,yB); i += 1){
            c[{xA,i}] = 1;
            c[{xB,i}] = 1;
      }
      lld n;
      cin >> n;
      for(lld i = 0; i < n; i += 1){
            dbl x, y, r;
            cin >> x >> y >> r;
            for(map <pair<lld, lld>, lld> :: iterator itr = c.begin(); itr != c.end(); itr++){
                  if (itr->second == 1){
                        pair <lld, lld> p = itr->first;
                        dbl dist = sqrt(pow(p.first - x, 2) + pow(p.second - y, 2));
                        if (dist <= r){
                              c[p]= 0;
                        }
                  }
            }
      }
      lld count = 0;
      for(map <pair<lld, lld>, lld> :: iterator itr = c.begin(); itr != c.end(); itr++){
            if (itr->second == 1){
                  count++;
            }
      }
      cout << count;
      return 0;
}