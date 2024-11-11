#include <iostream>
#include <string>
using namespace std;

string compress(const string& word) {
    string comp;
    size_t i = 0;
    
    while (i < word.length()) {
        char c = word[i];
    
        int count = 0;
        while (i < word.length() && word[i] == c && count < 9) {
            count++;
            i++;
        }

        comp += to_string(count) + c;
    }
    
    return comp;
}

int main() {
    string word = "ccccccccccccdddddeeeffgg";
    string compressed_word = compress(word);
    
    cout << "Original word: " << word << endl;
    cout << "Compressed word: " << compressed_word << endl;
    return 0;
}
