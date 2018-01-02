#include<iostream>
using namespace std;

// defining the node data structure
struct Node
{
	int data; // the data
	struct Node *next; // pointer to the next memory location
};

// making it a class
class singlyLinkedList{
public:
	singlyLinkedList(){
		head = NULL; tail = NULL;
	}
	// function to add a new node to the linked list to teh last location
	void add_node(int n){
		Node *temp = new Node;
		temp -> data = n; // loading the data
		temp -> next = NULL;

		if (head == NULL){
			head = temp; // since head == NULL this is the first element
			tail = temp; // thus both head will be temp and also the last
			// element thus tail is temp too
		}
		else{
			tail -> next = temp; // adding the element at last 
			tail = tail -> next; // basically shifting the tail to the end of new node
		}
	};

	// function to add the element to the front of the list
	void add_front(int n){
		Node *temp = new Node;
		temp -> data = n;
		temp -> next = head; // linking the back of linked list to the head of current list
		head = temp; // making the head of new node the new head
	}

	// function to add an element in the middle after the given node
	void add_after(Node *a, int value){
		Node *p = new Node;
		p->data = value;
		p->next = a->next; // linking the next of a to back of p
		a->next = p; // linking the back of a to p
	}

	// function to delete any node in the linked list
	void del(Node *before_del){
		Node *temp;
		temp = before_del->next; // connect the temp the one to be deleted
		// as the next to before_del the one we want to delete
		before_del->next = temp->next; // link the before_del block to the one after del
		delete temp; // delete the current node 
	}

	// function to display all the elements of the linked list using while loop
	void display_normal(){
		Node *temp = head;
		while(temp != NULL){
			cout << temp->data << "\t";
			temp = temp->next;
		}
	};

	// function to display elements of linked list using recursion
	// for this we also need the first node in the list thus we need to make
	// a seperate function
	Node *get_head(){
		return head;
	}

	// static function means that they are class function and not that
	// of the invoked object, so they can be called as class::static_func
	// as well as that of invoked object
	// https://www.geeksforgeeks.org/static-keyword-cpp/
	static void display_rec(Node *head){
		if (head != NULL){
			cout << head->data << "\t";
			display_rec(head->next);
		}
	}

	// now what if we have two different linked lists that we would
	// like to merge (concatenate). All we need to do is link the end
	// of one of the list to the start of second 
	static void concatenate(Node *a, Node *b){
		if(a!=NULL && b!=NULL){
			if(a->next == NULL){
				a->next = b;
			}
			else{
				concatenate(a->next, b);
			}
		}
		else{
			cout << "Either a or b is empty";
		}
	}
private:
	Node *head, *tail;
};

int main(){
	singlyLinkedList a, b;
	a.add_node(1); a.add_node(2); a.add_node(3);
	// since display_rec is a static function we can call it as
	// funtion of the class. if it were not static we get the error
	// call to non-static member function without an object argument
	singlyLinkedList::display_rec(a.get_head());
	cout << endl;
	b.add_node(4); b.add_node(5); b.add_node(6);
	// since display_rec is a static function, we can use it from
	//invoked object also
	b.display_rec(b.get_head());
	cout << endl;
	a.concatenate(a.get_head(), b.get_head());
	a.display_rec(a.get_head());
	return 0;
}

/*
The code below is a very C-style of doing things so we do not
implement it, rather prefer the method above
// to traverse the list we use external function
void printList(struct Node *n){
	while(n != NULL){
		cout << n-> data << "\t";
		n = n->next;
	}
}

// main function
int main(){
	struct Node *head = NULL;
	struct Node *second = NULL;
	struct Node *third = NULL;

	// allocate 3 nodes in a heap
	head = (struct Node*) malloc(sizeof(struct Node));
	second = (struct Node*) malloc(sizeof(struct Node));
	third = (struct Node*) malloc(sizeof(struct Node));

	head -> data = 1; // assign data in first node
	head -> next = second; // link first node with second

	second -> data = 2; second -> next = third;
	third -> data = 3; third -> next = NULL;

	printList(head);

	return 0;
}
*/
