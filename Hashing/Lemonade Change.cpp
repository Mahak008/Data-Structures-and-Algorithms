// Leetcode - 860
  
bool lemonadeChange(vector<int>& bills) {
    unordered_map<int, int> mp;
    bool flag = false;

    for (int i = 0; i < bills.size(); i++) {
        if (bills[i] == 10) {
            if (mp[5] >= 1) {
                mp[5]--;
                flag = true;
            } else {
                return false;
            }
        } else if (bills[i] == 20) {
            if (mp[10] >= 1 && mp[5] >= 1) {
                mp[5]--;
                mp[10]--;
                flag = true;
            } else if (mp[5] >= 3) {
                mp[5] -= 3;
                flag = true;
            } else {
                return false;
            }
        }
        mp[bills[i]]++;
    }

    return flag;
}

// Input: bills = [5,5,5,10,20]
// Output: true
// Explanation: 
// From the first 3 customers, we collect three $5 bills in order.
// From the fourth customer, we collect a $10 bill and give back a $5.
// From the fifth customer, we give a $10 bill and a $5 bill.
// Since all customers got correct change, we output true.
