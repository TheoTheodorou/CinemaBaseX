#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE CinemaBaseXtestModule
#include <boost/test/unit_test.hpp>


#include "Crew.h"
#include "LinkedListCrew.h"
#include "LinkedListMaterials.h"
#include "LinkedListProject.h"
#include "Material.h"
#include "Project.h"
#include "System.h"


/*//SYSTEM TESTS - SYSTEM TESTS - SYSTEM TESTS - SYSTEM TESTS - SYSTEM TESTS - SYSTEM TESTS - SYSTEM TESTS - SYSTEM TESTS - 
//SYSTEM TESTS - SYSTEM TESTS - SYSTEM TESTS - SYSTEM TESTS - SYSTEM TESTS - SYSTEM TESTS - SYSTEM TESTS - SYSTEM TESTS - 
BOOST_AUTO_TEST_SUITE( system_Tests )

	BOOST_AUTO_TEST_CASE(test_name)
	{
		//BOOST_CHECK_EQUAL( dataToTest , answerItShouldBe );
	}

BOOST_AUTO_TEST_SUITE_END()*/


//PROJECT TESTS - PROJECT TESTS - PROJECT TESTS - PROJECT TESTS - PROJECT TESTS - PROJECT TESTS - PROJECT TESTS - PROJECT TESTS - 
//PROJECT TESTS - PROJECT TESTS - PROJECT TESTS - PROJECT TESTS - PROJECT TESTS - PROJECT TESTS - PROJECT TESTS - PROJECT TESTS - 
BOOST_AUTO_TEST_SUITE(project_Tests)

	BOOST_AUTO_TEST_CASE(projectsFileCanBeOpened_Test) //Testing that the file "projects.txt" can be opened
	{
		ifstream read("projects.txt");
		bool opens = false;
		if (read.is_open()) opens = true;
		BOOST_CHECK_EQUAL( opens , true );
	}

	BOOST_AUTO_TEST_CASE(projectSplitFunction_Test) //Testing the project split function
	{
		std::string test_string = "This.is,a...test,string.done.";
		vector<string> test_list = Project::split(test_string, '.');
		//test list should be this/is,a/test,string/done
		BOOST_CHECK_EQUAL( test_list[0] , "this" );
		BOOST_CHECK_EQUAL(test_list[1], "is,a");
		BOOST_CHECK_EQUAL(test_list[2], "test,string");
		BOOST_CHECK_EQUAL(test_list[3], "done");
	}

BOOST_AUTO_TEST_SUITE_END()


//MATERIAL TESTS - MATERIAL TESTS - MATERIAL TESTS - MATERIAL TESTS - MATERIAL TESTS - MATERIAL TESTS - MATERIAL TESTS - MATERIAL TESTS - 
//MATERIAL TESTS - MATERIAL TESTS - MATERIAL TESTS - MATERIAL TESTS - MATERIAL TESTS - MATERIAL TESTS - MATERIAL TESTS - MATERIAL TESTS - 
BOOST_AUTO_TEST_SUITE(material_Tests)

	BOOST_AUTO_TEST_CASE(materialsFileCanBeOpened_Test) //Testing that the file "materials.txt" can be opened
	{
		ifstream read("materials.txt");
		bool opens = false;
		if (read.is_open()) opens = true;
		BOOST_CHECK_EQUAL(opens, true);
	}

	BOOST_AUTO_TEST_CASE(materialtSplitFunction_Test) //Testing the material split function
	{
		std::string test_string = "This.is,a...test,string.done.";
		vector<string> test_list = Material::split(test_string, '.');
		//test list should be this/is,a/test,string/done
		BOOST_CHECK_EQUAL(test_list[0], "this");
		BOOST_CHECK_EQUAL(test_list[1], "is,a");
		BOOST_CHECK_EQUAL(test_list[2], "test,string");
		BOOST_CHECK_EQUAL(test_list[3], "done");
	}
BOOST_AUTO_TEST_SUITE_END()


//LINKED LIST PROJECT TESTS - LINKED LIST PROJECT TESTS - LINKED LIST PROJECT TESTS - LINKED LIST PROJECT TESTS - LINKED LIST PROJECT TESTS - LINKED LIST PROJECT TESTS - LINKED LIST PROJECT TESTS - LINKED LIST PROJECT TESTS - 
//LINKED LIST PROJECT TESTS - LINKED LIST PROJECT TESTS - LINKED LIST PROJECT TESTS - LINKED LIST PROJECT TESTS - LINKED LIST PROJECT TESTS - LINKED LIST PROJECT TESTS - LINKED LIST PROJECT TESTS - LINKED LIST PROJECT TESTS - 
BOOST_AUTO_TEST_SUITE(linkedListProject_Tests)

	BOOST_AUTO_TEST_CASE(LLPgetMiddle_test) //testing get LLP middle function
	{
	vector<Project> testList;

	ifstream read("testprojects.txt"); //opens an fstream for file reading
	string fileContents((std::istreambuf_iterator<char>(read)), std::istreambuf_iterator<char>());

	vector<string> test_list = Project::split(fileContents, '@');

	for (int i = 0; i < test_list.size(); i++)
	{

		vector<string> att_list = Project::split(test_list[i], ',');
		vector<string> materials_list = Project::split(att_list[1], '%');
		vector<string> keywords_list = Project::split(att_list[10], '%');
		vector<string> locations_list = Project::split(att_list[11], '%');

		if (att_list[9] == "unreleased" || att_list[9] == "now playing")
		{
			materials_list.clear();
			if (att_list[9] == "unreleased") {
				att_list[12].clear();
			}
		}

		testList.push_back(Project(att_list[0], materials_list, att_list[2], att_list[3], att_list[4], att_list[5], att_list[6], att_list[7], att_list[8], att_list[9], keywords_list, locations_list, att_list[12]));

	}
		
		int counter = 0;
		node* head = NULL;

		node* temp = head;
		for (int i = 0; i < testList.size(); i++)
		{
			temp = new node;
			temp->data = testList[i];
			temp->next = head;
			head = temp;
		}
		node* middle = LinkedListProject::getMiddle(head);
	
		BOOST_CHECK_EQUAL( middle->data.title , "PoolZander");
	}

	/*BOOST_AUTO_TEST_CASE(LLPmerge_test) //testing get LLP merge function
	{
		//BOOST_CHECK_EQUAL( dataToTest , answerItShouldBe );
	}

	BOOST_AUTO_TEST_CASE(LLPsort_test) //testing get LLP sort function
	{
		//BOOST_CHECK_EQUAL( dataToTest , answerItShouldBe );
	}

	BOOST_AUTO_TEST_CASE(LLPappend_test) //testing get LLP append function
	{
		//BOOST_CHECK_EQUAL( dataToTest , answerItShouldBe );
	}

	BOOST_AUTO_TEST_CASE(LLPdeleteNode_test) //testing get LLP delete node function
	{
		//BOOST_CHECK_EQUAL( dataToTest , answerItShouldBe );
	}*/

BOOST_AUTO_TEST_SUITE_END()


//LINKED LIST MATERIALS TESTS - LINKED LIST MATERIALS TESTS - LINKED LIST MATERIALS TESTS - LINKED LIST MATERIALS TESTS - LINKED LIST MATERIALS TESTS - LINKED LIST MATERIALS TESTS - LINKED LIST MATERIALS TESTS - LINKED LIST MATERIALS TESTS - 
//LINKED LIST MATERIALS TESTS - LINKED LIST MATERIALS TESTS - LINKED LIST MATERIALS TESTS - LINKED LIST MATERIALS TESTS - LINKED LIST MATERIALS TESTS - LINKED LIST MATERIALS TESTS - LINKED LIST MATERIALS TESTS - LINKED LIST MATERIALS TESTS - 
BOOST_AUTO_TEST_SUITE(linkedListMaterials_Tests)

	BOOST_AUTO_TEST_CASE(LLMgetMiddle_test) //testing get LLM middle function
	{
	vector<Material> materialList;

	ifstream read("materials.txt"); //opens an fstream for file reading
	string fileContents((std::istreambuf_iterator<char>(read)), std::istreambuf_iterator<char>());

	vector<string>material_list = Material::split(fileContents, '@');

	for (int i = 0; i < material_list.size(); i++)
	{
		vector<string> att_list = Material::split(material_list[i], ',');
		vector<string> packaging_list = Material::split(att_list[8], '%');
		vector<string> language_list = Material::split(att_list[9], '%');
		vector<string> subtitle_list = Material::split(att_list[10], '%');
		materialList.push_back(Material(att_list[0], att_list[1], att_list[2], att_list[3], att_list[4], att_list[5], att_list[6], att_list[7], packaging_list, language_list, subtitle_list, att_list[11]));
	}
		
	int counter = 0;
	node* head = NULL;
	node* temp = head;
	for (int i = 0; i < materialList.size(); i++)
	{
		temp = new node;
		temp->data = materialList[i];
		temp->next = head;
		head = temp;
	}
		node* middle = LinkedListMaterial::getMiddle(head);
		

		BOOST_CHECK_EQUAL( middle->data.id , "1");
	}

BOOST_AUTO_TEST_SUITE_END()


/*//LINKED LIST CREW TESTS - LINKED LIST CREW TESTS - LINKED LIST CREW TESTS - LINKED LIST CREW TESTS - LINKED LIST CREW TESTS - LINKED LIST CREW TESTS - LINKED LIST CREW TESTS - LINKED LIST CREW TESTS - 
//LINKED LIST CREW TESTS - LINKED LIST CREW TESTS - LINKED LIST CREW TESTS - LINKED LIST CREW TESTS - LINKED LIST CREW TESTS - LINKED LIST CREW TESTS - LINKED LIST CREW TESTS - LINKED LIST CREW TESTS - 
BOOST_AUTO_TEST_SUITE(linkedListCrew_Tests)

	BOOST_AUTO_TEST_CASE(dataToTest)
	{
		//BOOST_CHECK_EQUAL( dataToTest , answerItShouldBe );
	}

BOOST_AUTO_TEST_SUITE_END()*/


//CREW TESTS - CREW TESTS - CREW TESTS - CREW TESTS - CREW TESTS - CREW TESTS - CREW TESTS - CREW TESTS - 
//CREW TESTS - CREW TESTS - CREW TESTS - CREW TESTS - CREW TESTS - CREW TESTS - CREW TESTS - CREW TESTS - 
BOOST_AUTO_TEST_SUITE(crew_Tests)

BOOST_AUTO_TEST_CASE(crewSplitFunction_Test) //Testing the material split function
{
	std::string test_string = "This.is,a...test,string.done.";
	vector<string> test_list = Crew::split(test_string, '.');
	//test list should be this/is,a/test,string/done
	BOOST_CHECK_EQUAL(test_list[0], "this");
	BOOST_CHECK_EQUAL(test_list[1], "is,a");
	BOOST_CHECK_EQUAL(test_list[2], "test,string");
	BOOST_CHECK_EQUAL(test_list[3], "done");
}

BOOST_AUTO_TEST_SUITE_END()