//SOURCE: linkedlist.cpp
//EXERCISE: Set 5 Question
//AUTHOR: Meenal Chaudhari
//DATE: 01/28/2017
//EMAIL: mchaudhari@aggies.ncat.edu
//DESCRIPTION: build a linkedlist with three elements with 7 assignment operations 
#include <iostream.h>
#include <string.h>
using namespace std;
//declaration of structure for the node
struct Node {
	int data;
	Node *next;
	};
//For creation of nodes
void addNode(struct Node *head, int n)
	{
	Node *newNode;
	//Allocate memory
	newNode = (Node*)malloc(sizeof(node));
	newNode->data=n;
	newNode->next=NULL;
	Node *cur=head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
			}
		cur = cur->next;
		}
	}
//Display the result
void display(struct Node *head) {
	Node *list = head;
	while(list) {
		cout << list->data << " ";
		list = list->next;
		}
	cout << endl;
	cout << endl;
	}
int main()
	{
	// struct Node *newHead;
	struct Node *head = new Node;
	//initialize first node
	initNode(head,0);
	display(head);
	addNode(head,20);
	display(head);
	addNode(head,30);
	display(head);
	return 0;
	}