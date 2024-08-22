bool Comparator(Job val1, Job val2) {
    return val1.profit > val2.profit;
}

class Solution  {
public:
vector<int> JobScheduling(Job arr[], int n) { 
    vector<Job> jobs(arr, arr + n);
    sort(jobs.begin(), jobs.end(), Comparator);
    int maxProfit = 0, cnt = 0, maxDead = 0;

    for(int i = 0; i < jobs.size(); i++) {
        maxDead = max(maxDead, jobs[i].dead);
    }
    
    vector<int> maxDeadline(maxDead + 1, -1);
    
    for(int i = 0; i < jobs.size(); i++) {
        for(int j = jobs[i].dead; j > 0 ; j--) {
            if(maxDeadline[j] == -1) {
                cnt = cnt + 1;
                maxDeadline[j] = jobs[i].id;
                maxProfit += jobs[i].profit;
                break;
            }
        }
    }
    
    return {cnt, maxProfit};
} 

// Input: Jobs = [[1,4,20],[2,1,1],[3,1,40],[4,1,30]]
// Output: 2 60
// Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
