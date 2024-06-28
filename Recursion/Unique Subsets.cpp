class Solution {
  public:
    void solve(vector<int> arr, vector<int> output, int ind, set<vector<int>>& s) {
      int n = arr.size();
        
      if(ind >= n) {
        sort(output.begin(), output.end());
        s.insert(output);
        return;
      }
        
      solve(arr, output, ind + 1, s);
        
      int ele = arr[ind];
      output.push_back(ele);
      solve(arr, output, ind + 1, s);
    }
    
    vector<vector<int>> AllSubsets(vector<int> arr, int n) {
      vector<vector<int>> ans;
      set<vector<int>> s;
      vector<int> output;
      int ind = 0;
        
      solve(arr, output, ind, s);
       
      for(auto subset : s) {
        ans.push_back(subset);
      }
        
      return ans;
    }
};

// Input: N = 3, arr[] = {2,1,2}
// Output:(),(1),(1 2),(1 2 2),(2),(2 2)
