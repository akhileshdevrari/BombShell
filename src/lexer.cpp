#include "lexer.h"


//Token class
Token::Token(){
	type = "";
	value = "";
}

Token::Token(std::string _type, std::string _value){
	type = _type;
	value = _value;
}

string Token::str(){
	return ("Token("+type+","+value+")");
}

//returns value of this token
string Token::_value(){
	return value;
}
//returns type of this token
string Token::_type(){
	return type;
}





// Lexer

Lexer::Lexer(){
	text = "";
	pos = 0;
	current_char = EOF;
}
Lexer::Lexer(std::string _text){
	text = _text;
	pos = 0;
	current_char = text[pos];
}

void Lexer::skip_whitespaces(){
	//as the name suggests, skip all whitespaces till any new character is encountered
	while(text[pos] == ' ' or text[pos] == '\t' or text[pos] == '\n')
		advance_pos();
}

void Lexer::advance_pos(){
	pos++;
	//if pos past the end of text, i.e tokenization is completed
	//return EOF token
	if(pos >= text.length())
		current_char = EOF;
	else current_char = text[pos];
}


string Lexer::get_string(){
	// std::cout<<"get_string()\n";
	std::string str;
	advance_pos();
	while(current_char != '\"')
	{
		// std::cout<<"current_char = "<<current_char<<"\n";
		str.push_back(current_char);
		advance_pos();
	}
	advance_pos();
	return str;
}

string Lexer::get_word(){
	string str;
	while(current_char != ' ' and current_char != EOF)
	{
		str.push_back(current_char);
		advance_pos();
		// cout<<"current_char = "<<current_char<<endl;
	}
	// cout<<"current_char = "<<current_char<<endl;
	return str;
}

//Only peeks into input buffer without actually consuming the next character
char Lexer::peek(){
	//if peek_pos past the end of text, return EOF
	if(pos+1 >= text.length())
		return EOF;
	else return text[pos+1];
}


Token Lexer::get_next_token(){
	// cout<<"text = "<<text<<endl;
	// cout<<"current_char uu = "<<current_char<<endl;
	//ignore whitespaces
	skip_whitespaces();

	//if token is + operator
	if(current_char == '|'){
		advance_pos();
		return Token(PIPE, "|");
	}

	if(current_char == '>' and peek() == '>'){
		advance_pos();
		advance_pos();
		return Token(OUTPUT_APPEND, ">>");
	}

	if(current_char == '<'){
		advance_pos();
		return Token(INPUT_REDIRECTION, "<");
	}

	if(current_char == '>'){
		advance_pos();
		return Token(OUTPUT_REDIRECTION, ">");
	}

	if(current_char == '\"'){
		return Token(STRING, get_string());
	}

	if(current_char == EOF){
		return Token(END, END);
	}
	return Token(WORD, get_word());
}
