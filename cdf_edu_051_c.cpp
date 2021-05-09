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
      queue <lld> index[101];
      map <lld, lld> cnt;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	cnt[A[i]]++;
      	index[A[i]].push(i);
      }
      vector <lld> a, b;
      lld c = 0;
      lld vis[101];
      memset(vis, -1, sizeof(vis));
      for(lld i = 1; i <= 100; i += 1){
      	if (cnt[i] == 1){
      		if (c%2 == 0) a.push_back(i);
      		if (c%2 != 0) b.push_back(i);
      		c++;
      		vis[i] = 1;
      	}
      }
      lld len1 = a.size();
      lld len2 = b.size();
      if (len1 < len2){
      	for(lld i = 1; i <= 100; i += 1){
      		if (cnt[i] > 2){
      			a.push_back(i);
      			vis[i] = 1;
      			cnt[i]-= 1;
      			len1++;
      			while (cnt[i]){
      				b.push_back(i);
      				cnt[i]--;
      			}
      			break;
      		}
      	}
      }
      if (len2 < len1){
      	for(lld i = 1; i <= 100; i += 1){
      		if (cnt[i] > 2){
      			b.push_back(i);
      			vis[i] = 1;
      			cnt[i]-= 1;
      			len2++;
      			while (cnt[i]){
      				a.push_back(i);
      				cnt[i]--;
      			}
      			break;
      		}
      	}
      }
      if (len1  !=  len2)
      	cout << "NO";
      else {
      	cout <<"YES\n";
      	char ch[n];
      	for(lld i = 1; i <= 100; i += 1){
      		if (vis[i] == 1){
      			continue;
      		}
      		if (cnt[i] >= 2){
      			while (cnt[i]){
      				a.push_back(i);
      				cnt[i]--;
      			}
      		}
      	}
      	for(lld i = 0; i < a.size(); i += 1){
      		ch[index[a[i]].front()] = 'A';
      		index[a[i]].pop();
      	}
      	for(lld i = 0; i < b.size(); i += 1){
      		ch[index[b[i]].front()] = 'B';
      		index[b[i]].pop();
      	}
      	foi(i,n) cout << ch[i];
      }
      return 0;
}