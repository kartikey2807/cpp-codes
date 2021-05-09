#include <bits/stdc++.h>
#include <set>
#include <map>
#include <string>
using namespace std;
typedef long long int lld;
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
double getComb (double n, double x){
    if (x > n){
        return 0;
    }
    else{
        double r = 1.0;
        for(double i = 1.0; i<=x; i += 1){
            double a = n-i+1;
            double b = a / i;
            r*=b;
        }
        return r;
    }
}
void merge(lld crr[], lld brr[], lld arr[], lld l, lld m, lld r){
    lld i , j ,  k;
    lld n1 = m-l+1; 
    lld n2 = r - m;
    lld L1[n1],L2[n1],L3[n1];
    lld R1[n2],R2[n2],R3[n2];
    for (i = 0; i < n1; i++){
        L1[i] = arr[l + i];
        L2[i] = brr[l + i];
        L3[i] = crr[l + i];
    }
    for (j = 0; j < n2; j++){
        R1[j] = arr[m+1+j];
        R2[j] = brr[m+1+j];
        R3[j] = crr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L1[i] <= R1[j]){
            arr[k] = L1[i];
            brr[k] = L2[i];
            crr[k] = L3[i];
            i++;
        }
        else{
            arr[k] = R1[j];
            brr[k] = R2[j];
            crr[k] = R3[j];
            j++;
        }
        k++;
    }
        while (i   <   n1){
            arr[k] = L1[i];
            brr[k] = L2[i];
            crr[k] = L3[i];
            i++;
            k++;
        }
        while (j   <   n2){
            arr[k] = R1[j];
            brr[k] = R2[j];
            crr[k] = R3[j];
            j++;
            k++;
        }
}
void mergeSort(lld crr[], lld brr[], lld arr[], lld l, lld r){
    if (l < r)
    {
        lld m = l+(r-l)/2;
        mergeSort(crr, brr, arr,l, m);
        mergeSort(crr, brr,arr,m+1,r);
        merge(crr, brr, arr, l, m, r);
    } 
} 
int main () {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("inputf.in",  "r",  stdin);
    // for writing output to output.txt
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld n, m;
    cin >> n;
    cin >> m;
    lld x, L;
    cin >> x;
    lld k, p;
    L = n* n;
    lld X[L];
    lld Y[L];
    lld i, j;
    char dda[n][m];
    set <char> pct; // present characters
    set <char> rct; // roundup characters
    k = 0;
    for(i = 0; i<n; i+=1){
    for(j = 0; j<m; j+=1){
        cin >> dda[i][j];
    pct.insert(dda[i][j]);
    if (dda[i][j] == 'S'){
        X[k] = i;
        Y[k] = j;
        k++;
    }
    }
    }
    double radi =pow(x,2);
    char c;
    for(i = 0; i<n; i+=1){
    for(j = 0; j<m; j+=1){
    for(p = 0; p<k; p+=1){
        double dist = pow((i - X[p]), 2) + pow((j - Y[p]), 2);
        if (dist <= radi){
            c = dda[i][j];
            rct.insert(c);
            break;
        }
    }
    }
    }
    lld q, g;
    cin >> q;
    string s;
    cin >> s;
    g = 1;
    lld count = 0;
    for(i = 0; i<q; i+=1){
        if (s[i] <= 'z' && s[i] >= 'a'){
            if (pct.count(s[i])){

            }
            else{
                g = 0;
                break;
            }
        }
        else{
            c = (char)(s[i] +32);
            if (pct.count ( c )){
                if (k == 0){
                    g = 0;
                    break;
                }
                if(rct.count(c)){

                }
                else{
                    count  +=  1;
                }
            }
            else{
                g = 0;
                break;
            }
        }
    }
        if (g == 1){
            cout << count <<"\n";
        }
        else{
            cout << "-1"  <<"\n";
        }
    return 0;
}