#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>
// For using systems calls like execvp(), fork()
#include <unistd.h>
// For using exit()
#include <stdlib.h>
// For using wait
#include <sys/wait.h> 

#include "lexer.h"
#include "parser.h"

using namespace std;

//!  Parser
/*!
  An object of this class will be created in main() and will be used to intepret command_table
*/

class Interpreter{
private:
	//! Command table containing commands entered by user
	vector<vector<string> > command_table;
	//! Function helpful for implementing piping
	//! Source: https://stackoverflow.com/questions/8082932/connecting-n-commands-with-pipes-in-a-shell
	void spawn_proc(int, int, vector<string> &);
public:
	Interpreter(){};

	//! Constructor
	/*!
	* \param command_table
	*/
	Interpreter(vector<vector<string> > &);
	~Interpreter(){};

	//! Interpret the command_table
	/*!
	* \return void
	*/
	void interpret();
};

#endif