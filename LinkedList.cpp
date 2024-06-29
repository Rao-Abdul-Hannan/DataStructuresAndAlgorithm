#include <iostream>
#include "Node.cpp"
	
using namespace std;

class LinkedList{
	Node *head;
public:
	LinkedList(){	head = NULL;	}
	void addNodeAtStart(int d){
		//please do paper work and understand that this statement will work in both cases i.e. where head is null and otherwise
		head = new Node(d, head);
	}
	void addNodeAtEnd(int d){
		Node *newNode = new Node(d, NULL);

		if (!head)
		{
			head = newNode;
			return;
		}

		Node *temp = head;
		while(temp -> next){		// temp -> next = *temp.next => jb tk aik aisa node mil rha ha jiske next ma koi address ha tb tk ye chlta jayega
			temp = temp -> next;
		}	
		temp -> next = newNode;	
	}
	void addNodeAtPosition(int d, int position)
	{
		if (position < 1)   // Invalid Position
		{
			cout << "Position should be greater than equal to 0" << endl;
		}
		else if (position == 1)    // Node should be added in the beginning so addNodeAtStart will work for it
		{
			addNodeAtStart(d);
			return;
		}
		Node *newNode = new Node(d);   // new node is created with next = NULL and data = d
		Node *temp = head;			// temporary pointer to point at first node whose address is in head
		for (int i = 1; i < position - 1 && temp; i++)   // agr position pr phnch gya tw bahir ajayega aur agr akhri node pr phnch gya tw bahir ajayega i.e. position out of range ha
		{
			temp = temp -> next;
		}
		if (!temp)		// if temp reaches at last node having next = NULL
		{
			cout << "Position out of range." << endl;
            delete newNode;		// new node is useless because it is added at position that does not exist in list
            return;
		}
		newNode -> next = temp -> next;
		temp -> next = newNode -> next;
	}
	void deleteNodeAtBeginning()
	{
		if (!head)		// agr head == NULL hai tw List empty hogi
		{
			cout << "List is empty" << endl;
			return;
		}
		Node *temp = head;	// head pointer sy agly node ko point krna ha agr temp ma head ko na rkhen aur head sy agly node ko point kr den tw pehle wala head memory leak kr de ga 
		head = head -> next;	// head pointer sy agly node ko point kr dia ha
		delete temp;			// pehle wala head ko delete kr dia
	}
	void deleteNodeAtEnd()
	{
		if (!head)	// agr head == NULL hai tw List empty hogi
		{
			cout << "List is empty" << endl;
			return;
		}
		if (!head -> next)		// agr aik hi node ha tw check krengy pehle waly head ke next ko
		{
			delete head;		// head ko delete kr dia aur usay phr NULL ke equal kr dia
			head = NULL;    	
			return;
		}
		Node *temp = head;
		while (temp -> next -> next)   // dekhain ge ke agr temp jis node ko point kr rha ha agr us sy agly wali node ka next == NULL ha tw ye bahir ajayega
		{
			temp = temp -> next;
		}
		delete temp -> next;		// deleting the position pointed by temp -> next i.e. last node
		temp -> next = NULL;		// phr us node ke next ko NULL kr ke osko akhri node bna dia
	}	
	void deleteNodeFromPosition(int position)
	{
		if (position < 1)
		{
			cout << "Position should be >= 1." << endl;
            return; 
		}
		if (position == 1) {
            deleteNodeAtBeginning();
            return;
        }
		Node *temp = head;
		for (int i = 0; i < position - 1 && temp; i++)
		{
			temp = temp -> next;
		}
		if (!temp || !temp -> next)
		{
			cout << "Position out of range" << endl;
			return;
		}
		Node *nodeToDelete = temp -> next;   // saving the address of node to be deleted
		temp -> next = temp -> next -> next;	// giving address of node to be deleted + 1 to node to be deleted -1
		delete nodeToDelete;
	}
	void show(){
		for ( Node *t = head; t != NULL ; t = t -> next)  // if started from head -> next i.e. 2nd node instead of first 
			cout << t -> data << ' ';
		cout << '\n' ;
	}

	// void check(){
	// 	cout << head->data << endl;
	// }
};
int main(){
	LinkedList list;
	list.addNodeAtStart(23);
	list.addNodeAtStart(31);
	// list.show();
	list.addNodeAtStart(11);
	// list.show();
	list.addNodeAtStart(21);
	list.show();

	return 0;
}
