vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* temp = head;
    int cnt = 0;
    vector<int> ans;

    while (temp != NULL && temp->next != NULL) {
        if (prev != NULL && temp->next != NULL) {
            if ((temp->val > prev->val && temp->val > temp->next->val) ||
                (temp->val < prev->val && temp->val < temp->next->val)) {
                ans.push_back(cnt);
            }
        }
        prev = temp;
        temp = temp->next;
        cnt += 1;
    }

    if (ans.size() < 2) {
        return {-1, -1};
    }

    int maxi = ans.back() - ans.front();

    int mini = INT_MAX;

    for (int i = 1; i < ans.size(); i++) {
        mini = min(mini, (ans[i] - ans[i - 1]));
    }

    return {mini, maxi};
}

// Input: head = [5,3,1,2,5,1,2]
// Output: [1,3]
// Explanation: There are three critical points:
// - [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
// - [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
// - [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
// The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
// The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
