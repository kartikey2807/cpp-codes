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
#define neg -1
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      set <queue <lld> > s1;
      set <queue <lld> > s2;
      lld k1,k2;
      cin >> k1;
      queue <lld> temp1;
      queue <lld> temp2;
      for(lld i = 0; i < k1; i += 1){
            lld r;
            cin >> r;
            temp1.push(r);
      }
      s1.insert(temp1);
      cin >> k2;
      for(lld i = 0; i < k2; i += 1){
            lld r;
            cin >> r;
            temp2.push(r);
      }
      s2.insert(temp2);
      lld f = 1;
      lld c = 0;
      while(!temp1.empty() && !temp2.empty()){
            lld x = temp1.front();temp1.pop();
            lld y = temp2.front();temp2.pop();
            if (x > y){
                  temp1.push(y);
                  temp1.push(x);
            }
            else{
                  temp2.push(x);
                  temp2.push(y);
            }
            if (s1.count(temp1) && s2.count(temp2)){
                  f = 0;
                  break;
            }
            s1.insert(temp1);
            s2.insert(temp2);
            c++;
      }
      if (f == 1){
            cout << c << " ";
            if (temp1.empty())
                  cout<< "2";
            else
                  cout<< "1";
      }
      else 
            cout << neg;
      return 0;
}