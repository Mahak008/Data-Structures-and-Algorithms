// Leetcode - 2244

int minimumRounds(vector<int>& tasks) {
    int rounds = 0;
    int n = tasks.size();
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        mp[tasks[i]]++;
    }

    for (const auto& it : mp) {
        if (it.second < 2) {
            return -1;
        } else {
            rounds += (it.second + 2) / 3;
        }
    }

    return rounds;
}

// Input: tasks = [2,3,3]
// Output: -1
// Explanation: There is only 1 task of difficulty level 2, but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.
