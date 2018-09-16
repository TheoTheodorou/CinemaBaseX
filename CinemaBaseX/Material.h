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

class Material
{
public:
	//Material Variables
	string id,type, title, format, audio_format, runtime, price, aspect, bonus;
	vector<string> packagings, languages, subtitles;

	//Default Constructor
	Material();

	//Constructor
	Material(string input_id, string input_type, string title, string input_format, string input_audio_format, string input_runtime, string input_price, string input_aspect,
		vector<string> input_packaging, vector<string> input_language, vector<string> input_subtitles, string input_bonus);

	//Member Declarations
	static vector<Material> readMaterials();
private:
	static vector<std::string>split(std::string str, char splitter);
};

