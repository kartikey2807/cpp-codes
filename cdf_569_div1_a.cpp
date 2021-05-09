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
      lld n, q;
      cin >> n >> q;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
            cin >> A[i];
      }
      lld ans = MIN;
      for(lld i = 0; i < n; i += 1){
            ans = max(ans, A[i]);
      }
      lld p;
      for(lld i = 0; i < n; i += 1){
            if (A[i] == ans){
                  p = i;
                  break;
            }
      }
      map <lld, pair <lld, lld> > v;
      vector <lld> y;
      lld m = A[0];
      lld j = 1;
      while(j <= p){
            v[j] = {m,A[j]};
            y.push_back(min(m,A[j]));
            m = max(m,A[j]);
            j += 1;
      }
      vector <lld> x;
      for(lld i = p+1; i < n; i += 1)
            x.push_back(A[i]);
      for(lld i = 0; i < y.size(); i += 1)
            x.push_back(y[i]);
      lld len = x.size();
      for(lld i = 0; i < q; i += 1){
            lld turn;
            cin >> turn;
            if (turn <= p) cout << v[turn].first << " " << v[turn].second << "\n";
            else cout << ans << " " << x[(turn-p-1)%len] << "\n";
      }
      return 0;
}