//------------------------------------------------------------------------------
// ex9_dictionary.cpp
// 
// Practice with reference parameters
//------------------------------------------------------------------------------
#include <iostream>

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

    int num_words = sizeof(words) / sizeof(string);
}

//------------------------------------------------------------------------------
// local functions
//------------------------------------------------------------------------------
inline void display_dictionary();
int lookup_word(const string& search_str, string& definition);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    display_dictionary();

    // prompt the user for words until they type "quit"
    while (true) {

        // get user's word to search for and store it in search_str
        cout << "\nWord to look up? ";
        string search_str;
        cin >> search_str;

        // terminate loop when the user types "quit"

        // first, let's force everything the user typed to lower case
        for (char& ch : search_str) {
            ch = tolower(ch);
        }

        // now let's see if they typed "quit" in upper, lower, or mixed case
        if (search_str.compare("quit") == 0)
            break;

        // we need a string variable for lookup_word() to put the definition in
        string definition;

        // search the words array for the user's word
        int index = lookup_word(search_str, definition);

        // is the user's word in the array?
        if (index == -1)
            cout << "Sorry, I don't know that word\n";
        else {
            // two different ways to display the definition
            cout << '\n' << search_str << ": " << definition << '\n';
            cout << dict::words[index] << ": " << dict::defs[index] << '\n';
        }
    }

    cout << "\nGoodbye!\n";

    return 0;
}

//------------------------------------------------------------------------------
// displays all words in dict::words[] array
//------------------------------------------------------------------------------
inline void display_dictionary() {
    cout << "\nDictionary words: ";
    for (int i = 0; i < dict::num_words; i++) {
        cout << dict::words[i] << ' ';
    }
    cout << '\n';
}

//------------------------------------------------------------------------------
// -look up passed search_str in dict::words[] array
// -returns:
//       index of the matching element in dict::words[], or
//       -1 if no match found in dict::words[]
// -if a match was found in dict::words[], store the corresponding definition
//      in reference parameter definition_str;
//------------------------------------------------------------------------------
int lookup_word(const string& search_str, string& definition_str) {

    // for better performance, we determined the number of words
    // in dict::words[] above, and we put it in global variable
    // dict::num_words

    for (int index = 0; index < dict::num_words; index++) {

        if (search_str.compare(dict::words[index]) == 0) {

            // fill reference parameter with corresponding definition
            definition_str = dict::defs[index];

            // return index of the matching element in dict::words
            return index;
        }
    }

    // we made it all the way through the for loop, so
    // the search_str was not found in dict::words

    return -1;
}
