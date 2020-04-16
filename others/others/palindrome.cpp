#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isnt_char(char c) {
    if (c >= 'A' && c <= 'Z')
        return false;
    else
        return true;
}

bool is_palindrome(string input) {
    int len = input.length();
    if (len <= 1)
        return true;
    if (input.at(0) == input.at(len - 1)) {
        return is_palindrome(input.substr(1, len-2));
    }else{
        return false;
    }

}

int main()
{
    string input;
    getline(cin, input);
    transform(input.begin(), input.end(), input.begin(), ::toupper);
    input.erase(std::remove_if(input.begin(), input.end(), isnt_char), input.end());
    cout << (is_palindrome(input)?"YES":"NO")    << endl;
    return 0;
}