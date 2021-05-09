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
      	lld A[n];
      	for(lld i = 0; i < n; i += 1){
      		cin >> A[i];
      	}
      	lld w[k];
      	for(lld i = 0; i < k; i += 1){
      		cin >> w[i];
      	}
      	sort(A,A+n);
      	sort(w,w+k);
      	lld tot_sum = 0;
      	lld pos = n-1, mpos = n-k-1;
      	for(lld i =  0; i < k; i += 1){
      		lld sum = 0;
      		sum+=A[pos];
      		w[i]--;
      		if (w[i] != 0){
      			lld j;
      			for(j = mpos; j >= 0; j -= 1){
      				if (w[i] == 0){
      					break;
      				}
      				w[i]--;
      			}
      			mpos = j;
      			sum += A[mpos+1];
      		}
      		else{
      			sum += A[pos];
      		}
      		pos--;
      		tot_sum += sum;
      	}
      	cout << tot_sum << "\n";
      }
      return 0;
}