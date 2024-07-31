string longestCommonPrefix(vector<string> arr) {
    string ans = "";
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<arr[0].size(); i++){
        if(arr[0][i] == arr[arr.size()-1][i]){
            ans.push_back(arr[0][i]);
        }
        else{
            break;
        }
    }
    return ans.size()<=0 ? "-1" : ans;
}

// Input: arr[] = ["geeksforgeeks", "geeks", "geek", "geezer"]
// Output: gee
// Explanation: "gee" is the longest common prefix in all the given strings.
