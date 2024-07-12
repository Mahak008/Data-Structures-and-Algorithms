// Leetcode - 1598

int minOperations(vector<string>& logs) {
    vector<string> log;
    for (auto i : logs) {
        if (i == "../") {
            if (!log.empty()) {
                log.pop_back();
            }
        } else if (i != "./") {
            log.push_back(i);
        }
    }

    return log.size();
}

// "../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
// "./" : Remain in the same folder.
// "x/" : Move to the child folder named x (This folder is guaranteed to always exist).

// Input: logs = ["d1/","d2/","../","d21/","./"]
// Output: 2
