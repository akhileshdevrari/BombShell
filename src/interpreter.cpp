#include "interpreter.h"

Interpreter::Interpreter(vector<vector<string> > &cmd_t){
	command_table = cmd_t;
}

// Source for this piece of code = https://stackoverflow.com/questions/8082932/connecting-n-commands-with-pipes-in-a-shell
void Interpreter::spawn_proc(int in, int out, vector<string> &command){
	pid_t pid;

	// Converting command to required format
	int n = command.size();
	char *cmd[n+1];
	cmd[n] = NULL;
	for(int j=0; j<n; j++)
		cmd[j] = (char*)command[j].c_str();
	
	if((pid = fork ()) == 0){
		if (in != 0){
			dup2(in, 0);
			close(in);
		}
		if (out != 1){
		  dup2(out, 1);
		  close(out);
		}
		execvp(cmd[0], cmd);
	}
}

void Interpreter::interpret(){
	//There are no commands to execute
	if(command_table.size()<=3)
		return;

	int fd[2];
    pid_t pid, wpid;
    int i=0;
    /* The first process should get its input from the original file descriptor 0.  */
    int in = 0;
    // Setting up input stream for first command if user has specified so
	if(command_table[0][0]!=""){
		if(freopen((const char*)command_table[0][0].c_str(), "r", stdin) == NULL){
			cout<<"freopen() failed while setting input stream";
			exit(1);
		}
	}
    /* Note the loop bound, we spawn here all, but the last stage of the pipeline.  */
	for(i=3; i<command_table.size()-1; i++){
		pipe(fd);
		/* f [1] is the write end of the pipe, we carry `in` from the prev iteration.  */
		spawn_proc(in, fd[1], command_table[i]);
		/* No need for the write end of the pipe, the child will write here.  */
		close(fd[1]);
		/* Keep the read end of the pipe, the next child will read from there.  */
		in = fd [0];
	}

	/* Execute the last stage with the current process. */
	if (in != 0)
    	dup2 (in, 0);
	int n = command_table[command_table.size()-1].size();
	char *cmd[n+1];
	cmd[n] = NULL;
	for(int j=0; j<n; j++)
		cmd[j] = (char*)command_table[command_table.size()-1][j].c_str();
	
	// Setting up output stream for last command
	if(command_table[1][0]!=""){
		if(freopen((const char*)command_table[1][0].c_str(), "w", stdout) == NULL){
			cout<<"freopen() failed while setting output stream";
			exit(1);
		}
	}
	if(command_table[2][0]!=""){
		if(freopen((const char*)command_table[2][0].c_str(), "a", stdout) == NULL){
			cout<<"freopen() failed while setting append stream";
			exit(1);
		}
	}

	int status = 0;
	pid_t cpid;
	// Execute last command
	if((pid = fork ()) == 0){
		execvp(cmd[0], cmd);
		cout<<"Error while executing : "<<cmd[0]<<endl;
		exit(1);	
	}
	else {
		cpid = wait(NULL);
	} 
}