#include<bits/stdc++.h>
using namespace std;
int main(){
     int t;
     cin >> t;
     unordered_map<string ,int>mp;
     int maxi=0;
     for(int i=0;i<t;i++){
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        sort(s.begin(),s.end());
        
        mp[s]++;

        

    } 
    for(auto x: mp){
         maxi= max(maxi,x.second);
    }
    cout << maxi << endl;
}