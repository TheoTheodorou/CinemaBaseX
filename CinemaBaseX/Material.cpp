#include "stdafx.h"
#include "Material.h"
//Default Constructor
Material::Material() {}

//Material Constructor
Material::Material(string input_id, string input_type, string title, string input_format, string input_audio_format, string input_runtime, string input_price, string input_aspect,
vector<string> input_packaging, vector<string> input_language, vector<string> input_subtitles, string input_bonus)
{
	id = input_id;
	type = input_type;
	format = input_format;
	audio_format = input_audio_format;
	runtime = input_runtime;
	price = input_price;
	aspect = input_aspect;
	packagings = input_packaging;
	languages = input_language;
	subtitles = input_subtitles;
	bonus = input_bonus;

}
//This function will read in all the information stored in the materials.txt file. After reading this information in, we send it to the split function which removes
//any symbols we pass through the parameter. It will then return a series of tokens which is stored into a vector<string>. This vector is then added to
//a list of materials which is then returned to the LinkedListMaterials.cpp for further processing.
vector<Material>Material::readMaterials()
{
	vector<Material> materialList;

	ifstream read("materials.txt"); //opens an fstream for file reading
	string fileContents((std::istreambuf_iterator<char>(read)), std::istreambuf_iterator<char>());

	vector<string>material_list = split(fileContents, '@');

	for (int i = 0; i < material_list.size(); i++)
	{
		vector<string> att_list = split(material_list[i], ',');
		vector<string> packaging_list = split(att_list[8], '%');
		vector<string> language_list = split(att_list[9], '%');
		vector<string> subtitle_list = split(att_list[10], '%');
		materialList.push_back(Material(att_list[0], att_list[1], att_list[2], att_list[3], att_list[4], att_list[5], att_list[6], att_list[7], packaging_list, language_list, subtitle_list, att_list[11]));
	}

	return materialList;
}

//This split function is used to retrieve tokens from a string which contains a set of symbols.
//Essentially the symbols are removed from the string(s) and a vector<string> of tokens is returned for further processing.
vector<std::string> Material::split(std::string str, char splitter)
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
