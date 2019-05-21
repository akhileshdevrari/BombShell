#include "builtin.h"

Builtin::Builtin(){};

Builtin::~Builtin(){};

string Builtin::receiveInput(){
	string input;
	while(input==""){
		getline(cin, input, '\n');
	}
	return input;
}

void Builtin::_exit(){
	cout<<"GoodBye!\n";
	exit(0);
}

void Builtin::addHistory(string cmd){
	history.push_back(cmd);
}

void Builtin::showHistory(){
	for(int i=0; i<history.size(); i++)
		cout<<(i+1)<<". "<<history[i]<<endl;
}

void Builtin::cd(string dir){
	chdir((char*)dir.c_str());
}

void Builtin::printCurDir(){
	char cwd[PATH_MAX];
	getcwd(cwd, sizeof(cwd));
	printf("%s\n", KGRN);
	printf("%s : ", cwd);
	printf("%s", KYEL);
}

int Builtin::checkBuiltin(vector<vector<string> > &command_table){
	if(command_table.size()==4){
		if(command_table[3][0] == "exit"){
			_exit();
			return 1;
		}
		else if(command_table[3][0] == "history"){
			showHistory();
			return 1;
		}
		else if(command_table[3][0] == "cd"){
			cd(command_table[3][1]);
			return 1;
		}
	}
	return 0;
}

void Builtin::printBomb(){
	string bomb;

	bomb+="	             . . .\n";
	bomb+="              \\|/\n";
	bomb+="            `--+--\'\n";
	bomb+="              /|\\\n";
	bomb+="             \' | \'\n";
	bomb+="               |\n";
	bomb+="               |\n";
	bomb+="           ,--\'#`--.\n";
	bomb+="           |#######|\n";
	bomb+="        _.-\'#######`-._\n";
	bomb+="     ,-\'###############`-.\n";
	bomb+="   ,\'#####################`,\n";
	bomb+="  /#########################\\\n";
	bomb+=" |###########################|\n";
	bomb+="|#############################|\n";
	bomb+="|#############################|\n";
	bomb+="|#############################|\n";
	bomb+="|#############################|\n";
	bomb+=" |###########################|\n";
	bomb+="  \\#########################/\n";
	bomb+="   `.#####################,\'\n";
	bomb+="     `._###############_,\'\n";
	bomb+="        `--..#####..--\'\n";
	
	printf("%s\n", KRED);
	cout<<bomb<<endl;
}