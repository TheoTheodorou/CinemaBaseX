#include "stdafx.h"
#include "Crew.h"

//Default Constructor
Crew::Crew() {}

//Crew Constructor
Crew::Crew(string input_producer, string input_director, string input_writer, string input_editor,
	string input_production_designer, string input_set_decorator, string input_costume_designer, vector<string> input_cast)
{
	//Definitions for all variables
	producer = input_producer;
	director = input_director;
	writer = input_writer;
	editor = input_editor;
	production_designer = input_production_designer;
	set_decorator = input_set_decorator;
	costume_designer = input_costume_designer;
	cast = input_cast;

}

//This function will read in all the information stored in the crew.txt file. After reading this information in, we send it to the split function which removes
//any symbols we pass through the parameter. It will then return a series of tokens which is stored into a vector<string>. This vector is then added to
//a list of crews which is then returned to the LinkedListCrew.cpp for further processing.
vector<Crew>Crew::readCrew()
{
	vector<Crew> crewList;

	ifstream read("crews.txt"); //opens an fstream for file reading
	string fileContents((std::istreambuf_iterator<char>(read)), std::istreambuf_iterator<char>());

	vector<string>crew_list = split(fileContents, '@');

	for (int i = 0; i < crew_list.size(); i++)
	{
		vector<string> att_list = split(crew_list[i], ',');
		vector<string> cast_list = split(att_list[7], '%');
		crewList.push_back(Crew(att_list[0], att_list[1], att_list[2], att_list[3], att_list[4], att_list[5], att_list[6], cast_list));
	}

	return crewList;
}

//This split function is used to retrieve tokens from a string which contains a set of symbols.
//Essentially the symbols are removed from the string(s) and a vector<string> of tokens is returned for further processing.
vector<std::string> Crew::split(std::string str, char splitter)
{
	vector<int> symbols;
	vector<string> tokens;
	for (size_t i = 0; i<str.length(); i++) {
		if (str[i] == splitter) {
			symbols.push_back(i);
		}
	}
	for (size_t i = 0; i<symbols.size() + 1; i++) {
		if (i == 0)
			tokens.push_back(str.substr(0, symbols[i]));
		else if (i == symbols.size()) {
			tokens.push_back(str.substr(symbols[i - 1] + 1));
		}
		else
			tokens.push_back(str.substr(symbols[i - 1] + 1, symbols[i] - symbols[i - 1] - 1));
	}
	return tokens;
}