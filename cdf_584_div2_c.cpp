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
      	lld n;
      	string s;
      	cin >> n >> s;
      	lld A[n];
      	for(lld i = 0; i < n; i += 1){
      		A[i] = (lld)s[i]-48;
      	}
      	lld ans = MAX;
      	for(lld i = 0; i < n; i += 1){
      		ans = min(ans,A[i]);
      	}
      	lld p;
      	for(lld i = 0; i < n; i += 1){
      		if (A[i] == ans){
      			p = i;
      			break;
      		}
      	}
      	if (p != 0){
      		lld f = 1;
      		for(lld i = 1; i < p; i += 1){
      			if (A[i] < A[i-1]){
      				f = 0;
      				break;
      			}
      		}
      		if (f == 0){
      			cout << "-\n";
      			continue;
      		}
      		else{
      			lld g = 1;
      			lld low = 0;
      			lld cur = p;
      			lld upp = p-1;
      			vector <lld> c1, c2;
      			for(lld i = 0; i < p; i += 1){
      				c2.push_back(i);
      			}
      			for(lld i = p; i < n; i += 1){
      				if (A[i] >= A[upp]){
      					upp = i;
      					c2.push_back(i);
      				}
      				else{
      					if (A[i] <= A[low]){
      						if (A[i] >= A[cur]){
      							cur = i;
      							c1.push_back(i);
      						}
      						else
      							g = 0;
      					}
      					else
      						g = 0;
      				}
      			}
      			if (g == 0)
      				cout << "-\n";
      			else{
      				lld B[n];
      				for(lld i = 0; i < c1.size(); i += 1)
      					B[c1[i]] = 1;
      				for(lld i = 0; i < c2.size(); i += 1)
      					B[c2[i]] = 2;
      				foi(i,n) cout << B[i];
      				cout << "\n";
      			}
      		}
      	}
      	else{
      		lld Temp[n];
      		foi(i,n)
      			Temp[i] = A[i];
      		sort(Temp,Temp+n);
      		lld pos = -1;
      		for(lld i = 0; i < n; i += 1){
      			if (Temp[i] != A[i]){
      				pos = i;
      				break;
      			}
      		}
      		if (pos == -1){
      			foi(i,n) cout << "1";
      			cout << "\n";
      		}
      		else{
      			lld g = 1;
      			lld low = pos;
      			lld upp = pos;
      			lld cur = 0;
      			vector <lld> c1, c2;
      			for(lld i = 0; i < n; i += 1){
      				if (A[i] >= A[upp]){
      					upp = i;
      					c2.push_back(i);
      				}
      				else{
      					if (A[i] <= A[low]){
      						if (A[i] >= A[cur]){
      							cur = i;
      							c1.push_back(i);
      						}
      						else
      							g = 0;
      					}
      					else
      						g = 0;
      				}
      			}
      			if (g == 0)
      				cout << "-\n";
      			else{
      				lld B[n];
      				for(lld i = 0; i < c1.size(); i += 1)
      					B[c1[i]] = 1;
      				for(lld i = 0; i < c2.size(); i += 1)
      					B[c2[i]] = 2;
      				foi(i,n) cout << B[i];
      				cout << "\n";
      			}
      		}
      	}
      }
      return 0;
}