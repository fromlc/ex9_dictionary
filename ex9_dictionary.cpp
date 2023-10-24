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
}

//------------------------------------------------------------------------------
// local functions
//------------------------------------------------------------------------------
//#TODO put your lookup_word() function prototype here

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    //#TODO use a loop to prompt the user for words until they want to quit

    //#TODO call function lookup_word() with either
    //   a string variable or a literal string

    string definition;
    //int index = lookup_word("dog", definition);

    string word = "cat";
    //int index = lookup_word(word, definition);

    // #TODO display the definition, or a not found message
}

//------------------------------------------------------------------------------
// -look up passed word in defs array
// -return index of word if found otherwise return -1
//------------------------------------------------------------------------------
//#TODO put your lookup_word() function definition here