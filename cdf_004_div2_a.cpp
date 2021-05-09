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
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      string s;
      while(std::getline(std::cin, s)){
      	lld L = s.length();
      	char c[L];
      	lld k = 0;
      	char prev = 'a';
      	for(lld i = 0; i < L; i++){
      		if (s[i] == ' '){
      			lld p = -1;
      			for(lld j = i; j < L; j++){
      				if (s[j] != ' '){
      					p = j;
      					break;
      				}
      			}
      			if (p != -1){
      				if (prev >= 'a' && prev <= 'z'){
      					if (s[p] >= 'a' && s[p] <= 'z'){
      						c[k]= ' ';
      						k++;
      						c[k]=s[p];
      						k++;
      					}
      					else{
      						c[k]=s[p];
      						k++;
      					}
      				}
      				else{
      					if (s[p] >= 'a' && s[p] <= 'z'){
      						c[k]= ' ';
      						k++;
      						c[k]=s[p];
      						k++;
      					}
      				}
      				i = p;
      			}
      			else{
      				i = L;
      			}
      		}
      		else{
      			c[k] = s[i];
      			k++;
      		}
      	}
      	for(lld i = 0; i < k; i += 1){
      		cout << c[i];
      		if (i+1 < k && (c[i] < 'a' || c[i] > 'z') && c[i] != ' ' && c[i+1] != ' '){
      			cout << " ";
      		}
      	}
      }
      return 0;
}