#include "stdafx.h"
#include "LinkedListProject.h";
//Default Constructor
LinkedListProject::LinkedListProject() {

}

//This function loads the information stored on file into a newly generated linked list.
//This linked list is exclusive for storing information about the projects.
LinkedListProject::node* LinkedListProject::loadList() {
	//Creates a vector of projects which stores the information returned by the read projects function.
	vector<Project> projectList = Project::readProjects();
	node* head = NULL;
	node* temp = head;
	for (int i = 0; i < projectList.size(); i++)
	{
		temp = new node;
		temp->data = projectList[i];
		temp->next = head;
		head = temp;
	}
	//Returns the head node for processing
	return head;
}

//This functions takes the information stored within the projects linked list
//and outputs it to file.
void LinkedListProject::writeList(string fileName, LinkedListProject::node* head) {
	ofstream write;
	write.open(fileName, std::ios::app);
	if (head != NULL) {
		Project currProject = head->data;
		string projString = "";
		string materialString = "";
		string keywordString = "";
		string locationString = "";
		//These for loops will append a % for each material id, keyword and film locations within the linked list.
		for (int i = 0; i < currProject.material_ids.size(); i++)
		{
			materialString.append(currProject.material_ids[i] + "%");
		}
		materialString = materialString.substr(0, materialString.length() - 1);

		for (int i = 0; i < currProject.keywords.size(); i++)
		{
			keywordString.append(currProject.keywords[i] + "%");
		}
		keywordString = keywordString.substr(0, keywordString.length() - 1);

		for (int i = 0; i < currProject.filmLocations.size(); i++)
		{
			locationString.append(currProject.filmLocations[i] + "%");
		}
		locationString = locationString.substr(0, locationString.length() - 1);
		//appends to the project string
		projString += currProject.film_id + ",";
		projString += materialString + ",";
		projString += currProject.crew_id + ",";
		projString += currProject.title + ",";
		projString += currProject.summary + ",";
		projString += currProject.genre + ",";
		projString += currProject.releaseDate + ",";
		projString += currProject.language + ",";
		projString += currProject.runtime + ",";
		projString += currProject.status + ",";
		projString += keywordString + ",";
		projString += locationString + ",";

		if (first) 
		{
			projString += currProject.weeklySale;
		}

		else
		{
			projString += currProject.weeklySale + "@";
		}
		first = false;
		//outputs data to file
		write << projString;
		writeList(fileName, head->next);
		write.close();
	}

	return;
}
//This locates the middle node of a linked list.
LinkedListProject::node* LinkedListProject::getMiddle(node* head) {		//gets the middle of a linked list, returns pointer to the middle
	if (head == NULL) return head;	//if the linked list is empty return the head pointer
	node* slow = head;				//two pointers store the beginning of the linked list, one will traverse twice as fast as the other, when the faster one reaches the end, the slower one will be at the middle
	node* fast = head;
	while (fast->next != NULL && fast->next->next != NULL) {		//traverse the linked list
		slow = slow->next; fast = fast->next->next;					//traverse using the two pointers at different speeds
	}
	return slow;													//return the middle of the list
}
//This merges a linked list based off the if statement condition.
LinkedListProject::node * LinkedListProject::merge(node * lower, node * upper) {							//merges the lists taking the head pointer for each list
	node* head;
	node* nodeA;
	node* nodeB;
	node *dummy = new node();
	node *node = dummy;

	nodeA = lower;													//create a current pointer for traversal
	nodeB = upper;													//set the current to the head
	do {							//while both lists have not reached the end, continue traversing both and searching for the smallest item
		if ((nodeA->data.title.compare(nodeB->data.title)) < 0) {		//if the first list's next item is greater than the second's
			node->next = nodeA;									//add the second's next item to the new list
			nodeA = nodeA->next;									//move the first link on the second list to the next link, thereby reducing the size of the second list because the old first item has been taken
		}

		else {														//same logic, opposite conditions
			node->next = nodeB;
			nodeB = nodeB->next;
		}
		node = node->next;									//move to the next item on the new list
	} while (nodeA != NULL && nodeB != NULL);
	node->next = nodeA != NULL ? nodeA : nodeB;
	head = dummy->next;
	delete dummy;
	return head;
}
//This function begins the sort and merge of a given linked list.
LinkedListProject::node * LinkedListProject::sort(node * head) {											//main mergesort function
	if (head == NULL || head->next == NULL) return head;			//if the list is empty or the list only contains one element the linked list is already sorted, return the head
	node* middle = getMiddle(head);									//calls get middle function to get the middle of the list
	node* half = middle->next;										//set the middle's next pointer to null, thus breaking the link between the first half and the second half, divides the list into two
	middle->next = NULL;
	return merge(sort(head), sort(half));							//recursively break the linked list down until they are individual elements and then merge them together in sorted order
}
//This function will display a given linked list.
void LinkedListProject::printLinkedList(node* head)
{
	int num = 0;
	node* currNode = head;
	while (currNode != NULL)
	{
		cout << currNode->data.title << endl;
		currNode = currNode->next;
		num++;
	}
	cout << "---------------------------------------\nTotal Projects: " << num << endl;
}
//This function will insert a node and will assign the node data depending on what is receieved.
void LinkedListProject::append(node *head, Project p)
{
	if (head == NULL)
	{
		head->data = p;
		head->next = NULL;
	}
	else if (head != NULL)
	{
		while (head->next != NULL)
		{
			head = head->next;
		}
		head->next = new node;
		head->next->data = p;
		head->next->next = NULL;

	}
}
//This function will search a linked list based off the title parameter.
LinkedListProject::node* LinkedListProject::searchListbyTitle(string title, node *head) {
	node * current = head;
	while (current != NULL)
	{
		if (current->data.title == title) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

LinkedListProject::node* LinkedListProject::searchListbyID(string id, node *head) {
	node * current = head;
	while (current != NULL)
	{
		if (current->data.film_id == id) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

//This function will delete a given node at a given position
void LinkedListProject::deleteNode(node* n, node* head)
{
	// When node to be deleted is head node
	if (head == n)
	{
		if (head->next == NULL)
		{
			printf("There is only one node. The list can't be made empty ");
			return;
		}

		/* Copy the data of next node to head */
		head->data = head->next->data;

		// store address of next node
		n = head->next;

		// Remove the link of next node
		head->next = head->next->next;

		// free memory
		free(n);

		return;
	}


	// When not first node, follow the normal deletion process

	// find the previous node
	node* prev = head;
	while (prev->next != NULL && prev->next != n)
		prev = prev->next;

	// Check if node really exists in Linked List
	if (prev->next == NULL)
	{
		printf("\n Given node is not present in Linked List");
		return;
	}

	// Remove node from Linked List
	prev->next = prev->next->next;

	// Free memory
	free(n);

	return;
}