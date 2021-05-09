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
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
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
      lld n;
      cin >> n;
      string s;
      string m;
      cin >> s;
      cin >> m;
      lld S[n];
      lld M[n];
      set <lld> moriarty1, moriarty2;
      map <lld, lld> cnt1, cnt2;
      for(lld i = 0; i < n; i += 1){
      	S[i] = (lld)s[i] - 48;
      	M[i] = (lld)m[i] - 48;
      	moriarty1.insert(M[i]);
      	moriarty2.insert(M[i]);
      	cnt1[M[i]]++; cnt2[M[i]]++;
      }
      lld c = 0;
      for(lld i = 0; i < n; i += 1){
      	lld f = 0;
      	for(set <lld> :: iterator itr = moriarty1.begin(); itr != moriarty1.end(); itr++){
      		if ((*itr)>=S[i]){
      			cnt1[*itr]--;
      			if (cnt1[*itr] == 0){
      				moriarty1.erase(itr);
      			}
      			f = 1;
      			break;
      		}
      	}
      	if (f == 0)
      		c+=1;
      }
      cout << c << "\n";
      c = 0;
      for(lld i = 0; i < n; i += 1){
      	lld f = 0;
      	for(set <lld> :: iterator itr = moriarty2.begin(); itr != moriarty2.end(); itr++){
      		if ((*itr)> S[i]){
      			cnt2[*itr]--;
      			if (cnt2[*itr] == 0){
      				moriarty2.erase(itr);
      			}
      			f = 1;
      			break;
      		}
      	}
      	if (f == 1)
      		c+=1;
      }
      cout<< c;
      return 0;
}