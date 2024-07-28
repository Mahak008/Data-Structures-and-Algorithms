void buildTree(int segTree[], int arr[], int low, int high, int pos) {
    if (low == high) {
        segTree[pos] = arr[low];
        return;
    }
    
    int mid = (low + high) / 2;
    
    buildTree(segTree, arr, low, mid, 2 * pos + 1);
    buildTree(segTree, arr, mid + 1, high, 2 * pos + 2);
    
    segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

/* The functions which builds the segment tree */
int *constructST(int arr[],int n) {
    int x = (int)(ceil(log2(n)));
    int size = 2 * (int)pow(2, x) - 1;

    int *segTree = new int[size];
    buildTree(segTree, arr, 0, n - 1, 0);

    return segTree;
}

int query(int segTree[], int start, int end, int low, int high, int pos) {
    if(low > end || high < start) {
        return INT_MAX;
    }    
    
    if(low >= start && high <= end) {
        return segTree[pos];
    }
    
    int mid = (low + high) / 2;
    
    return min(query(segTree, start, end, low, mid, 2 * pos + 1), query(segTree, start, end, mid + 1, high, 2 * pos + 2));
}

/* The functions returns the min element in the range from a and b */
int RMQ(int st[] , int n, int a, int b) {
    return query(st, a, b, 0, n - 1, 0);
}

// Input:
// n = 4
// arr = 1 2 3 4
// q = 2
// queries = 0 2 2 3
  
// Output
// 1 3
  
// Explanation
// 1. For query 1 ie 0 2 the element in this range are 1 2 3 and the min element is 1. 
// 2. For query 2 ie 2 3 the element in this range are 3 4 and the min element is 3.
