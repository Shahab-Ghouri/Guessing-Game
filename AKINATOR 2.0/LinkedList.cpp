
#include <iostream>
using namespace std;
class NODE{
	public:
		int data;
		NODE *next;
};
class LinkedList{
	public:
		NODE *head,*tail;
		
		LinkedList();
		void insert_at_last(int);
		void display();
		int size();
};
		// Default constructor
	LinkedList::LinkedList(){
		this->head = NULL;
		this->tail = NULL;
	}
	void LinkedList::insert_at_last(int n){
//		 creating a new node
			NODE *temp = new NODE;
			temp->data = n;
			temp->next = NULL;
			if(head == NULL){		// it means there is no linked list
				head = temp;
				tail = temp;
			}
			else{
				tail->next = temp;
				tail = temp;
			}
	}
	
		
		void LinkedList::display(){
			NODE *temp;
			temp = head;
			if(head == NULL)
			cout<<" There is no element in the list!!"<<endl;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp = temp->next;
			}
		}
		int LinkedList::size(){
			int count;
			NODE *temp;
			temp = head;
			if(head==NULL)
				return 0;
			while(temp!=NULL){
				count++;
				temp = temp->next;
			}
			return count;	
		}	
