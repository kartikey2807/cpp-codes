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
      string s;
      cin >> s;
      lld m;
      cin >> m;
      lld L = s.length();
      for(lld i = 0; i < m; i += 1){
      	lld l, r, k;
      	cin >> l >> r >> k;
      	if (l != r){
      		lld x = k%(r-l+1);
      		if (x  != 0){
      			l-=1;
      			r-=1;
      			queue <char> q;
      			for(lld j = r; j >= l; j -= 1){
      				q.push(s[j]);
      			}
      			lld count = 0;
      			while(true){
      				if (count == x){
      					break;
      				}
      				char c = q.front();
      				q.pop();
      				q.push(c);
      				count += 1;
      			}
      			stack <char> rev;
      			while(!q.empty()){
      				rev.push(q.front());
      				q.pop();
      			}
      			string manip = "";
      			for(lld j = 0; j <  l; j += 1){
      				manip += s[j];
      			}
      			while(!rev.empty()){
      				char c = rev.top();
      				rev.pop();
      				manip += c;
      			}
      			for(lld j = r+1;j < L; j += 1){
      				manip += s[j];
      			}
      			s = manip;
      		}
      	}
      }
      cout <<s;
      return 0;
}