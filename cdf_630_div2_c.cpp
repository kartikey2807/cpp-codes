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
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld n, k;
      	cin >> n >> k;
      	string s;
      	cin >> s;
      	string temp = s;
      	map <pair <lld, char>, lld> c;
      	for(lld i = 0; i < n; i += 1){
      		c[{i%k, s[i]}]++;
      	}
      	for(lld i = 0; i < (k/2); i += 1){
      		char pos;
      		lld max = MIN;
      		for(char a = 'a'; a <= 'z'; a+=1){
      			if ((c[{i,a}]+c[{k-i-1,a}]) > max){
      				max = c[{i,a}]+c[{k-i-1,a}];
      				pos = a;
      			}
      		}
      		s[i] = s[k-i-1] = pos;
      	}
      	if (k%2 != 0){
      		char pos;
      		lld max = MIN;
      		for(char a = 'a'; a <= 'z'; a+=1){
      			if (c[{(k/2), a}] > max){
      				max = c[{(k/2),a}];
      				pos = a;
      			}
      		}
      		s[k/2] = pos;
      	}
      	for(lld i = k; i < n; i += 1){
      		s[i] = s[i%k];
      	}
      	lld count = 0;
      	for(lld i = 0; i < n; i += 1){
      		if (temp[i] != s[i])
      			count++;
      	}
      	cout << count << "\n";
      }
      return 0;
}