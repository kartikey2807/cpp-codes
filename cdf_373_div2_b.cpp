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
lld cnt_ (string s, char A[], lld n)
{
	set <lld> red, black;
	for(lld i = 0; i < n; i += 1){
		if (s[i] != A[i]){
			if (s[i] == 'b'){
				black.insert(i);
			}
			else{
				red.insert  (i);
			}
		}
	}
	lld count = 0;
	for(set <lld> :: iterator itr = red.begin(); itr != red.end(); itr++){
		if (!black.empty()){
			set <lld> :: iterator pos = black.begin();
			lld x = (*itr);
			lld y = (*pos);
			swap(s[x],s[y]);
			count++;
			black.erase(y);
		}
	}
	for(lld i = 0; i < n; i += 1){
		if (s[i] != A[i]){
			count++;
		}
	}
	return count;
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
      string s;
      cin >> s;
      char A[n], B[n];
      for(lld i = 0; i < n; i += 2){
      	A[i] = 'b';
      	B[i] = 'r';
      }
      for(lld i = 1; i < n; i += 2){
      	A[i] = 'r';
      	B[i] = 'b';
      }
      cout << min(cnt_(s, A, n), cnt_(s, B, n));
      return 0;
}