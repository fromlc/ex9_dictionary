//------------------------------------------------------------------------------
// ex9_dictionary.cpp
// 
// word lookup
// 
// Modify function lookup_word() to return definition as ref param
// Add a loop to prompt user for word to lookup
//------------------------------------------------------------------------------
#include <iostream>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
namespace dict {
    string words[] = {
        "cat",
        "dog",
        "duck",
    };

    string defs[] = {
        "meows and sleeps a lot",
        "barks and chases cats",
        "quacks and has webbed feet",
    };
    vector<string> vwords = {
        "cat",
        "dog",
        "duck",
    };
}

//------------------------------------------------------------------------------
// local functions
//------------------------------------------------------------------------------
int lookup_word(string&);
// need const reference to use string literal arguments
//int lookup_word(const string&);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    // word to look up
    string word = "cat";
    int index = lookup_word(word);

    // without const argument, lookup doesn't work with a string literal
    //int defs_index = lookup_word("cat");

    // output
    cout << dict::words[index] << ": ";

    if (index >= 0)
        cout << dict::defs[index];
    else
        cout << "not in dictionary";

    cout << '\n';
}

//------------------------------------------------------------------------------
// -look up passed word in defs array
// -return index of word if found otherwise return -1
//------------------------------------------------------------------------------
int lookup_word(string& word) {

    // search array with string compare
    int index = 0;
    for (string s : dict::words) {

        
        // Don't use direct string comparison
        //if (word == s)

        // compare() is best practice, returns 0 if strings have the same text
        if (!word.compare(s))
            return index;

        index++;
    }

    return -1;
}
