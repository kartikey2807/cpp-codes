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
#define LEN 10000
vector <lld>v[LEN];
set  <lld> visited;
vector <lld> order;
lld exec (lld x, lld y)
{
      return (((x+y)*(x+y+1))/2)+y;
}
void dfs (lld pos)
{
      visited.insert(pos);
      for(lld i = 0; i < v[pos].size(); i += 1){
            if (!visited.count(v[pos][i])){
                  dfs(v[pos][i]);
            }
      }
      order.push_back(pos);
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      string s[n+1];
      lld dda[n+1][n+1];
      lld x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      for(lld i = 1; i <= n; i += 1){
            cin >> s[i];
      }
      map <lld, pair<lld, lld> > pts;
      for(lld i = 1; i <= n; i += 1){
            for(lld j = 1; j <= n; j += 1){
                  dda[i][j] = (lld)s[i][j-1]-48;
                  pts[exec(i,j)] = {i,j};
            }
      }
      for(lld i = 1; i <= n; i += 1){
            for(lld j = 2; j <= n; j += 1){
                  if (dda[i][j] == 0  &&  dda[i][j-1] == 0){
                        v[exec(i,j)].push_back(exec(i,j-1));
                        v[exec(i,j-1)].push_back(exec(i,j));
                  }
            }
      }
      for(lld j = 1; j <= n; j += 1){
            for(lld i = 2; i <= n; i += 1){
                  if (dda[i][j] == 0  &&  dda[i-1][j] == 0){
                        v[exec(i,j)].push_back(exec(i-1,j));
                        v[exec(i-1,j)].push_back(exec(i,j));
                  }
            }
      }
      dfs(exec(x1,y1));
      vector <lld> f = order;
      visited.clear();
      order.clear();
      dfs(exec(x2,y2));
      lld min = MAX;
      for(lld i = 0; i < f.size(); i += 1){
            for(lld j = 0; j < order.size(); j += 1){
                  lld dist = pow(pts[f[i]].first - pts[order[j]].first, 2) + pow(pts[f[i]].second -pts[ order[j]].second, 2);
                  if (dist < min){
                        min = dist;
                  }
            }
      }
      cout << min;
      return 0;
}