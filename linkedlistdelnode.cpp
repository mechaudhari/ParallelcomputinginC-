//SOURCE: linkedlistdelnode.cpp
//EXERCISE: Set 5 Question
//AUTHOR: Meenal Chaudhari
//DATE: 01/28/2017
//EMAIL: mchaudhari@aggies.ncat.edu
//DESCRIPTION: delete a node from a linkedlist

#include <iostream>
#include <string>
using namespace std;
//Structure to create node
	struct Node {
	int data;
	Node *next;
	};
//For the creation of first node
void initNode(struct Node *head, int n)
	{
	head->data=NULL;
	head->next=NULL;
	}
//For the creation of the next nodes
void addNode(struct Node *head, int n)
	{
	Node *newNode=new Node;
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
//To display the result
void display(struct Node *head) {
	Node *list = head;
	while(list) {
		cout << list->data << " ";
		list = list->next;
		}
	cout << endl;
	cout << endl;
	}
//To search the node
struct Node *searchNode(struct Node *head, int n) {
	Node *cur = head;
	while(cur) {
		if(cur->data == n) return cur;
		cur = cur->next;
		}
	cout << "No Node " << n << " in list.\n";
	}
//To delete the node
bool deleteNode(struct Node **head, Node *ptrDel) {
	Node *cur = *head;
	if(ptrDel == *head) {
		*head = cur->next;
		delete ptrDel;
		return true;
		}
	while(cur) {
		if(cur->next == ptrDel) {
			cur->next = ptrDel->next;
			delete ptrDel;
			return true;
			}
		cur = cur->next;
	}
	return false;
}
void deleteLinkedList(struct Node **node)
	{
	struct Node *tmpNode;
	while(*node) {
		tmpNode = *node;
		*node = tmpNode->next;
		delete tmpNode;
		}
	}
int main(){
	// struct Node *newHead;
	struct Node *head = new Node;
	initNode(head,10);
	display(head);
	addNode(head,20);
	display(head);
	addNode(head,30);
	display(head);
	int numDel = 5;
	Node *ptrDelete = searchNode(head,numDel);
	if(deleteNode(&head,ptrDelete))
		cout << "Node "<< numDel << " deleted!\n";
	display(head);
	return 0;
	}