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
	queue <char> c_que;
	queue <char> d_que;
	for(lld i = 0; i < s.length(); i++){
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'y'|| s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y'){
			continue;
		}
		c_que.push(s[i]);
	}
	while (!c_que.empty()){
		char p = c_que.front();
		c_que.pop();
		if (p >= 'A' && p <= 'Z'){
			p = p + 32;
		}
		d_que.push('.');
		d_que.push(p);
	}
	while (!d_que.empty()){
		cout << d_que.front();
		d_que.pop();
	}
	return 0;
}