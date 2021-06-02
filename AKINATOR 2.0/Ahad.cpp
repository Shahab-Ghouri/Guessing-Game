#include<string>
#include "LinkedList.h"
using namespace std;
class Ahad{
	private:
		string ans;
	public:
		bool check_pers(){
			char response[10];
			ifstream fileptr;
			fileptr.open("MALE/Ahad.txt");
			if(fileptr){
				getline(fileptr,ans);
				cout<<" IS Your Character Graduated from "<<ans<<" ? (YES/NO) : ";
				string phrase = "IS Your Character Graduated from "+ans; 
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
				cout<<" Does Your Character Has PLayed a role of Army Officer in "<<ans<<" ? (YES/NO) : ";
				phrase = "Does Your Character Has PLayed a role of Army Officer in "+ans; 
				command = "espeak \"" + phrase + "\"";
				char_command = command.c_str();
				system(char_command);
				
				cin>>response;
				if(strcmp(response,"YES") ==0|| strcmp(response,"yes") ==0|| strcmp(response,"Yes")==0 ){}
				getline(fileptr,ans);
				cout<<" Does Your Character Has Married To "<<ans<<" ? (YES/NO) : ";
				phrase = "Does Your Character Has Married To "+ans; 
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
		
		bool check_in_file(LinkedList &obj,int dom,int size,bool flag){
			NODE *temp = obj.head;
			 size = obj.size();		// size of the linked list
			ifstream file;
			
			
		
			file.open("ahad.txt",ios::in);
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
