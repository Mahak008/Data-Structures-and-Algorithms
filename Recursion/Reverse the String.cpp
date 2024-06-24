void rev(string &str, int left, int right) {
    if (left > right) {
        return;
    }
    swap(str[left], str[right]);
    rev(str, left + 1, right - 1);
}

string reverseString(string str)
{
	if (str.empty()) {
        return str; // Handle empty string case
    }
    rev(str, 0, str.length() - 1);
    return str;
}
