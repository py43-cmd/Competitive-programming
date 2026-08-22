#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto &x:a)cin >> x;
    vector<int>prefix(n,0);
    prefix[0]=a[0];
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+a[i];
    }
    int mini=1e9;
    for(int i=0;i<n-1;i++){
        mini=min(mini,abs(prefix[i]-(prefix[n-1]-prefix[i])));
    }
    cout << mini << endl;
}