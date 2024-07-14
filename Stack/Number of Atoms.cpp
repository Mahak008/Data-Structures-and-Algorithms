// Leetcode - 726

string countOfAtoms(string formula) {
    int n = formula.length();
    stack<unordered_map<string, int>> st;

    st.push(unordered_map<string, int>());

    int i = 0;
    while (i < n) {
        if (formula[i] == '(') {
            st.push(unordered_map<string, int>());
            i++;
        } else if (formula[i] == ')') {
            unordered_map<string, int> curr = st.top();
            st.pop();
            i++;

            string mul;
            while (i < n && isdigit(formula[i])) {
                mul.push_back(formula[i]);
                i++;
            }

            int mulInt = mul.empty() ? 1 : stoi(mul);
            for (auto& it : curr) {
                string ele = it.first;
                int count = it.second;

                curr[ele] = count * mulInt;
            }

            // merge it to top of stack
            for (auto& it : curr) {
                string ele = it.first;
                int count = it.second;

                st.top()[ele] += count;
            }
        } else {
            string currEle;
            currEle.push_back(formula[i]);
            i++;

            while (i < n && isalpha(formula[i]) && islower(formula[i])) {
                currEle.push_back(formula[i]);
                i++;
            }

            string currCnt;
            while (i < n && isdigit(formula[i])) {
                currCnt.push_back(formula[i]);
                i++;
            }

            int currCntInt = currCnt.empty() ? 1 : stoi(currCnt);
            st.top()[currEle] += currCntInt;
        }
    }

    // stack will have only one element at the top
    unordered_map<string, int> topMap = st.top();
    map<string, int> sortedMap(topMap.begin(), topMap.end());

    string res;
    for (auto& it : sortedMap) {
        string ele = it.first;
        res += ele;

        int cnt = it.second;

        if (cnt > 1) {
            res += to_string(cnt);
        }
    }

    return res;
}

// Input: formula = "K4(ON(SO3)2)2"
// Output: "K4N2O14S4"
