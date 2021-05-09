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
      lld t, l;
      cin >> t;
      foi(l,t){
            string s;
            cin >> s;
            lld p = -1;
            for(lld i = 1; i < s.length(); i += 1){
                  if (s[i] != s[i-1]){
                        p = i;
                        break;
                  }
            }
            if (p == -1){
                  cout << "0\n";
            }
            else{
                  lld f = 0;
                  for(lld i = p+1; i < s.length(); i += 1){
                        if (s[i] != s[i-1]){
                              f = 1;
                              break;
                        }
                  }
                  if (f == 0){
                        cout << "0\n";
                  }
                  else{
                        lld z = 0, o = 0;
                        lld n = s.length();
                        map <lld, pair <lld, lld> > right, left;
                        for(lld i = 0; i < n; i += 1){
                              if (s[i] == '0'){
                                    z++;
                              }
                              else{
                                    o++;
                              }
                              right[i] = {z,o};
                        }
                        o = 0;
                        z = 0;
                        left[n-1] = {0,0};
                        for(lld i = n-2; i >= 0; i -= 1){
                              if (s[i+1] == '0'){
                                    z++;
                              }
                              else{
                                    o++;
                              }
                              left[i] = {z,o};
                        }
                        lld Min = MAX;
                        for(lld i = 0; i < n; i += 1){
                              lld x = min(right[i].first, right[i].second) + min(left[i].first, left[i].second);
                              if (x < Min){
                                    Min=x;
                              }
                        }
                        cout << Min << "\n";
                  }
            }
      }
      return 0;
}