#pragma once
#include <stdlib.h>
#include <time.h>
#include "Project.h";
#include "Crew.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>;

using std::cin;
using std::cout;
using std::ofstream;
using std::string;
using std::vector;

class LinkedListCrew
{
public:
	//Default Constructor 
	LinkedListCrew();
	
	//Declares the structure for a crew node
	struct node {
		Crew data;
		node* next;
	};

	//Member Declarations
	node* getMiddle(node* head);
	node * merge(node * lower, node * upper);
	node * sort(node * head);
	node* loadList();
	void writeList(string fileName, LinkedListCrew::node* head);
	void printLinkedList(node* head);
	void append(node *head, Crew c);
	node* searchList(std::string title, node *head);
	void deleteNode(node* n, node* head);
	void edit(node *head, node* e, Crew p);
	//LinkedListCrew Variable Declarations
	bool first = true;
};

