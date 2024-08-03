#include <iostream>
#include <vector>

using namespace std;

// Function to tokenize a string based on given delimiters
vector<string> tokenize(string str, string delimiters) {
    vector<string> tokens;
    size_t start = 0;
    size_t end;

    while ((end = str.find_first_of(delimiters, start)) != string::npos) {
        if (end > start) {
            tokens.push_back(str.substr(start, end - start));
        }
        start = end + 1;
    }

    if (start < str.length()) {
        tokens.push_back(str.substr(start));
    }

    return tokens;
}

int main() {
    string text = "This,is a.test:string with;multiple delimiters";
    string delimiters = ",. :;";

    vector<string> tokens = tokenize(text, delimiters);

    cout << "Tokens:" << endl;
    for (string token : tokens) {
        cout << token << endl;
    }

    return 0;
}
