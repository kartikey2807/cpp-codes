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
bool checkPalin (string s)
{
      lld len = s.length();
      lld z = 0, o = 0;
      for(lld i = 0; i < len; i += 1){
            if (s[i] == '0'){
                  z++;
            }
            if (s[i] == '1'){
                  o++;
            }
      }
      if (z%2==0) return true;
      else return false;
}
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
            lld n;
            cin >> n;
            string s[n];
            for(lld i = 0; i < n; i += 1){
                  cin >> s[i];
            }
            map <pair<string, lld>, bool> ans;
            for(lld i = 0; i < n; i += 1){
                  if (s[i].length()%2==0){
                        if (checkPalin(s[i]) == false){
                              ans[{s[i], i}] = false;
                        }
                        else
                              ans[{s[i], i}] = true;
                  }
            }
            for(map<pair<string, lld>, bool> :: iterator itr = ans.begin(); itr!=ans.end(); itr++){
                  pair <string, lld> p = itr->first;
                  if (itr->second == false){
                        for(lld i = 0; i < n; i += 1){
                              if (s[i].length()%2!=0){
                                    ans[p] = true;
                                    break;
                              }
                        }
                        if (ans[p] == false){
                              for(lld i = 0; i < n; i += 1){
                                    if (i == p.second)
                                          continue;
                                    if (s[i].length()%2==0 && ans[{s[i], i}] == false){
                                          ans[p] = true;
                                          ans[{s[i], i}] = true;
                                          break;
                                    }
                              }
                        }
                  }
            }
            lld count = 0;
            for(lld i = 0; i < n; i += 1){
                  if (s[i].length()%2!=0 || (s[i].length()%2==0 && ans[{s[i], i}] == true)){
                        count++;
                  }
            }
            cout << count << "\n";
      }
      return 0;
}