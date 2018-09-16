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
using std::cerr;

class LinkedListMaterials
{
public:
	//Default Constructor
	LinkedListMaterials();
	
	//Declaration for material node
	struct node {
		Material data;
		node* next;
	};
	//Member Declarations
	node* getMiddle(node* head);
	node * merge(node * lower, node * upper);
	node * sort(node * head);
	node* loadList();
	void writeList(string fileName, LinkedListMaterials::node* head);
	void printLinkedList(node* head);
	void append(node *head, Material m);
	node* searchList(std::string title, node *head);
	void deleteNode(node* n, node* head);
	void edit(node *head, node* e, Project p);
	node* searchListbyID(string id, node *head);
	//Linked List Material variable declarations
	bool first = true;
};

