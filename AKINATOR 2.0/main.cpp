// 		© Copyright 2021 , OBAID ULLAH SHAHAB GHOURI 
// 		19K-1322
// 		SECTION-A

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <queue>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <iomanip>
#include <windows.h>
// including characters  
#include "fawwad.cpp"
#include "Ahad.cpp"
#include "ImranAbbas.cpp"
#include "Hamza.cpp"
#include "Daniyal.cpp"
#include "Abid.cpp" 
// ----------------------
#include "Hira.cpp"
#include "Alizeh.cpp"
#include "Hania.cpp"
#include "Iqra.cpp"
#include "Sunita.cpp"
#include "Tahira.cpp"
// ---------------------

// including Linked List which stores the answers
#include "LinkedList.h"
using namespace std;

// KEYS FOR NODE 
//MALE   : 1
//FEMALE : 2
//AGE    : 3	
//ACTOR + SINGER : 4
//ALIVE : 5
//MARRIED : 6
// RELIGION : 8		MUSLIM


class Node{
	public:
		int domain;
		vector<Node*> child;
};

class TREE{
	public:
		
		Node *create_Node(int key){
			Node *temp = new Node;
			temp->domain = key;
			return temp;
		}
		
		void Traverse(Node *root){
			queue<Node *>q;
			q.push(root);
			while(!q.empty()){
				int size = q.size();
				for(int i=0;i<size;i++){
					
					Node *ptr = q.front();
					q.pop();
					cout<<ptr->domain<<" ";
					int count = 0;
					// pushing children of each node
					while(count<ptr->child.size()){
						q.push(ptr->child[count]);
						count++;
					}
					
				}
			}
		}
		
//		bool search_from_file(char filename[],int key){
//			ifstream file_ptr;
//			
//			file_ptr.open(filename,ios::in);
//			int x;
//			string ques;
//			queue<Node *>q;
//			q.push(root);
//			while(!q.empty()){
//				int size = q.size();
//				for(int i=0;i<size;i++){
//					
//					Node *ptr = q.front();
//					q.pop();
//					int count = 0;
//					// printing children of each Nodes by pushing into queue
//					while(count<ptr->child.size()){
//						q.push(ptr->child[count]);
//						count++;
//					}
//					
//				}
//			}
//		}
			
//			while(file_ptr){
//				file_ptr.ignore();
//				getline(file_ptr,ques);
//				file_ptr>>x;
//				if(x==4)
//					return true;
//			}
//			return false;
	
};

// function to speak
void speak(string phrase){
	string command = "espeak \"" + phrase + "\"";
	const char* char_command = command.c_str();
	system(char_command);
}
void speak_any_key(){
	string phrase =" Press ANY KEY TO CONTINUE";
	string command = "espeak \"" + phrase + "\"";
	const char* char_command = command.c_str();
	system(char_command);
}
class ANSWER{
	private :
		char ans[];
		int key;
		
	public:
		
		bool get_answer(){
			cout<<"\n\t(YES/NO) : ";cin>>ans;
			if(strcmp(ans,"Yes")==0 || strcmp(ans,"yes")==0 || strcmp(ans,"YES")==0){
				key = 1;
				return true;
			}
			else if(strcmp(ans,"No")==0 || strcmp(ans,"no") == 0 || strcmp(ans,"NO")==0 )
			{
				key = 0;
				return false;
			}
		}	
		
	
};
class M_Personality{
	private:
		int dom,size;
		bool flag ;
	public:
		M_Personality(){
			this->size = 0;
			this->dom = 0;
			this->flag = true;
		}
		int check_personality(LinkedList &obj){
			Fawwad fwd;
			Ahad ahd;
			ImranAbbas ima;
			Hamza hz;
			Daniyal dy;
			Abid abd;
			
			size = obj.size();
			if(fwd.check_in_file(obj,dom,size,flag)){
				return 1;
			}
			else if(ahd.check_in_file(obj,dom,size,flag)){
				return 2;
			}
			else if(ima.check_in_file(obj,dom,size,flag)){
				return 3;
			}
			else if(hz.check_in_file(obj,dom,size,flag)){
				return 4;
			}
			else if(dy.check_in_file(obj,dom,size,flag)){
				return 5;
			}
			else if(abd.check_in_file(obj,dom,size,flag)){
				return 6;
			}
			return 0;
		}
};
class F_Personality{
	private:
		int dom,size;
		bool flag ;
	public:
		F_Personality(){
			this->size = 0;
			this->dom = 0;
			this->flag = true;
		}
		int check_personality(LinkedList &obj){
			Hira hr;
			Alizeh alz;
			Hania hn;
			Iqra iq;
			Sunita sn;
			Zaheen zh;
			
			size = obj.size();
			if(hr.check_in_file(obj,dom,size,flag)){
				return 1;
			}
			else if(alz.check_in_file(obj,dom,size,flag)){
				return 2;
			}
			else if(hn.check_in_file(obj,dom,size,flag)){
				return 3;
			}
			else if(iq.check_in_file(obj,dom,size,flag)){
				return 4;
			}
			else if(sn.check_in_file(obj,dom,size,flag)){
				return 5;
			}
			else if(zh.check_in_file(obj,dom,size,flag)){
				return 6;
			}
			return 0;
		}
};


class QUESTIONS{
	private:
		string ques;
		int key;
	public:
		QUESTIONS(){
			this->ques = " ";
			this->key = 0;
		}
		
		
		void Print_Questions(Node *temp,char filename[]){
			// objects of male_actors
			Fawwad fwd;
			Ahad ahd;
			ImranAbbas ia;
			Hamza hz;
			Daniyal dy;
			Abid abd;
			// objects of female_actors
			Hira hr;
			Alizeh alz;
			Hania hn;
			Iqra iq;
			Sunita sn;
			Zaheen zh;
			
			M_Personality pers;
			F_Personality f_pers;
			
			LinkedList lst;
			ANSWER ans_obj;
			ifstream file_ptr;
			int x,check_gender;
			string phrase;
			
//			char male_filenames[][20]= {"fawwad.txt","ahad.txt","imranabbas.txt","hamza.txt","Daniyal.txt"};
//			char female_filenames[][20]={"Hira.txt"};
			string ques;
			queue<Node *>q;
			queue<Node *>q2;
			q.push(temp);
			while(!q.empty()){	// if queue is empty simply exit
				int size = q.size();
				for(int i=0;i<size;i++){
						Node *ptr = q.front();
						q2.push(ptr);
						q.pop();
						
						int count = 0;
						while(count<ptr->child.size()){
							q.push(ptr->child[count]);
							count++;
						}
					}
				}
				cout<<endl<<endl;
				int count = 0;
				int offset;
				Node *ptr;
				while(!q2.empty()){
				file_ptr.open(filename,ios::in);
					int size = q2.size();
					for(int i=0;i<size;i++){
						ptr = q2.front();
						q2.pop();
						if(find_in_file(filename,ptr->domain)){
							count++;
							int var_for_list = ans_obj.get_answer();
							lst.insert_at_last(var_for_list);
							// if male
							if(count==1){
								if(lst.head->data == 1){
									lst.insert_at_last(0);
									q2.pop();
								}
								// if female
								else if(lst.head->data == 0){
									lst.insert_at_last(1);
									q2.pop();
								}
							}
				
							if(lst.head->data == 1){
								if(count == 6){
									int var = pers.check_personality(lst);
									switch(var){
										case 1:{
											if(fwd.check_pers()){
												cout<<"\n\n YOU GUESSED FAWWAD KHAN ?"<<endl;
												phrase = "YOU GUESSED FAWWAD KHAN ?";
												speak(phrase);
												if(ans_obj.get_answer()){
//													phrase = "HUUUUUUUUURAAAHHHHH!";
//													speak(phrase);
													cout<<" I WAS RIGHT!!";
													speak("I WAS RIGHT");
												}
											}
											break;
										}
										case 2:{
											if(ahd.check_pers()){
												cout<<"\n\n YOU GUESSED Ahad Raza Mir?  : ";
												phrase = "YOU GUESSED AHAD RAZA MIR ?";
												speak(phrase);
												if(ans_obj.get_answer()){
													phrase = "HUUUURAAAHHHHH!";
													speak(phrase);
													cout<<" I WAS RIGHT!!";
													speak("I WAS RIGHT");
												}
											}
											break;
										}
										case 3:{
											if(ia.check_pers()){
												cout<<"\n\n YOU GUESSED Imran Abbas?  : ";
												phrase = "YOU GUESSED IMRAN ABBAS ?";
												speak(phrase);
												if(ans_obj.get_answer()){
													phrase = "HUUUURAAAHHHHH!";
													speak(phrase);
													cout<<" I WAS RIGHT!!!";
													speak("I WAS RIGHT");
												}
											}
											break;
										}
										case 4:{
												if(hz.check_pers()){
												cout<<"\n\n YOU GUESSED Hamza Ali Abbasi? : ";
												phrase = "YOU GUESSED Hamza Ali Abbasi ?";
												speak(phrase);
												if(ans_obj.get_answer()){
													phrase = "HUUUURAAAHHHHH!";
													speak(phrase);
													cout<<" I WAS RIGHT!!!";
													speak("I WAS RIGHT");
												}
											}
											break;
										}
										case 5:{
											if(dy.check_pers()){
												cout<<"\n\n YOU GUESSED Daniyal Zafar? : ";
												phrase = "YOU GUESSED DANIYAL ZAFAR ?";
												speak(phrase);
												if(ans_obj.get_answer()){
													phrase = "HUUUURAAAHHHHH!";
													speak(phrase);
													cout<<" I WAS RIGHT!!!";
													speak("I WAS RIGHT");
												}
											break;
										}
									}
									case 6:{
										if(abd.check_pers()){
											cout<<"\n\n YOU GUESSED Abid Ali? : ";
											phrase = "YOU GUESSED ABID ALI?";
											speak(phrase);
											if(ans_obj.get_answer()){
												phrase = "HUUUURAAAHHHHH!";
												speak(phrase);
												cout<<" I WAS RIGHT!!!";
												speak("I WAS RIGHT");
											}
											
										}
										break;
									}
								}	// end of switch
									return;
								}
							}
							// if FEMALE
							else if(lst.head->data == 0){
								if(count == 6){
									int var = f_pers.check_personality(lst);
									switch(var){
										case 1:{
											if(hr.check_pers()){
												cout<<"\n\n YOU GUESSED Hira Mani ?"<<endl;
												phrase = "YOU GUESSED HIRA MANI?";
												speak(phrase);
												if(ans_obj.get_answer()){
													phrase = "HUUUURAAAHHHHH!";
													speak(phrase);
													cout<<" I WAS RIGHT!!!";
													speak("I WAS RIGHT");
												}
											}
											break;
										}
										case 2:{
											if(alz.check_pers()){
												cout<<"\n\n YOU GUESSED Alizeh Shah ?"<<endl;
												phrase = "YOU GUESSED ALIZEH SHAH?";
												speak(phrase);
												if(ans_obj.get_answer()){
													phrase = "HUUUURAAAHHHHH!";
													speak(phrase);
													cout<<" I WAS RIGHT!!!";
													speak("I WAS RIGHT");
												}	
											} // end of if(alz)
											else
											{
												if(hn.check_pers()){
												cout<<"\n\n YOU GUESSED Hania Amir?"<<endl;
												phrase = "YOU GUESSED HANIA AMIR?";
												speak(phrase);
												if(ans_obj.get_answer()){
													phrase = "HUUUURAAAHHHHH!";
													speak(phrase);
													cout<<" I WAS RIGHT!!!";
													speak("I WAS RIGHT");
													}
												}
														
											}// end of else
											break;
										}	
										case 3:{
											if(hn.check_pers()){
												cout<<"\n\n YOU GUESSED Hania Amir?"<<endl;
												phrase = "YOU GUESSED HANIA AMIR?";
												speak(phrase);
												if(ans_obj.get_answer()){
													phrase = "HUUUURAAAHHHHH!";
													speak(phrase);
													cout<<" I WAS RIGHT!!!";
													speak("I WAS RIGHT");
												}
											}
											break;
										}
										case 4:{
											if(iq.check_pers()){
												cout<<"\n\n YOU GUESSED Iqra Aziz?"<<endl;
												phrase = "YOU GUESSED Iqra Aziz?";
												speak(phrase);
												if(ans_obj.get_answer()){
													cout<<" I WAS RIGHT!!!";
													speak("I WAS RIGHT");
												}
											}
											break;
										}
										case 5:{
											if(sn.check_pers()){
												cout<<"\n\n YOU GUESSED Sunita Marshal?"<<endl;
												phrase = "YOU GUESSED Sunita Marshal?";
												speak(phrase);
												if(ans_obj.get_answer()){
													phrase = "HUUUURAAAHHHHH!";
													speak(phrase);
													cout<<" I WAS RIGHT!!!";
													speak("I WAS RIGHT");
												}
											}
											break;
										}
										case 6:{
											if(zh.check_pers()){
												cout<<"\n\n YOU GUESSED Zaheen Tahira?"<<endl;
												phrase = "YOU GUESSED ZAHEEN TAHIRA?";
												speak(phrase);
												if(ans_obj.get_answer()){
													phrase = "HUUUURAAAHHHHH!";
													speak(phrase);
													cout<<" I WAS RIGHT!!!";
													speak("I WAS RIGHT");
												}
											}
											break;
										}
										
									}		// end of switch
									return;
								}	
									
								}
							else{
								cout<<" INVALID INPUT !!!"<<endl;
								cout<<" Press Any Key To Continue";
								return;
								}	
							}
						}	// end of for
					}	// end of while
//					cout<<endl<<endl<<" Answers : "<<endl;lst.display();
						return;
				}		// end of Print Questions
				
			
		
		
	bool find_in_file(char filename[],int key){
	
			  	ifstream fin(filename,ios::in); 
  				string ques1; 
  				int a; 
  				getline(fin,ques1); 
  				fin>>a; 
  				while(fin) 
  				{ 
  					if(a==key){
    					cout<<ques1<<" : ";
  						speak(ques1);
						return true; 
					  }
					fin.ignore(); 
    				getline(fin,ques1); 
    				fin>>a; 
  				}   
				  return false; 
  				fin.close(); 
		}		// end of find in file
};

// function to print letter by letter
void print(string a){
	for(int i=0;i<a.length();i++){
		cout<<a[i]<<" ";
		Sleep(100);
	}
}





main(){
	TREE obj;
	// 	creating THE QUESTION TREE
	Node *root = obj.create_Node(0);
//	obj.Traverse(root);
//	cout<<endl<<" Tree with children : "<<endl;
	root->child.push_back(obj.create_Node(1)) ;
	root->child.push_back( obj.create_Node(2));
//	obj.Traverse(root);
//	cout<<endl<<" Complete Tree : "<<endl;
	root->child[0]->child.push_back(obj.create_Node(4));
	root->child[0]->child.push_back(obj.create_Node(8));
	root->child[0]->child.push_back(obj.create_Node(5));
	root->child[0]->child[2]->child.push_back(obj.create_Node(3));
	root->child[0]->child[2]->child.push_back(obj.create_Node(6));
//	obj.Traverse(root);
	
	
	QUESTIONS q;
	cout<<endl<<endl;
	char filename[] = "questions.txt";
	while(1){
		
		system("cls");
		string phrase1 = "HELLO   USER ";
		string phrase = "WELCOME TO ROTANIKA 1.O";
		string command = "espeak \"" + phrase + "\"";
		const char* char_command = command.c_str();
	
		string command1 = "espeak \"" + phrase1 + "\"";
		const char* char_command1 = command1.c_str();
		cout<<setw(35);print("WELCOME TO ROTANIKA 1.0");
		
		system(char_command1);
		system(char_command);
		
		cout<<"\n\n Think of Any Character From The List below : "<<endl<<endl;
		phrase = "Think of Any Character From The List below";
		speak(phrase);
		cout<<"Male\n\n  1 - Fawwad Khan\n 2- Ahad Raza Mir \n 3- Imran Abbas \n 4- Hamza Ali Abbasi \n 5- Daniyal Zafar \n 6- Abid Ali";
		cout<<endl<<endl<<"Female\n\n 1- Hira Mani \n 2- Alizeh Shah \n 3- Hania Amir \n 4- Iqra Aziz \n 5- Sunita Marshal \n 6- Zaheen Tahira";
		
		cout<<"\n\n\n"<<endl<<endl;
		speak_any_key();
		cout<<endl<<endl<<endl<<"\n\n PRESS ANY KEY TO CONTINUE..";
		getchar();
		system("cls");
		q.Print_Questions(root,filename);
		speak_any_key();
		cout<<endl<<endl<<endl<<"\n\n PRESS ANY KEY TO CONTINUE..";
		getchar();
	}
	
}

//class Node{
//	public:
//		char quest[50];
//		int domain;
//		Node *child;
//};
//class Q_TREE{
//	public:
//		Node *root;
//		Q_TREE(){
//			root = new Node;
//			root->domain = 0;
//		}
//		
//		void insert(int key){
//			Node *temp = new Node;
//				temp->child = NULL;
//			if(root == NULL){
//				root = temp;
//			}
//			else{
//				Node *ptr;
//				cout<<ptr->domain<<" ";
//			}
//		}
//		bool isLeaf(Node* root)
//	{
//    	if(root == NULL){cout<<"ERROR"<<endl;return false;}
//    	if(root->child == NULL)
//    	{
//       		return true;
//    	}
//    	return false;
//	}
//	void print_Question(){
//		Node *ptr;
//		ptr = root;
//		while(ptr!=NULL){
//			cout<<ptr->domain;
//			ptr = ptr->child;
//		}
//}
//};

	
//	stringstream ss;
//	ifstream file;
//	file.open("questions.txt");
//	Node *ptr;
//	ptr = obj.root;
//	int x=0;
//	int i = 0;
//	char ques[50];
//	string q1;
//	char g[50] = "Gender";
//	while(!file.eof()){
//		file>>ques;
//		if(strcmp(ques,g)==0){
//			file>>ques;
//			cout<<q1<<endl;
//		}
//		i++;		
//	}
//}




//main(){
//	Q_TREE tree;
//	tree.insert(0);
//	tree.insert(1);
//	tree.insert(330);
//	tree.insert(81);
//	tree.insert(6);
//	tree.insert(4);
//	tree.print_Question();
	
	
	



//}




//class NODE{
//	public:
//		int data;
//		string edu = "NULL";
//		NODE *next,*prev;
//};
//
//class LinkedList{
//	public:
//		NODE *head,*tail;
//		
//		// Default constructor
//		LinkedList(){
//			this->head = NULL;
//			this->tail = NULL;
//		}
//	void insert_at_last(int n){
//			// creating a new node
//			NODE *temp = new NODE;
//			temp->data = n;
//			temp->next = NULL;
//			if(head == NULL){		// it means there is no linked list
//				head = temp;
//				tail = temp;
//			}
//			else{
//				tail->next = temp;
//				tail = temp;
//			}
//		}
////			void insert_at_last(string n){
////			// creating a new node
////			NODE *temp = new NODE;
////			temp->edu = n;
////			temp->next = NULL;
////			if(head == NULL){		// it means there is no linked list
////				head = temp;
////				tail = temp;
////			}
////			else{
////				tail->next = temp;
////				tail = temp;
////			}
////		}
//		void display(){
//			NODE *temp;
//			temp = head;
//			if(head == NULL)
//			cout<<" There is no element in the list!!"<<endl;
//			while(temp!=NULL){
//				cout<<temp->data<<" ";
////				if(temp->edu==NULL)
////				cout<<temp->edu;
//				temp = temp->next;
//			}
//		}
//		void input_in_file(LinkedList obj){
//		ofstream file;
//		file.open("MALE/fawwad.txt",ios::app);
//		file.write((char*)&obj, sizeof(obj));
//		ifstream file1;
//		file1.open("MALE/fawwad.txt",ios::in);
//		file1.read((char*)&obj, sizeof(obj));
//		obj.display();
//		}
//		
//};
//main(){
//	LinkedList fawwad;
//	fawwad.insert_at_last(1);
//	fawwad.insert_at_last(4);
//	fawwad.insert_at_last(330);
//	fawwad.insert_at_last(81);
////	fawwad.insert_at_last("FAST");
//	fawwad.display();
//	fawwad.input_in_file(fawwad);
	
//}



//class Question_TREE{
//	public:
//		Node *root;
//		Question_TREE(){
//			root = NULL;
//		}
//		void create_tree(){
//			Node *temp = new Node;
//				root = temp;
//				root->quest = 0;
//				Node *l = new Node;
//				Node *r = new Node;
//				root->left = l;
//				root->right = r;
//				left->quest =  1;	// male
//				right->quest  = 2;	// female
//			Node *Age = new Node;	
//			
//				Node *ptr;
//				ptr = root->left ;
//				Age = ptr->child_ptr; 	// age
//				Age->quest = 3;
//				
//			Node *Religion = new Node;
//				Node *ptr;
//				ptr = root->left;
//				Religion = ptr->child_ptr2;
//				Religion->quest = 8	
//				
//			
//		}
//		
//		int get_quest(Node *temp){
//				return temp->quest;
//		}
//
//	
//
//};

