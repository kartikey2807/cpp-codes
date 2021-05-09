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
      lld n;
      cin >> n;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      lld ans = MIN;
      lld prev = n-1;
      set <lld> diff;
      map <lld, lld> count;
      for(lld i = n-1; i >= 0; i -= 1){
      	diff.insert(A[i]);
      	count[A[i]]++;
      	set <lld> :: iterator itr = diff.begin();
      	set <lld> :: iterator pos = diff.end(); pos--;
      	if (((*pos)-(*itr)) > 1){
      		if (prev-i > ans){
      			ans = prev-i;
      		}
      		for(lld j = prev; j >= i; j -= 1){
      			count[A[j]]--;
      			if (count[A[j]] == 0){
      				diff.erase(A[j]);
      			}
      			set <lld> :: iterator a1 = diff.begin();
      			set <lld> :: iterator a2 = diff.end(); a2--;
      			if (((*a2)-(*a1)) <= 1){
      				prev = j-1;
      				break;
      			}
      		}
      	}
      }
      if ((prev+1) > ans){
      	ans = prev+1;
      }
      cout << ans;
      return 0;
}