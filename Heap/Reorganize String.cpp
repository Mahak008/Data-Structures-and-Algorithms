// Leetcode - 767

typedef pair<int, char> p;
string reorganizeString(string s) {
    int n = s.length();
    vector<int> v(26, 0);

    for (char& ch : s) {
        v[ch - 'a']++;

        if (v[ch - 'a'] > (n + 1) / 2) {
            return "";
        }
    }

    priority_queue<p, vector<p>> pq;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (v[ch - 'a'] > 0) {
            pq.push({v[ch - 'a'], ch});
        }
    }

    string ans = "";

    while (pq.size() >= 2) {
        auto p1 = pq.top();
        pq.pop();

        auto p2 = pq.top();
        pq.pop();

        ans.push_back(p1.second);
        p1.first--;

        ans.push_back(p2.second);
        p2.first--;

        if (p1.first > 0) {
            pq.push(p1);
        }

        if (p2.first > 0) {
            pq.push(p2);
        }
    }

    if (!pq.empty()) {
        ans.push_back(pq.top().second);
    }

    return ans;
}

// Input: s = "aab"
// Output: "aba"
