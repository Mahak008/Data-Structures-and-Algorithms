#include <bits/stdc++.h> 

void solve(string str, string output, int index, vector<string> &ans) {
	int n = str.length();
	if(index >= n) {
		if(!output.empty()){
			ans.push_back(output);
		}
		return;
	}

	solve(str, output, index + 1, ans);

	int ele = str[index];
	output += ele;
	solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str){
	vector<string>ans;
	string output = "";
	int index = 0;
	solve(str, output, index, ans);
	return ans;
}


// Input: abc
// Output: a ab abc ac b bc c
// No empty string
