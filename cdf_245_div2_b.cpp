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
      lld n, k, x;
      cin >> n >> k >> x;
      lld C[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> C[i];
      }
      lld max_count = 0;
      for(lld i = 1; i < n; i += 1){
      	if (C[i] == C[i-1] && C[i] == x){
      		lld count = 2;
      		lld pos = i-2;
      		for(lld j = i+1; j < n; j += 1){
      			if (j < n &&  pos  >=  0){
      				lld cnt1 = 0;
      				lld p = -1;
      				for(lld start = j+1; start < n; start++){
      					if (C[start] == C[start-1]){
      						cnt1++;
      					}
      					else{
      						p = start;
      						cnt1++;
      						break;
      					}
      				}
      				if (p == -1){
      					p  = n;
      					cnt1++;
      				}
      				lld cnt2 = 0;
      				lld q = -1;
      				for(lld end = pos-1; end >= 0; end -= 1){
      					if (C[end] == C[end+1]){
      						cnt2++;
      					}
      					else{
      						q = end;
      						cnt2++;
      						break;
      					}
      				}
      				if (q == -1){
      					q = -1;
      					cnt2++;
      				}
      				if (cnt1 + cnt2 >= 3 && C[j] == C[pos]){
      					count += (cnt1+cnt2);
      					j = p-1;
      					pos = q+1;
      				}
      				else{
      					break;
      				}
      			}
      			pos--;
      		}
      		if (count > max_count){
      			max_count=count;
      		}
      	}
      }
      cout << max_count;
      return 0;
}