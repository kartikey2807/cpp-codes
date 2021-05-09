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
vector <lld> add (vector <lld> a, vector <lld> b)
{
	if (a.empty()) return b;
	if (b.empty()) return a;
	vector <lld> x;
	lld sum = 0,carry = 0;
	lld len1 = a.size()-1;
	lld len2 = b.size()-1;
	while(len1 >= 0 && len2 >= 0){
		sum = a[len1]+b[len2]+carry;
		x.push_back(sum%10);
		carry = sum/10;
		len2--;
		len1--;
	}
	while(len1 >= 0){
		sum = a[len1]+carry;
		x.push_back(sum%10);
		carry = sum/10;
		len1--;
	}
	while(len2 >= 0){
		sum = b[len2]+carry;
		x.push_back(sum%10);
		carry = sum/10;
		len2--;
	}
	if (carry > 0)
		x.push_back(carry);
	reverse(x.begin(),x.end());
	return x;
}
void first_ (lld A[], lld n)
{
	vector <lld> a, b;
	for(lld i = 0; i < (n/2); i += 1)
		a.push_back(A[i]);
	for(lld i = (n/2); i < n; i += 1)
		b.push_back(A[i]);
	lld j = 0;
	while(b[j] == 0 && j < (n/2))
		j++;
	vector <lld> c;
	vector <lld> d;
	c = a;
	for(lld i = 0; i < j; i += 1)
		c.push_back(b[i]);
	for(lld i = j; i<n/2; i += 1)
		d.push_back(b[i]);
	vector <lld> v1 = add(c,d);

	j = (n/2)-1;
	while(a[j] == 0 && j >= 0)
		j--;
	vector <lld> e;
	vector <lld> f;
	for(lld i = j; i<n/2; i += 1)
		e.push_back(a[i]);
	for(lld i = 0; i<n/2; i += 1)
		e.push_back(b[i]);
	for(lld i = 0; i < j; i += 1)
		f.push_back(a[i]);
	vector <lld> v2 = add(e,f);
	if (v1.size() > v2.size()){
      	foi(i,v2.size())
      		cout << v2[i];
      }
      else{
      	if (v1.size() < v2.size()){
      		foi(i,v1.size())
      			cout << v1[i];
      	}
      	else{
      		lld f = 0;
      		for(lld i = 0; i < v2.size(); i += 1){
      			if (v1[i] < v2[i]){
      				f = 1;
      				break;
      			}
      			if (v2[i] < v1[i]){
      				f = 2;
      				break;
      			}
      		}
      		if (f == 1) foi(i,v1.size()) cout << v1[i];
      		if (f == 2) foi(i,v2.size()) cout << v2[i];
      		if (f == 0) foi(i,v2.size()) cout << v2[i];
      	}
      }
}
vector <lld> first (lld A[], lld n)
{
	vector <lld> a, b;
	for(lld i = 0; i < (n/2); i += 1)
		a.push_back(A[i]);
	for(lld i = (n/2); i < n; i += 1)
		b.push_back(A[i]);
	lld j = 0;
	while(b[j] == 0 && j < (n/2)+1)
		j++;
	vector <lld> c;
	vector <lld> d;
	c = a;
	for(lld i = 0; i < j; i += 1)
		c.push_back(b[i]);
	for(lld i = j; i < (n/2)+1; i += 1)
		d.push_back(b[i]);
	vector <lld> v1 = add(c,d);

	j = (n/2)-1;
	while(a[j] == 0 && j >= 0)
		j--;
	vector <lld> e;
	vector <lld> f;
	for(lld i = j; i<n/2; i += 1)
		e.push_back(a[i]);
	for(lld i = 0; i < (n/2)+1; i += 1)
		e.push_back(b[i]);
	for(lld i = 0; i < j; i += 1)
		f.push_back(a[i]);
	vector <lld> v2 = add(e,f);
	if (v1.size() > v2.size()){
      	return v2;
      }
      else{
      	if (v1.size() < v2.size()){
      		return v1;
      	}
      	else{
      		lld f = 0;
      		for(lld i = 0; i < v2.size(); i += 1){
      			if (v1[i] < v2[i]){
      				f = 1;
      				break;
      			}
      			if (v2[i] < v1[i]){
      				f = 2;
      				break;
      			}
      		}
      		if (f == 1) return v1;
      		if (f == 2) return v2;
      		if (f == 0) return v2;
      	}
      }
}
vector <lld> second (lld A[], lld n)
{
	vector <lld> a, b;
	for(lld i = 0; i < (n/2)+1; i += 1)
		a.push_back(A[i]);
	for(lld i = (n/2)+1; i < n; i += 1)
		b.push_back(A[i]);
	lld j = 0;
	while(b[j] == 0 && j < (n/2))
		j++;
	vector <lld> c;
	vector <lld> d;
	c = a;
	for(lld i = 0; i < j; i += 1)
		c.push_back(b[i]);
	for(lld i = j; i<n/2; i += 1)
		d.push_back(b[i]);
	vector <lld> v1 = add(c,d);

	j = (n/2);
	while(a[j] == 0 && j >= 0)
		j--;
	vector <lld> e;
	vector <lld> f;
	for(lld i = j; i < (n/2)+1; i += 1)
		e.push_back(a[i]);
	for(lld i = 0; i<n/2; i += 1)
		e.push_back(b[i]);
	for(lld i = 0; i < j; i += 1)
		f.push_back(a[i]);
	vector <lld> v2 = add(e,f);
	if (v1.size() > v2.size()){
      	return v2;
      }
      else{
      	if (v1.size() < v2.size()){
      		return v1;
      	}
      	else{
      		lld f = 0;
      		for(lld i = 0; i < v2.size(); i += 1){
      			if (v1[i] < v2[i]){
      				f = 1;
      				break;
      			}
      			if (v2[i] < v1[i]){
      				f = 2;
      				break;
      			}
      		}
      		if (f == 1) return v1;
      		if (f == 2) return v2;
      		if (f == 0) return v2;
      	}
      }
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      string s;
      cin >> n >> s;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	A[i] = (lld)s[i]-48;
      }
      if (n%2 == 0){
      	first_(A,n);	
      }
      else{
      	vector <lld> a = first(A,n);
      	vector <lld> b = second(A,n);
      	if (a.size() < b.size()){
      		foi(i,a.size())
      			cout << a[i];
      	}
      	else{
      		if (b.size() < a.size()){
      			foi(i,b.size())
      				cout << b[i];
      		}
      		else{
      			lld f = 0;
      			for(lld i = 0; i < a.size(); i += 1){
      				if (a[i] < b[i]){
      					f = 1;
      					break;
      				}
      				if (b[i] < a[i]){
      					f = 2;
      					break;
      				}
      			}
      			if (f == 1) foi(i,a.size()) cout<<a[i];
      			if (f == 2)	foi(i,b.size()) cout<<b[i];
      			if (f == 0) foi(i,b.size()) cout<<b[i];
      		}
      	}
      }
      return 0;
}