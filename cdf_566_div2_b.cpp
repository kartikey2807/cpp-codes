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
      lld r, c;
      cin >> r >> c;
      char dda[r][c];
      lld flag[r][c];
      for(lld i = 0; i < r; i += 1){
      	for(lld j = 0; j < c; j += 1){
      		cin >> dda[i][j];
      		flag[i][j]  = 0;
      	}
      }
      lld f = 0;
      for(lld i = 0; i < r; i += 1){
      	for(lld j = 0; j < c; j += 1){
      		if (dda[i][j] == '*'){
      			lld count_l = 0, count_r = 0, count_u = 0, count_d = 0;
      			for(lld k = j-1; k >= 0; k -= 1){
      				if (dda[i][k] == '*'){
      					count_l += 1;
      				}
      				else{
      					break;
      				}
      			}
      			for(lld k = j+1; k  < c; k += 1){
      				if (dda[i][k] == '*'){
      					count_r += 1;
      				}
      				else{
      					break;
      				}
      			}
      			for(lld k = i-1; k >= 0; k -= 1){
      				if (dda[k][j] == '*'){
      					count_u += 1;
      				}
      				else{
      					break;
      				}
      			}
      			for(lld k = i+1; k  < r; k += 1){
      				if (dda[k][j] == '*'){
      					count_d += 1;
      				}
      				else{
      					break;
      				}
      			}
      			if (count_d > 0 && count_u > 0 && count_l > 0 && count_r > 0){
      				flag[i][j]  = 1;
      				for(lld k = j-1; k >= 0; k -= 1){
      					if (count_l <= 0){
      						break;
      					}
      					flag[i][k] = 1;
      					count_l--;
      				}
      				for(lld k = j+1; k  < c; k += 1){
      					if (count_r <= 0){
      						break;
      					}
      					flag[i][k] = 1;
      					count_r--;
      				}
      				for(lld k = i-1; k >= 0; k -= 1){
      					if (count_u <= 0){
      						break;
      					}
      					flag[k][j] = 1;
      					count_u--;
      				}
      				for(lld k = i+1; k  < r; k += 1){
      					if (count_d <= 0){
      						break;
      					}
      					flag[k][j] = 1;
      					count_d--;
      				}
      				f = 1;
      				break;
      			}
      		}
      	}
      	if (f == 1){
      		break;
      	}
      }
      if (f == 1){
      	lld g = 1;
      	for(lld i = 0; i < r; i += 1){
      		for(lld j = 0; j < c; j += 1){
      			if (flag[i][j] == 0 && dda[i][j] == '*'){
      				g = 0;
      				break;
      			}
      		}
      		if (g == 0){
      			break;
      		}
      	}
      	if (g == 1){
      		cout << "YES\n";
      	}
      	else{
      		cout <<  "NO\n";
      	}
      }
      else{
      		cout <<  "NO\n";
      }
      return 0;
}