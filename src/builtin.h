#ifndef BUILTIN_H
#define BUILTIN_H

#include <iostream>
#include <string>
#include <vector>

// For using exit()
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <linux/limits.h>

// Color Codes
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"


using namespace std;

//!  Builtin
/*!
  An object of this class will be created in main() and will be used for keeping track of current working directory and executing builtin functions
*/ 
class Builtin
{
private:
	//! vector containing history of commands entered by user in this session
	vector<string> history;
public:
	Builtin();
	~Builtin();
	
	//! Print current working directory
	/*!
	* \return void
	*/
	void printCurDir();

	//! Enter a given directory
	/*!
	* \param dir name of directory
	* \return void
	*/
	void cd(string dir);

	//! Show history of commands entered by user since program started
	/*!
	* \return A vector of strings containing history in LIFO order
	*/
	void showHistory();

	//! Add current command to history
	/*! 
	* \param cmd a string which was entered by user and should be stored in history if it is non-empty
	* \return void
	*/
	void addHistory(string cmd);

	//! receive input from user
	/*! 
	* \return string entered by user
	*/
	string receiveInput();

	//! exit program
	/*! 
	* \return void
	*/
	void _exit();

	//! check if command entered is a builtin function
	/*! 
	* \return 1 command is builtin
	* \return 2 command is not builtin
	*/
	int checkBuiltin(vector<vector<string> > &command_table);

	//! print a giant bomb on screen
	/*! 
	* \return void
	*/
	void printBomb();
};



#endif