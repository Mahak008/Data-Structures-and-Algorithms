// Leetcode - 621

int leastInterval(vector<char>& tasks, int n) {
    vector<int> alpha(26, 0);
    for (char& ch : tasks) {
        alpha[ch - 'A']++;
    }

    int time = 0;
    priority_queue<int> pq;

    for (int i = 0; i < 26; i++) {
        if (alpha[i] > 0) {
            pq.push(alpha[i]);
        }
    }

    while (!pq.empty()) {
        vector<int> temp;

        for (int i = 1; i <= n + 1; i++) {
            if (!pq.empty()) {
                int freq = pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
            }
        }

        for (int& f : temp) {
            if (f > 0) {
                pq.push(f);
            }
        }

        if (pq.empty()) {
            time += temp.size();
        } else {
            time += n + 1;
        }
    }

    return time;
}

// Time - O(N)
// Space - O(1)

// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
