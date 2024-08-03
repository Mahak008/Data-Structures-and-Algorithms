// Leetcode - 846

bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize) {
        return false;
    }

    map<int, int> mp;
    for (int i = 0; i < hand.size(); i++) {
        mp[hand[i]]++;
    }

    while (!mp.empty()) {
        int curr = mp.begin()->first;

        for (int i = 0; i < groupSize; i++) {
            if (mp[curr + i] == 0) {
                return false;
            }

            mp[curr + i]--;

            if (mp[curr + i] == 0) {
                mp.erase(curr + i);
            }
        }
    }

    return true;
}

// Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
