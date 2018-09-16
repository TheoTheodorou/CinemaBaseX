#pragma once
#include <stdlib.h>
#include <time.h>
#include "Project.h";
#include <iostream>
#include <string>
#include <fstream>
#include <vector>;

using std::cin;
using std::cout;
using std::ofstream;
using std::string;
using std::vector;


#pragma once
class LinkedListProject
{
public:
	//Default Constructor
	LinkedListProject();

	//Declaration for project node structure 
	struct node {
		Project data;
		node* next;	
	};
	//Member Declarations
	node* getMiddle(node* head);
	node * merge(node * lower, node * upper);
	node * sort(node * head);
	node* loadList();
	void writeList(string fileName, LinkedListProject::node* head);
	void printLinkedList(node* head);
	void append(node *head, Project p);
	node* searchListbyTitle(string title, node *head);
	node* searchListbyID(string id, node *head);
	void deleteNode(node* n, node* head);
	void edit(node *head, node* e, Project p);
	//Linked List Project variable declarations
	bool first = true;


};

