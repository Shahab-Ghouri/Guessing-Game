#include <iostream> 
#include <string> 
#include <windows.h>

using namespace std; 
int main(){
	string phrase = " HELLO";
	string phrase1 = "WELCOME TO";
	string phrase2 = "AKINATOR 2.0"; 
	
	
	string command  = "espeak \"" + phrase + "\"";
	string command1 = "espeak \"" + phrase1+"\"";
	string command2 = "espeak \"" + phrase2+"\"";

	
	
	const char* charCommand = command.c_str();
	system(charCommand);
	
	charCommand = command1.c_str();
	system(charCommand);
	
	charCommand = command2.c_str();
	system(charCommand);
	

	
	
}
