#include <iostream>

using namespace std;

// Function to replace all occurrences of a substring
void searchAndReplace(string& str, string search, string replace) {
    for (size_t pos = 0; pos < str.length();) {
        pos = str.find(search, pos);
        if (pos != string::npos) {
            str.replace(pos, search.length(), replace);
            pos += replace.length();
        } else {
            break;
        }
    }
}

int main() {
    string text = "The quick brown fox jumps over the lazy dog.";
    cout << "Original text: " << text << endl;

    string search = "fox";
    string replace = "cat";

    searchAndReplace(text, search, replace);

    cout << "Modified text: " << text << endl;

    return 0;
}
