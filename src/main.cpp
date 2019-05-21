/**
@file
*/

#include <iostream>
#include <string>
#include <vector>


#include "parser.h"
#include "lexer.h"
#include "builtin.h"
#include "interpreter.h"

using namespace std;

/**
* This is the main loop of the BombShell program. Take input from user, parse and interpret it until exit is called
 */
int main(int argc, char const *argv[])
{
	string input, temp;
	Builtin builtin;
	builtin.printBomb();
	while(1){
		builtin.printCurDir();
		//Receive input
		input = builtin.receiveInput();
		
		Lexer lexer(input);

		Parser parser(lexer);
		vector<vector<string> > command_table;
		command_table = parser.parse();

		// Check for any builtin command
		if(builtin.checkBuiltin(command_table))
			continue;
		// Otherwise interpret() command_table
		Interpreter interpreter(command_table);
		interpreter.interpret();
		fdopen(0, "r");
		freopen ("/dev/tty", "a", stdout);
		builtin.addHistory(input);
	}

	return 0;
}