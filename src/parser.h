#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <vector>

#include "lexer.h"

using namespace std;

//!  Parser
/*!
  An object of this class will be created in main() and will be used to parse the user input
*/

class Parser{
private:
	Lexer lexer;
	Token current_token;
	vector<vector<string> > command_table;
public:
	Parser(){};
	//! Constructor
	/*!
	* \param lexer
	*/
	Parser(Lexer _lexer);
	~Parser(){};

	//! parses the tokens sent by lexer
	/*!
	* \return command table generated after parsing
	*/
	vector<vector<string> > parse();

	//! shows if an error occurs whiling parsing a token
	/*!
	* \param token parsing which causes error
	* \return void
	*/
	void error(Token token);
	
};

#endif