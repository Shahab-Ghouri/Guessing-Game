#include<iostream>
#include <fstream>
#include "LinkedList.h"
#include <string>
using namespace std;
class Alizeh{
	private:
		string ans;
	public:
		bool check_pers(){
			char response[10];
			ifstream fileptr;
			fileptr.open("FEMALE/Alizeh.txt");
			if(fileptr){
				getline(fileptr,ans);
				cout<<" Has Your Character played a role in  "<<ans<<" ? (YES/NO) : ";
				string phrase = "Has Your Character played a role in "+ans; 
				string command = "espeak \"" + phrase + "\"";
				const char* char_command = command.c_str();
				system(char_command);
				
				cin>>response;
				if(strcmp(response,"YES")== 0  || strcmp(response,"yes")==0 || strcmp(response,"Yes")==0 ){}
				else if(strcmp(response,"NO") ==0|| strcmp(response,"no") ==0|| strcmp(response,"No")==0 ){
					return false;
				}
				else{
					cout<<" PLEASE TYPE ONLY Yes/No";
					check_pers();
				}
				getline(fileptr,ans);
			
				cout<<" Is your  Character"<<ans<<"(YES/NO) : ";
				phrase = " Is your Character "+ans; 
				command = "espeak \"" + phrase + "\"";
				char_command = command.c_str();
				system(char_command);
				cin>>response;
				if(strcmp(response,"YES") ==0|| strcmp(response,"yes") ==0|| strcmp(response,"Yes")==0 ){
					return true;
				}
				else if(strcmp(response,"NO") ==0|| strcmp(response,"no") ==0|| strcmp(response,"No")==0 ){
					return false;
				}
				else{
					cout<<" PLEASE TYPE ONLY Yes/No";
					check_pers();
				}
		}
		// if file was not found
			else{
				 cout<<" NO FILE WAS FOUND";
			}
		}	// end of function
		
		
		bool check_in_file(LinkedList &obj,int dom,int size, bool flag){
			ifstream file;
			NODE *temp = obj.head;
			 size = obj.size();		// size of the linked list
			
			
			file.open("Alizeh.txt",ios::in);
			temp = obj.head;
			for(int i=0;i<size;i++){
					file>>dom;
					if(dom==temp->data){
						flag = true;
					}
					else{
						flag = false;
						break;		// if personality is not found break the loop
					}
				temp = temp->next;
			}
			if(flag)
			{
				return true;
			}
			else 
				return false;
		}
		
};

