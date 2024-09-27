// Leetcode - 729

vector<pair<int, int>> ranges;

bool book(int start, int end) {
    for (auto it : ranges) {
        int s = it.first;
        int e = it.second;

        if (start < e && end > s) {
            return false;
        }
    }

    ranges.push_back(make_pair(start, end));

    return true;
}

// Input
// ["MyCalendar", "book", "book", "book"]
// [[], [10, 20], [15, 25], [20, 30]]
  
// Output
// [null, true, false, true]

// Explanation
// MyCalendar myCalendar = new MyCalendar();
// myCalendar.book(10, 20); // return True
// myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
// myCalendar.book(20, 30); // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.
