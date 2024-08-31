class Comp {
public:
    bool operator()(const Item& a, const Item& b) const {
        double ratio1 = (double) (a.value / a.weight);
        double ratio2 = (double) (b.value / b.weight);
        return ratio1 > ratio2; // Greater ratio comes first
    }
};

class Solution {
public:
    double fractionalKnapsack(int w, Item arr[], int n) {
        if (n == 0 || w == 0) return 0.0;

        sort(arr, arr + n, Comp());
        double totVal = 0.0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i].weight <= w) {
                totVal += arr[i].value;
                w -= arr[i].weight;
            } else {
                totVal += (arr[i].value * (double)w) / arr[i].weight;
                break;
            }
        }
        
        return totVal;
    }
};

// Input: n = 3, w = 50, value[] = [60,100,120], weight[] = [10,20,30]
// Output: 240.000000
