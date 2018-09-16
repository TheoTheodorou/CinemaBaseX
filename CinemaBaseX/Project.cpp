#include "stdafx.h"
#include "Project.h"
//Default Constructor
Project::Project(){}
//Project Constructor
Project::Project(string input_film_id, vector<string> input_material_ids, string input_crew_id, string input_title, string input_summary,
	string input_genre, string input_releaseDate, string input_language, string input_runtime, string input_status,
	vector<string> input_keywords, vector<string> input_filmLocations, string input_weeklySale) 
{
	film_id = input_film_id;
	material_ids = input_material_ids;
	crew_id = input_crew_id;
	title = input_title;
	summary = input_summary;
	genre = input_genre;
	releaseDate = input_releaseDate;
	language = input_language;
	runtime = input_runtime;
	status = input_status;
	keywords = input_keywords;
	filmLocations = input_filmLocations;
	weeklySale = input_weeklySale;

}
//This function will read in all the information stored in the projects.txt file. After reading this information in, we send it to the split function which removes
//any symbols we pass through the parameter. It will then return a series of tokens which is stored into a vector<string>. This vector is then added to
//a list of projects which is then returned to the LinkedListProject.cpp for further processing.
vector<Project>Project::readProjects()
{
	vector<Project> projectList;
	ifstream read("projects.txt"); //opens an fstream for file reading
	string fileContents((std::istreambuf_iterator<char>(read)), std::istreambuf_iterator<char>());
	vector<string> project_list = split(fileContents, '@');
	for (int i = 0; i < project_list.size(); i++)
	{
		vector<string> att_list = split(project_list[i], ',');
		vector<string> materials_list = split(att_list[1], '%');
		vector<string> keywords_list = split(att_list[10], '%');
		vector<string> locations_list = split(att_list[11], '%');
		//Checks to see if the film has been released...
		if (att_list[9] == "unreleased"|| att_list[9] == "now playing")
		{
			//...if its not been released there are no materials...
			materials_list.clear();
			if (att_list[9] == "unreleased") {
				att_list[12].clear();
			}
		}
		projectList.push_back(Project(att_list[0],materials_list,att_list[2], att_list[3], att_list[4], att_list[5], att_list[6], att_list[7], att_list[8], att_list[9],keywords_list,locations_list, att_list[12]));

	}

	return projectList;
}

//This split function is used to retrieve tokens from a string which contains a set of symbols.
//Essentially the symbols are removed from the string(s) and a vector<string> of tokens is returned for further processing.
vector<std::string> Project::split(std::string str, char splitter)
{
	vector<int> symbol;
	vector<string> tokens;
	for (size_t i = 0; i<str.length(); i++) {
		if (str[i] == splitter) {
			symbol.push_back(i);
		}
	}
	for (size_t i = 0; i<symbol.size() + 1; i++) {
		if (i == 0)
			tokens.push_back(str.substr(0, symbol[i]));
		else if (i == symbol.size()) {
			tokens.push_back(str.substr(symbol[i - 1] + 1));
		}
		else
			tokens.push_back(str.substr(symbol[i - 1] + 1, symbol[i] - symbol[i - 1] - 1));
	}
	return tokens;
}