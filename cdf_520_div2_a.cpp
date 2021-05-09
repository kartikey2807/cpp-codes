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
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      lld s = 0, e = 0;
      vector<lld>start;
      vector <lld> end;
      for(lld i = 1; i < n; i += 1){
      	if (A[i] == A[i-1] + 1){
      		e+= 1;
      	}
      	else{
      		start.push_back(s);
      		end.push_back(e);
      		s = i;
      		e = i;
      	}
      }
      		start.push_back(s);
      		end.push_back(e);
      lld max = MIN;
      lld len;
      for(lld i = 0; i < start.size(); i += 1){
      	if (A[start[i]] == 1 || A[end[i]] == 1000){
      		if (A[start[i]] == 1 && A[end[i]] == 1000){
      			len = end[i]-start[i];
      			len+= 1;
      		}
      		else{
      			len = end[i]-start[i];
      		}
      	}
      	else{
      		len = end[i] - start[i] - 1;
      	}
      	if (len > max){
      		max=len;
      	}
      }
      if (max == -1){
      	cout << "0\n";
      }
      else{
      	cout << max << "\n";
      }
      return 0;
}