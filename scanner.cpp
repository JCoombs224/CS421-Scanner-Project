#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* Look for all **'s and complete them */

//=====================================================
// File scanner.cpp written by: Group Number: **
//=====================================================

// --------- Two DFAs ---------------------------------

bool isConsonantStart(char c)
{
  return (c == 'b' || c == 'g' || c == 'h' || c == 'k' || c == 'm' || c == 'n' || c == 'p' || c == 'r');
}

bool isConsonantEnd(char c)
{
  return (c == 'd' || c == 'w' || c == 'z' || c == 'y' || c == 'j');
}

bool isVowel(char c)
{
  return(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// WORD DFA
// Done by: Jamison Coombs
// RE:   Lilly <last-name>, Tim <last-name>
bool word(string s)
{
  int state = 0;
  int charpos = 0;

  while(s[charpos] != '\0') 
  {
    char c = s[charpos];
    if (state == 0)
    {
      if (isConsonantStart(c)) // ~~~~~~~~~~~~ State 0 ~~~~~~~~~~~~
      state = 6;
    else if(isConsonantEnd(c))
      state = 5;
    else if(c == 's')
      state = 4;
    else if(isVowel(c))
      state = 1;
    else
      state = -1;
    }
    else if(state == 1) // ~~~~~~~~~~~~ State 1 ~~~~~~~~~~~~
    {
      if(state == 1 && isVowel(c))
        state = 1;
      else if(isConsonantEnd(c))
        state = 5;
      else if(isConsonantStart(c))
        state = 6;
      else if(c == 'n')
        state = 3;
      else if(c == 's')
        state = 4;
      else if(c == 't')
        state = 2;
      else
        state = -1;
    }
    else if(state == 2) // ~~~~~~~~~~~~ State 2 ~~~~~~~~~~~~
    {
      if(isVowel(c))
        state = 1;
      else if(c == 's')
        state = 5;
      else
        state = -1;
    }
    else if(state == 3) // ~~~~~~~~~~~~ State 3 ~~~~~~~~~~~~
    {
      if(isVowel(c))
        state = 1;
      else if(c == 't')
        state = 2;
      else if(c == 's')
        state = 4;
      else if(c == 'c')
        state = 7;
      else if(isConsonantStart(c))
        state = 6;
      else if(isConsonantEnd(c))
        state = 5;
      else
        state = -1;
    }
    else if(state == 4) // ~~~~~~~~~~~~ State 4 ~~~~~~~~~~~~
    {
      if (isVowel(c))
        state = 1;
      else if(c == 'h')
        state = 5;
      else
        state = -1;
    }
    else if(state == 5) // ~~~~~~~~~~~~ State 5 ~~~~~~~~~~~~
    {
      if(isVowel(c))
        state = 1;
      else
        state = -1;
    }
    else if(state == 6) // ~~~~~~~~~~~~ State 6 ~~~~~~~~~~~~
    {
      if(isVowel(c))
        state = 1;
      else if(c == 'y')
        state = 5;
    }
    else if(state == 7) // ~~~~~~~~~~~~ State 7 ~~~~~~~~~~~~
    {
      if(c == 'h')
        state = 5;
      else
        state = -1;
    }
    else // ~~~~~~~~~~~~ Error State ~~~~~~~~~~~~
    {
      return false;
    }

    charpos++;
  } // End of while

  // where did I end up????
  if(state == 0 || state == 1 || state == 3)
  {
    return true;
  }
  else
    return false;
}

// PERIOD DFA
// Done by: Jamison Coombs
bool period(string s)
{
  int state = 0;
  int charpos = 0;
  while(s[charpos] != '\0')
  {
    char c = s[charpos];

    if(state == 0 && c == '.')
      state = 1;
    else
      return false;
    
    charpos++;
  } // End of loop

  if(state == 1)
    return true;
  else
    return false;
}

// ------ Three  Tables -------------------------------------

// TABLES Done by: **

// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype
{
  ERROR,
};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = {};

// ** Need the reservedwords table to be set up here.
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.

// ------------ Scanner and Driver -----------------------

ifstream fin; // global stream for reading from the input file

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by:
int scanner(tokentype &tt, string &w)
{

  // ** Grab the next word from the file via fin
  // 1. If it is eofm, return right now.

  /*  **
  2. Call the token functions (word and period)
     one after another (if-then-else).
     Generate a lexical error message if both DFAs failed.
     Let the tokentype be ERROR in that case.

  3. If it was a word,
     check against the reservedwords list.
     If not reserved, tokentype is WORD1 or WORD2
     decided based on the last character.

  4. Return the token type & string  (pass by reference)
  */

} // the end of scanner

// The temporary test driver to just call the scanner repeatedly
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!!
// Done by:  Louis
int main()
{
  tokentype thetype;
  string theword;
  string filename;

  cout << "Enter the input file name: ";
  cin >> filename;

  fin.open(filename.c_str());

  // the loop continues until eofm is returned.
  while (true)
  {
    scanner(thetype, theword); // call the scanner which sets
                               // the arguments
    if (theword == "eofm")
      break; // stop now

    cout << "Type is:" << tokenName[thetype] << endl;
    cout << "Word is:" << theword << endl;
  }

  cout << "End of file is encountered." << endl;
  fin.close();

} // end
