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
      lld j = 0;
      lld A[n],B[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	if (A[i] % 2 != 0){
      		B[j] = A[i];
      		j++;
      	}
      }
      sort(B,B+j);
      lld f = 0;
      lld sum;
      for(lld i = 0; i < j; i += 1){
      	if (B[i] > 0){
      		f = 1;
      		break;
      	}
      }
      if (f == 0){
      	sum = B[j-1];
      }
      else{
      	sum = 0;
      	lld count = 0;
      	for(lld i = j-1; i >= 0; i -= 1){
      		if (B[i] > 0){
      			sum += B[i];
      			count++;
      		}
      	}
      	if (count % 2 == 0){
      		if (B[0] < 0){
      			lld i;
      			for(i = j-1; i >= 0; i -= 1){
      				if (B[i] < 0){
      					break;
      				}
      			}
      			sum = max(sum-B[i+1], sum+B[i]);
      		}
      		else{
      			sum-= B[0];
      		}
      	}
      }
      for(lld i = 0; i < n; i += 1){
      	if (A[i]%2 == 0 && A[i] > 0){
      		sum += A[i];
      	}
      }
      cout << sum;
      return 0;
}