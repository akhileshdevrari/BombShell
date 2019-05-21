#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include <vector>
// For using EOF
#include <fstream>

using namespace std;


//Token types
#define WORD "WORD"
#define STRING "STRING"
#define INPUT_REDIRECTION "INPUT_REDIRECTION"
#define OUTPUT_REDIRECTION "OUTPUT_REDIRECTION"
#define OUTPUT_APPEND "OUTPUT_APPEND"
#define EMPTY "EMPTY"
#define PIPE "PIPE"
#define END "END"

//!  Builtin
/*!
  An object of this class will be created in main() and will be used for tokening user input
*/ 
class Token
{
private:
	//token type: eg: STRING, COMMAND, etc
	std::string type;
	//token value: eg: 0, 1, '+', 'EOF'
	std::string value;

public:
	Token();
	//! Constructor
	/*!
	* \param _value input string
	* \return void
	*/
	Token(std::string _type, std::string _value);

	~Token(){};

	//String representation of class instance
	// eg:  Token(int,3)    Token(plus,'+')
	std::string str();

	//returns value of this token
	std::string _value();
	//returns type of this token
	std::string _type();
};





class Lexer
{
private:
	//! input text entered by user
	std::string text;
	//! current char at text[pos]
	char current_char;
	//! current index of text to be tokenized
	int pos;

public:
	Lexer();
	//! Constructor
	/*!
	* \param _value input string
	* \return void
	*/
	Lexer(std::string _text);
	~Lexer(){};


	
	//! Ignores whitespaces and put pos pointer to a non-whitespace character
	/*!
	* \return void
	*/
	void skip_whitespaces();


	//! Advances position of pos pointer in text, and check if EOF reached
	/*!
	* \return void
	*/
	void advance_pos();


	//! returns a word starting at pos, and shift pos to next pointer
	/*!
	* \return void
	*/
	std::string get_word();


	//! returns a string which is present under double quotes
	/*!
	* \return void
	*/
	std::string get_string();


	//! Most important function in Lexical analyzer. This method breaks the text into tokens, and returns a token starting at pos
	/*!
	* \return void
	*/
	Token get_next_token();

	//! returns next character in input text 
	/*!
	* \return character after current_pos
	*/
	char peek();
};



#endif