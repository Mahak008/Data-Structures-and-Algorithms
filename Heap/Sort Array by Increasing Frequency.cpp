class MyComp {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

class Solution {
public:
    typedef pair<int, int> p;
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        priority_queue<p, vector<p>, MyComp> pq;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second, it->first});
        }

        vector<int> ans;
        while (!pq.empty()) {
            int freq = pq.top().first;
            while (freq) {
                ans.push_back(pq.top().second);
                freq--;
            }
            pq.pop();
        }

        return ans;
    }
};

// Input: 2, 3, 1, 3, 2
// Output: 1, 3, 3, 2, 2
