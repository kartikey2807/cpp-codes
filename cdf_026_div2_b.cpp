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
	lld i;
	stack  <char> stk;
	foi(i,s.length()){
		if (s[i] == '('){
			stk.push(s[i]);
		}
		else{
			if (!stk.empty()){
				char p = stk.top();
				if (p == '('){
					stk.pop();
				}
				else{
					stk.push(s[i]);
				}
			}
			else{
				stk.push(s[i]);
			}
		}
	}
	cout << (s.length()- stk.size());
	return 0;
}