#include <iostream>
#include <string>
#include <vector>
using namespace std;

//!  Builtin
/*!
  An object of this class will be created in main() and will be used for keeping track of current working directory and executing builtin functions

  Use a private stack to implement cd() and history()
*/ 
class Builtin
{
public:
	Builtin();
	~Builtin();
	
	//! Returns current working directory
	/*!
	* \return string
	*/
	string currentDir();

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
	vector<string> showHistory();

	//! Add current command to history
	/*! 
	* \param command a string which was entered by user and should be stored in history if it is non-empty
	* \return void
	*/
	void addToHistory(string command);
};