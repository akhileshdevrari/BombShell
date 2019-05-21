#include "parser.h"
using namespace std;

Parser::Parser(Lexer _lexer){
	lexer = _lexer;
}

void Parser::error(Token token){
	cout<<"Error while processing token near "<<token.str()<<endl;
}

vector<vector<string> > Parser::parse(){
	command_table.clear();
	// command_table[0] = Input redirection
	command_table.push_back(vector<string> (1, ""));
	// command_table[1] = output redirection(overwrite)
	command_table.push_back(vector<string> (1, ""));
	// command_table[2] = output redirection (append)
	command_table.push_back(vector<string> (1, ""));

	current_token = lexer.get_next_token();
	while(current_token._type() != END){
		// Input redirection
		if(current_token._type() == INPUT_REDIRECTION){
			current_token = lexer.get_next_token();
			if(current_token._type() != WORD)
				error(current_token);
			else command_table[0][0] = current_token._value();
			current_token = lexer.get_next_token();
			continue;
		}

		if(current_token._type() == OUTPUT_REDIRECTION){
			current_token = lexer.get_next_token();
			if(current_token._type() != WORD)
				error(current_token);
			else{
				command_table[1][0] = current_token._value();
				command_table[2][0] = "";
			}
			current_token = lexer.get_next_token();
			continue;
		}

		if(current_token._type() == OUTPUT_APPEND){
			current_token = lexer.get_next_token();
			if(current_token._type() != WORD)
				error(current_token);
			else{
				command_table[2][0] = current_token._value();
				command_table[1][0] = "";
			}
			current_token = lexer.get_next_token();
			continue;
		}

		if(current_token._type() == PIPE){
			current_token = lexer.get_next_token();
			if(current_token._type() != WORD)
				error(current_token);
			continue;
		}

		if(current_token._type() == WORD){
			vector<string> command;
			while(current_token._type() == WORD){
				command.push_back(current_token._value());
				current_token = lexer.get_next_token();
			}
			command_table.push_back(command);
			continue;
		}
		
	}
	return command_table;
}