#include <iostream>
#include <string>
#include <vector>
using namespace std;

//!  Parser
/*!
  An object of this class will be created in main() and will be used to parse the user input
*/
class Parser
{
private:
	//! text entered by user on terminal
	string inputText;

	//! vector of string tokens
	vector<string> tokens;


	//! parse the inputText and setup tokens[]
	void parse();

public:
	//! Constructor.
    /*!
    	Takes a string as argument, sets it as this.inputText and then call this.parse()
    	\param text input string
    	\return void
    */
	Parser(string text);
	~Parser();


	//! Given next token in tokens[]
	/*!
	* \return a string for next token from tokens[]
	* \return suitable EOF symbol if no more tokens are left
	*/
	string getNextToken();
};