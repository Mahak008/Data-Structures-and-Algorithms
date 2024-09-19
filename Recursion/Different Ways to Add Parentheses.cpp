// Leetcode - 241

vector<int> solve(string s) {
    int n = s.length();
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
            vector<int> left = solve(s.substr(0, i));
            vector<int> right = solve(s.substr(i + 1));

            for (int& x : left) {
                for (int& y : right) {
                    if (s[i] == '+') {
                        ans.push_back(x + y);
                    } else if (s[i] == '-') {
                        ans.push_back(x - y);
                    } else {
                        ans.push_back(x * y);
                    }
                }
            }
        } else {
            continue;
        }
    }

    if (ans.empty()) {
        ans.push_back(stoi(s));
    }

    return ans;
}

vector<int> diffWaysToCompute(string exp) { 
  return solve(exp); 
}

// Input: expression = "2*3-4*5"
// Output: [-34,-14,-10,-10,10]
// Explanation:
// (2*(3-(4*5))) = -34 
// ((2*3)-(4*5)) = -14 
// ((2*(3-4))*5) = -10 
// (2*((3-4)*5)) = -10 
// (((2*3)-4)*5) = 10
