#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        set<int> st;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            st.insert(a[i]);
        }

        // duplicate exists
        if (st.size() < n) {
            cout << -1 << '\n';
            continue;
        }

        sort(a.rbegin(), a.rend());

        for (int x : a) cout << x << " ";
        cout << '\n';
    }

    return 0;
}