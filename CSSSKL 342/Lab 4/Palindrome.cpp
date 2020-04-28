#include <iostream>
using namespace std;bool isPalindrome(const string& str, int start, int end) {    if (start >= end)        return true;    if (str[start] != str[end])        return false;    return isPalindrome(str, ++start, --end);}

int main() {
    string str = "abccba";
    isPalindrome(str, 0, str.length() - 1) ? "Palindrome" : "Not Palindrome";

    return 0;
}



