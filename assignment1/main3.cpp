#include <string>
#include <cassert>
#include <cctype>
#include <ostream>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string reverse_words(const string &str)
{
    string final_str = str;
    int tmp_index = 0;

    for(size_t i = 0; i < final_str.size(); i++) {      
        if (!isalnum(final_str[i])) {
            // If letter is NOT alphanumeric, reverse substring from tmp_index to current location i 
            reverse(final_str.begin() + tmp_index, final_str.begin() + i);
            // Update tmp index to location + 1
            tmp_index = i + 1;
        }
    }
    
    // Handle the last word
    reverse(final_str.begin() + tmp_index, final_str.end());
    
    cout << "Final str: " << final_str << endl;
    return final_str;
}

int main()
{
    string test_str = "String; 2be reversed...";
    reverse_words(test_str);
    // assert(reverse_words(test_str) == "gnirtS; eb2 desrever...");

    // assert(reverse_words(" Hello World Test ") == " olleH dlroW tseT ");
    // assert(reverse_words("Hello, world!! 1234") == "olleH, dlrow!! 4321");
    // assert(reverse_words("") == "");
    // assert(reverse_words("@$%^&*()!") == "@$%^&*()!");
    // assert(reverse_words("1234") == "4321");
    // assert(reverse_words("test1234test") == "tset4321tset");
    // assert(reverse_words("Test Case") == "tseT esaC");

    return 0;
}