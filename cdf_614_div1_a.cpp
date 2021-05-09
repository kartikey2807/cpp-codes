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
      lld n, q;
      cin >> n >> q;
      lld dda[2][n];
      for(lld i = 0; i < n; i += 1){
            dda[0][i] = 1;
            dda[1][i] = 1;
      }
      set <pair<pair<lld,lld>, pair<lld,lld> > > block;
      for(lld i = 0; i < q; i += 1){
            lld x, y;
            cin >> x >> y;
            x -= 1;y -= 1;
            dda[x][y] = 1-dda[x][y];
            if (dda[x][y] == 0){
                  if (dda[1-x][y] == 0){
                        block.insert({{x,y},{1-x,y}});
                        block.insert({{1-x,y},{x,y}});
                  }
                  if (y+1 < n && dda[1-x][y+1] == 0){
                        block.insert({{x,y},{1-x,y+1}});
                        block.insert({{1-x,y+1},{x,y}});
                  }
                  if (y-1 >=0 && dda[1-x][y-1] == 0){
                        block.insert({{x,y},{1-x,y-1}});
                        block.insert({{1-x,y-1},{x,y}});
                  }
            }
            else{
                  if (block.count({{x,y},{1-x,y}})){
                        block.erase({{x,y},{1-x,y}});
                        block.erase({{1-x,y},{x,y}});
                  }
                  if (block.count({{x,y},{1-x,y+1}})){
                        block.erase({{x,y},{1-x,y+1}});
                        block.erase({{1-x,y+1},{x,y}});
                  }
                  if (block.count({{x,y},{1-x,y-1}})){
                        block.erase({{x,y},{1-x,y-1}});
                        block.erase({{1-x,y-1},{x,y}});
                  }
            }
            if (block.empty()){
                  cout << "Yes\n";
            }
            else{
                  cout <<  "No\n";
            }
      }
      return 0;
}