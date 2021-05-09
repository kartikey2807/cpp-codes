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
      string s;
      cin >> s;
      lld n = s.length();
      vector <pair <char,lld> > cnt;
      for(lld i = 0; i < n; i += 1){
      	lld p = n;
      	for(lld j = i+1; j < n; j += 1){
      		if (s[j] != s[i]){
      			p = j;
      			break;
      		}
      	}
      	if (p-i > 2) cnt.push_back({s[i], 2});
      	else cnt.push_back({s[i], p-i});
      	i = p-1;
      }
      for(lld i = 1; i < cnt.size(); i += 1){
      	if (cnt[i].second == 2 && cnt[i-1].second == 2){
      		cnt[i].second= 1;
      	}
      }
      vector <char> v;
      for(lld i = 0; i < cnt.size(); i += 1){
      	while(cnt[i].second != 0){
      		cout<<cnt[i].first;
      		cnt[i].second -= 1;
      	}
      }
      return 0;
}