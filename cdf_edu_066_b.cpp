// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA. Double cannot be used
// for comparisons use div and mod instead. 
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
#define auth set <lld> :: iterator
#define pb push_back
#define POW 4294967295
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      lld sum = 0;
      stack <lld> stk, val;
      for(lld i = 0; i < n; i += 1){
      	string s;
      	cin >> s;
      	if (s == "for"){
      		lld r;
      		cin >> r;
      		stk.push(0);val.push(r);
      	}
      	if (s == "end"){
      		lld x = stk.top(); stk.pop();
      		lld r = val.top(); val.pop();
      		lld res = x*r;
      		if (stk.empty()){
      			sum += res;
      			if (sum > POW)
      				{cout << "OVERFLOW!!!"; return 0;}
      		}
      		else{
      			lld x = stk.top();
      			stk.pop();
      			x += res;
      			if (x > POW)
      				{cout << "OVERFLOW!!!"; return 0;}
      			stk.push(x);
      		}
      	}
      	if (s == "add"){
      		if (stk.empty()){
      			sum++;
      			if (sum > POW)
      				{cout << "OVERFLOW!!!"; return 0;}
      		}
      		else{
      			lld x = stk.top();
      			stk.pop();
      			x++;
      			if (x > POW)
      				{cout << "OVERFLOW!!!"; return 0;}
      			stk.push(x);
      		}
      	}
      }
      cout << sum;
      return 0;
}