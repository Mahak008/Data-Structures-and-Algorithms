// Leetcode - 874

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    unordered_set<string> st;
    for (vector<int>& ob : obstacles) {
        string key = to_string(ob[0]) + "_" + to_string(ob[1]);
        st.insert(key);
    }

    int x = 0, y = 0, maxDis = 0;

    // Poiting to North
    pair<int, int> dir = {0, 1};

    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == -2) { // Left 90deg
            dir = {-dir.second, dir.first};
        } else if (commands[i] == -1) {
            dir = {dir.second, -dir.first};
        } else {
            for (int step = 0; step < commands[i]; step++) {
                int newX = x + dir.first;
                int newY = y + dir.second;

                string nextKey = to_string(newX) + "_" + to_string(newY);

                if (st.find(nextKey) != st.end()) {
                    break;
                }

                x = newX;
                y = newY;
            }
        }

        maxDis = max(maxDis, x * x + y * y);
    }

    return maxDis;
}

// Input: commands = [4,-1,3], obstacles = []
// Output: 25

// Explanation: The robot starts at (0, 0):
// 1. Move north 4 units to (0, 4).
// 2. Turn right.
// 3. Move east 3 units to (3, 4).
// The furthest point the robot ever gets from the origin is (3, 4), which squared is 32 + 42 = 25 units away.
