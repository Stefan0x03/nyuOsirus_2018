#include <iostream>
#include <string>
using namespace std;

string xorshift(string, string);

//Declare input string and contents(Must escape chars)
string input = "";
int inputstr[] = {203,227, 223, 166, 025, 2, 138, 104, 228, 120
								, 118, 110, 91, 200, 061, 113 ,8, 125, 153, 189
								, 3, 180, 054}; /*23*/

int main(){
  //Read escape chars into input
  for(int i = 0; i< 23; i++)
    input += (char)inputstr[i];

  string xorstring = "";
  string output = "";

  for(int i = 0; i<256; i++){

    //Key assembly
    xorstring = "";
    xorstring += i;

    //Add new bit to key
    //xorstring += ((char)i);
    output = xorshift(input,xorstring);

    //Check for flag
    /*if (output.find("flag{") != -1){*/
      cout << "output: " << output << endl;
      cout << "key: " << xorstring << endl;
      cout << "input: " << input << endl;
    //}
  }

  return 0;
}

string xorshift(string keyin, string xorstring){
  string output = "";
  //Shift char in input by bit in xorstring, allow wrap around
    for(int pos = 0; pos < keyin.length(); pos++)
      output += (char)(keyin[pos] ^ xorstring[pos % xorstring.length()]);
  return output;
}
