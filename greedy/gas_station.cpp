// Gas Station
// Solved
// Time Limit: 1 sec
// Memory: 256 MB
// Description
// Imagine you are managing a super busy gas station alone where vehicles stop for refuelling. The shop opens at ( t = 0 ) and from ( t = 1 ) onwards vehicles start to arrive at different times independently and may also have different tolerance for waiting at the station before getting frustrated and moving on to the different gas stations if not served within the waiting interval.

// You are the only one in charge of the station who is juggling between multiple different chores at the station office and hence you would like to minimize your total visits in a day at the refuelling pumps such that no vehicles leave the gas station without refuelling. Assume, at any time t, if you start refuelling the waiting vehicles, you will always be able to release all of them instantaneously, no matter how many vehicles have crowded the place.

// Now if you are given the arrival times and the tolerance for waiting of every vehicle beforehand, can you report the minimum number of total visits you’re gonna make at the refuelling pumps by the end of the day?

// Input Format
// The first line of the test case contains an integer N - total number of vehicles.
// Each of the next N lines contains two integers A and W, arriving time and tolerance time of a particular vehicle which are represented by some purely hypothetical values measured in some suitable unit (maybe minute).

// E.g. if some vehicle has A = 34 & W = 2, you can refuel it at ( t = 34 ) or at ( t = 35 ) or at ( t = 36 ).

// Output Format
// Print the minimum number of visits to the refuelling pumps.

// Constraints
// 0 ≤ N ≤ 2 * 105
// 0 < A, the arrival time ≤ 108
// 0 ≤ W, the maximum waiting time ≤ 104

//
#include<bits/stdc++.h>
using namespace std;
int main(){
     int n;
     cin >> n;
     vector<pair<long long ,long long >>result;
    for(int i=0;i<n;i++){
        int a,w;
        cin >> a >> w;
        result.push_back({w+a,a});

    }
    sort(result.begin(),result.end());
    long long  last=-1;
    int cover=0;
    for(int i=0;i<n;i++){
         if(last<result[i].second){
             cover++;
             last= result[i].first;
         }
    }
    cout <<  cover  << endl;


}