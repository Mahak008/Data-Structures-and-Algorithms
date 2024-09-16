// Leetcode - 539

int findMinDifference(vector<string>& timePoints) {
    int n = timePoints.size();
    vector<int> time;

    for (const string& s : timePoints) {
        int colonPos = s.find(':');
        int h = stoi(s.substr(0, colonPos));
        int m = stoi(s.substr(colonPos + 1));

        int min = 60 * h + m;
        time.push_back(min);
    }

    sort(time.begin(), time.end());

    int mini = INT_MAX;

    for (int i = 1; i < n; i++) {
        mini = min(mini, time[i] - time[i - 1]);
    }

    int wrapAroundDifference = 1440 - (time[n - 1] - time[0]);
    mini = min(mini, wrapAroundDifference);

    return mini;
}

// Input: timePoints = ["23:59","00:00"]
// Output: 1
