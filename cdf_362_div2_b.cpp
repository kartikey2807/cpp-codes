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
lld sti_ (string x)
{
	lld ans = 0;
	for(lld i = 0; i < x.length(); i += 1){
		lld y = (char)x[i]-48;
		ans = (ans*10)+y;
	}
	return(ans);
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      string s;
      cin >> s;
      lld p, q;
      string t = "";
      string r = "";
      for(lld i = 0; i < s.length(); i += 1){
      	if (s[i] == 'e'){
      		p = i;
      		break;
      	}
      	t += s[i];
      }
      for(lld i = p+1; i<s.length(); i += 1){
      	r += s[i];
      }
      for(lld i = 0; i < t.length(); i += 1){
      	if (t[i] == '.'){
      		q = i;
      		break;
      	}
      }
      lld L = t.length();
      lld b = sti_(r);
      lld f = 0;
      while(b){
      	if (q+1 < L){
      		swap(t[q], t[q+1]);
      		q++;
      	}
      	else{
      		if (f == 0){
      			string temp = "";
      			for(lld i = 0; i < L-1; i += 1){
      				temp+=t[i];
      			}
      			t = temp;
      			f = 1;
      		}
      		t += '0';
      	}
      	b --;
      }
      lld flag = 0;
      for(lld i = 0; i < t.length(); i += 1){
      	if (t[i] == '.'){
      		flag = 1;
      		break;
      	}
      }
      if (flag == 0){
      	lld count = 0;
      	for(lld i = 0; i < t.length(); i += 1){
      		if (t[i] == '0'){
      			count++;
      		}
      	}
      	if (count == t.length()){
      		cout << "0";
      		return 0;
      	}
      	for(lld i = 0; i < t.length(); i += 1){
      		if (t[i] != '0'){
      			for(lld j = i; j < t.length(); j += 1){
      				cout << t[j];
      			}
      			break;
      		}
      	}
      }
      else{
      	lld count = 0;
      	for(lld i = 0; i < t.length(); i += 1){
      		if (t[i] == '0'){
      			count++;
      		}
      	}
      	if (count == t.length()-1){
      		cout << "0";
      		return 0;
      	}
      	lld len = t.length();
      	lld pos;
      	for(lld j = len-1; j >= 0; j -= 1){
      		if (t[j] == '.'){
      			pos = j-1;
      			break;
      		}
      		if (t[j] != '0'){
      			pos=j;
      			break;
      		}
      	}
      	string temp = "";
      	for(lld i = 0; i <=  pos;  i += 1){
      		temp+= t[i];
      	}
      	for(lld i = 0; i < temp.length(); i += 1){
      		if (temp[i] != '0'){
      			if (temp[i] == '.'){
      				cout << "0";
      			}
      			for(lld j = i; j < temp.length(); j += 1){
      				cout << temp[j];
      			}
      			break;
      		}
      	}
      }
      return 0;
}