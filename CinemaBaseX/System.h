#pragma once

#include "LinkedListProject.h"
#include "LinkedListMaterials.h"
#include "LinkedListCrew.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::string;



#pragma once
class System
{
public:
	//Default Constructor
	System();
	//Member Declarations
	bool Run();
	void Shutdown();
	LinkedListProject ProjectList;
	LinkedListMaterials MaterialList;
	LinkedListCrew CrewList;
	LinkedListProject::node* projectHead;
	LinkedListMaterials::node* materialHead;
	LinkedListCrew::node* crewHead;
	Project addProject(LinkedListProject::node* head);
	void editProject();
	void modifyMaterials();
	void modifyCrew();
	Material addMaterial();
	void editMaterial();
	Crew addCrew();
	void editCrew();
};

