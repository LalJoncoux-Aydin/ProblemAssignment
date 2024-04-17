#include <string>
#include <cassert>
#include <cctype>
#include <ostream>
#include <iostream>
#include <algorithm>

using namespace std;

string reverse_words(const string &str)
{
    string final_str = "";
    string tmp_str = "";

    for (size_t i = 0; i < str.size(); i++) {
        if (isalnum(str[i])) {
            // If letter is alphanumeric, append to temporary string
            tmp_str += str[i]; 
        } else {
            if (!tmp_str.empty()) {
                // If temporary string is not empty, then reverse, add to the final string and clean the temporary string
                reverse(tmp_str.begin(), tmp_str.end());
                final_str += tmp_str;
                tmp_str.clear();
            }
            // Add non-word/special characters - do not need reverse
            final_str += str[i]; 
        }    
    }

    if (!tmp_str.empty()) {
        // Handle the last word
        reverse(tmp_str.begin(), tmp_str.end());
        final_str += tmp_str;
    }

    cout << "Final str: " << final_str << endl;
    return final_str;
}

int main()
{
    string test_str = "String; 2be reversed...";
    assert(reverse_words(test_str) == "gnirtS; eb2 desrever...");

    assert(reverse_words(" Hello World Test ") == " olleH dlroW tseT ");
    assert(reverse_words("Hello, world!! 1234") == "olleH, dlrow!! 4321");
    assert(reverse_words("") == "");
    assert(reverse_words("@$%^&*()!") == "@$%^&*()!");
    assert(reverse_words("1234") == "4321");
    assert(reverse_words("test1234test") == "tset4321tset");
    assert(reverse_words("Test Case") == "tseT esaC");

    return 0;
}