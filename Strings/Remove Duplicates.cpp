string removeDups(string str) {
    unordered_set<char>s;
    string st = "";
    
    for (char c : str) {
        if (s.find(c) == s.end()) {
            s.insert(c);
            st += c;
        }
    }
        
    return st;
}

// Input: str = "gfg"
// Output: "gf"
