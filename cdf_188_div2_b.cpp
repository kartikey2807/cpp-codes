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
      string s;
      cin >> s;
      lld L = s.length();
      vector <lld> metal, heavy;
      for(lld i = 0; i < L-4; i += 1){
      	string r = "";
      	for(lld j = i; j < i+5; j += 1){
      		r += s[j];
      	}
      	if (r == "metal"){
      		metal.push_back(i);
      	}
      	if (r == "heavy"){
      		heavy.push_back(i);
      	}
      }
      lld l = metal.size(), pos = 0, count = 0;
      for(lld i = 0; i < heavy.size(); i += 1){
      	lld j;
      	for(j = pos; j < metal.size(); j += 1){
      		if (metal[j] > heavy[i]){
      			count+= l-j;
      			break;
      		}
      	}
      	pos = j;
      }
      cout << count << "\n";
      return 0;
}