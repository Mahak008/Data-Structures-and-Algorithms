string rev(string& arr, int l, int r) {
    if (l >= r) {
        return arr;
    }

    swap(arr[l], arr[r]);
    return rev(arr, l + 1, r - 1);
}

bool isPalindrome(string s) {
    string a;

    for (char c : s) {
        if (isalnum(c)) {
            a += tolower(c);
        }
    }

    int l = 0, r = a.length() - 1;
    string d = a;

    string b = rev(d, l, r);
    if (a == b) {
        return true;
    }
    return false;
}
