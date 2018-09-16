#pragma once
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

class Crew
{

public:
	//Crew Variables
	string producer, director, writer, editor, production_designer, set_decorator, costume_designer;
	vector<string> cast;

	//Default Constructor
	Crew();
	//Constructor
	Crew(string input_producer, string input_director, string input_writer, string input_editor, string input_production_designer, string input_set_decorator, string input_costume_designer, vector<string> input_cast);
	//Member Declarations
	static vector<Crew> readCrew();
private:
	static vector<std::string>split(std::string str, char splitter);
};

