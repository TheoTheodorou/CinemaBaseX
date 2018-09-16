#pragma once
#include "Material.h";
#include <iostream>
#include <fstream>
#include <string>;
#include <vector>;
using std::string;
using std::vector;
using std::ifstream;
using std::getline;
using std::endl;
using std::cout;
using std::cin;

class Project
{
public:
	//Project Variables
	string title, summary, genre, releaseDate, language, runtime, status,film_id, crew_id, weeklySale;
	vector<string> keywords, filmLocations, material_ids;

	//default constructor
	Project();
	
	//Constructor
	Project(string input_film_id, vector<string> input_material_ids, string input_crew_id, string input_title, string input_summary,
		string input_genre, string input_releaseDate, string input_language, string input_runtime, string input_status,
		vector<string> input_keywords, vector<string> input_filmLocations, string input_weeklySale);

	//Member Declarations
	static vector<Project> readProjects();
private:
	static vector<std::string>split(std::string str, char splitter);


};

