#include "stdafx.h"
#include "System.h";


//Constructor
System::System()
{
}

//Runs the CinemaBaseX System
bool System::Run() {
	//Loads the linked lists and gets the head nodes
	projectHead = ProjectList.loadList();
	materialHead = MaterialList.loadList();
	crewHead = CrewList.loadList();




	//Display Main Screen
	cout << "-------------Cinema Base X-------------" << endl;
	cout << "---------By Trek Star Pictures---------\n" << endl;
	cout << "To enter the program type 'enter', to close the program at any time type 'exit'" << endl;

	string title_input;
	string menu_input = "";
	string search_item = "";
	bool system_repeat = true;

	while (system_repeat) {
		//runs main user interface via cmd
		getline(cin, title_input);


		if (title_input == "enter") {
			cout << "Entered the program" << endl;

			bool repeat = true;

			while (repeat) {
				cout << "\nPlease input: |1| view projects |2| add project |3| delete project |4| edit project |5| modify materials |6| modify crew |7| sort projects |exit| to exit" << endl;

				getline(cin, menu_input);

				cout << "\n---------------------------------------\n";

				if (menu_input == "1")
				{
					ProjectList.printLinkedList(projectHead);
				}

				else if (menu_input == "2")
				{
					Project project = addProject(projectHead);
					ProjectList.append(projectHead, project);
				}

				else if (menu_input == "3")
				{
					cout << "Enter the name of the project you want to delete: ";
					while (true) {
						getline(cin, search_item);
						if (!search_item.empty())
							break;
					}
					LinkedListProject::node* nodeD = ProjectList.searchListbyTitle(search_item, projectHead);

					if (nodeD == NULL)
					{
						cout << "Project Not Found" << endl;
					}

					else
					{
						ProjectList.deleteNode(nodeD, projectHead);
						cout << "Deleted" << search_item << "from list of projects" << endl;
					}

				}

				else if (menu_input == "4")
				{
					editProject();
				}

				else if (menu_input == "5")
				{
					modifyMaterials();
				}

				else if (menu_input == "6")
				{
					modifyCrew();
				}

				else if (menu_input == "7")
				{
					ProjectList.sort(projectHead);
				}



				else if (menu_input == "exit")
				{
					repeat = false;
					system_repeat = false;
				}

				else
				{
					cout << "Invalid input" << endl;
				}

			}
		}


		else if (title_input == "exit") {
			cout << "Exit the program" << endl;
			system_repeat = false;
		}

		else
			cout << "Input invalid" << endl;
	}

	Shutdown();
	return false;


}
//cycles a shutdown and writes all the volatile data to file
void System::Shutdown() {
	cout << "Shutting Down..." << endl;
	cout << "3" << endl;
	cout << "2" << endl;
	cout << "1" << endl;
	cout << "Press any key to exit";

	ProjectList.writeList("projectstmp.txt", projectHead);
	remove("projects.txt");
	rename("projectstmp.txt", "projects.txt");

	MaterialList.writeList("materialstmp.txt", materialHead);
	remove("materials.txt");
	rename("materialstmp.txt", "materials.txt");

	CrewList.writeList("crewstmp.txt", crewHead);
	remove("crews.txt");
	rename("crewstmp.txt", "crews.txt");

}
//adds a brand new project to the system based off the user input. Appropriately validated 
Project System::addProject(LinkedListProject::node* head)
{
	Project project;

	string id, crew, title, summary, genre, year, language, runtime, status, sales;
	vector<string> materials, keywords, locations;
	bool isEmpty = true;
	bool looping = true;
	cout << "Please enter the project details: " << endl;

		cout << "ID: ";
		while (true) {
			getline(cin, id);
			LinkedListProject::node* nodeI = ProjectList.searchListbyID(id, projectHead);

			if (!id.empty())
				if (nodeI == NULL) {
					break;
				}
				else
					cout << "ID taken by other project" << endl;
		}
	

	cout << "\nMaterial ID/s: " << endl;
	while (looping)
	{
		cout << "Enter a material ID, to stop entering ID's type 'done': ";
		string material_input = "";

		while (true) {
			getline(cin, material_input);
			if (!material_input.empty())
				break;
		}

		if (material_input != "done") {
			materials.push_back(material_input + "%");
			isEmpty = false;
		}

		else if (material_input == "done" && isEmpty == false)
			looping = false;

		else
			cout << "Invalid input" << endl;
	}

	cout << "\nCrew ID: ";
	while (true) {
		getline(cin, crew);
		if (!crew.empty())
			break;
	}

	cout << "\nTitle: ";
	while (true) {
		getline(cin, title);
		if (!title.empty())
			break;
	}

	cout << "\nSummary: ";
	while (true) {
		getline(cin, summary);
		if (!summary.empty())
			break;
	}

	cout << "\nGenre: ";
	while (true) {
		getline(cin, genre);
		if (!genre.empty())
			break;
	}

	cout << "\nYear: ";
	while (true) {
		getline(cin, year);
		if (!year.empty())
			break;
	}

	cout << "\nLanguage: ";
	while (true) {
		getline(cin, language);
		if (!language.empty())
			break;
	}

	cout << "\nRun Time (mins): ";
	while (true) {
		getline(cin, runtime);
		if (!runtime.empty())
			break;
	}
	runtime = runtime + " mins";

	cout << "\nStatus('unreleased'/'now playing'/'released') : ";
	while (true) {
		getline(cin, status);
		if (!status.empty())
			break;
	}

	isEmpty = true;
	looping = true;
	cout << "\nKeyword/s: " << endl;
	while (looping)
	{
		cout << "Enter a keyword, to stop entering keyword's type 'done': ";
		string keyword_input = "";
		while (true) {
			getline(cin, keyword_input);
			if (!keyword_input.empty())
				break;
		}

		if (keyword_input != "done")
		{
			keywords.push_back(keyword_input + "%");
			isEmpty = false;
		}

		else if (keyword_input == "done" && isEmpty == false)
			looping = false;

		else
			cout << "Invalid input";
	}

	isEmpty = true;
	looping = true;
	cout << "\nLocation/s: " << endl;
	while (looping)
	{
		cout << "Enter a location, to stop entering location's type 'done': ";
		string location_input = "";
		while (true) {
			getline(cin, location_input);
			if (!location_input.empty())
				break;
		}

		if (location_input != "done")
		{
			locations.push_back(location_input + "%");
			isEmpty = false;
		}

		else if (location_input == "done" && isEmpty == false)
		{
			looping = false;
		}

		else
			cout << "Invalid input";


	}

	cout << "\nWeekly sales: ";
	while (true) {
		getline(cin, sales);
		if (!sales.empty())
			break;
	}

	if (status == "unreleased" || status == "now playing")
	{
		materials.clear();
		if (status == "unreleased")
		{
			sales.clear();
		}
	}

	project.film_id = id;
	project.material_ids = materials;
	project.crew_id = crew;
	project.title = title;
	project.summary = summary;
	project.genre = genre;
	project.releaseDate = year;
	project.language = language;
	project.runtime = runtime;
	project.status = status;
	project.keywords = keywords;
	project.filmLocations = locations;
	project.weeklySale = sales;

	return project;

}
//Edits an existing project on file based off user input
void System::editProject()
{
	string search_item = "";
	cout << "Enter the name of the project you want to edit: ";
	while (true) {
		getline(cin, search_item);
		if (!search_item.empty())
			break;
	}
	LinkedListProject::node* nodeE = ProjectList.searchListbyTitle(search_item, projectHead);

	if (nodeE == NULL)
	{
		cout << "Project Not Found" << endl;
	}

	else
	{
		string attribute = "";
		string newAttribute = "";
		bool isEmpty = true;
		bool looping = true;
		cout << "Please choose the attribute to edit: ";
		cout << "'ID' 'materials' 'crew' 'title' 'summary' 'genre' 'year' 'language' 'runtime' 'status' 'keywords' 'locations' 'sales'";
		while (true) {
			getline(cin, attribute);
			if (!attribute.empty())
				break;
		}

		if (attribute == "ID")
		{
			cout << "Please enter a new ID for" << search_item;
			while (true) {
				getline(cin, newAttribute);
				LinkedListProject::node* nodeI = ProjectList.searchListbyID(newAttribute, projectHead);

				if (!newAttribute.empty())
					if (nodeI == NULL) {
						break;
					}
					else
						cout << "ID taken by other project" << endl;
			}
			nodeE->data.film_id = newAttribute;
		}

		else if (attribute == "materials")
		{
			vector<string> newMaterials;
			while (looping) {
				cout << "Please enter a new material for" << search_item << ", type 'done' when finished";
				while (true) {
					getline(cin, newAttribute);
					if (!newAttribute.empty())
						break;
				}

				if (newAttribute != "done") {
					newMaterials.push_back(newAttribute + "%");
					isEmpty = false;
				}
				else if (newAttribute == "done" && isEmpty == false)
					looping = false;
				else
					cout << "Invalid input";


			}
			nodeE->data.material_ids = newMaterials;
		}
		else if (attribute == "crew")
		{
			cout << "Please enter a new crew for" << search_item;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.crew_id = newAttribute;
		}
		else if (attribute == "title")
		{
			cout << "Please enter a new title for" << search_item;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.title = newAttribute;
		}
		else if (attribute == "summary")
		{
			cout << "Please enter a new summary for" << search_item;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.summary = newAttribute;
		}
		else if (attribute == "genre")
		{
			cout << "Please enter a new genre for" << search_item;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.genre = newAttribute;
		}
		else if (attribute == "year")
		{
			cout << "Please enter a new year for" << search_item;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.releaseDate = newAttribute;
		}
		else if (attribute == "language")
		{
			cout << "Please enter a new language for" << search_item;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.language = newAttribute;
		}
		else if (attribute == "runtime")
		{
			cout << "Please enter a new runtime for" << search_item << "(mins)";
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.runtime = newAttribute + "mins";
		}
		else if (attribute == "status('unreleased'/'now playing'/'released')")
		{
			cout << "Please enter a new status for" << search_item;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.status = newAttribute;
		}
		else if (attribute == "keywords")
		{
			isEmpty = true;
			looping = true;
			vector<string> newKeywords;
			while (looping) {
				cout << "Please enter a new keyword for" << search_item << ", type 'done' when finished";
				while (true) {
					getline(cin, newAttribute);
					if (!newAttribute.empty())
						break;
				}
				if (newAttribute != "done") {
					newKeywords.push_back(newAttribute + "%");
					isEmpty = false;
				}
				else if (newAttribute == "done" && isEmpty == false)
					looping = false;
				else
					cout << "Invalid input";

			}
			nodeE->data.keywords = newKeywords;
		}
		else if (attribute == "locations")
		{
			isEmpty = true;
			looping = true;
			vector<string> newLocations;
			while (looping) {
				cout << "Please enter new location for" << search_item << ", type 'done' when finished";
				while (true) {
					getline(cin, newAttribute);
					if (!newAttribute.empty())
						break;
				}
				if (newAttribute != "done") {
					newLocations.push_back(newAttribute + "%");
					isEmpty = false;
				}
				else if (newAttribute == "done" && isEmpty == false)
					looping = false;
				else
					cout << "Invalid input" << endl;
			}
			nodeE->data.filmLocations = newLocations;
		}
		else if (attribute == "sales")
		{
			cout << "Please enter a new sales for" << search_item;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.weeklySale = newAttribute;
		}

		else
		{
			cout << "Invalid input" << endl;
		}



	}
}
//Runs the user interface to modify the information for materials
void System::modifyMaterials()
{
	string material_input = "";
	string search_id = "";
	bool material_repeat = true;

	while (material_repeat) {
		cout << "\nPlease input: |1| View materials |2| Add material |3| Delete material |4| Edit materials" << endl;
		while (true) {
			getline(cin, material_input);
			if (!material_input.empty())
				break;
		}
		cout << "\n---------------------------------------\n";

		if (material_input == "1")
		{
			MaterialList.printLinkedList(materialHead);
		}

		else if (material_input == "2")
		{
			Material material = addMaterial();
			MaterialList.append(materialHead, material);
		}

		else if (material_input == "3")
		{
			cout << "Enter the id of the material you want to delete: ";
			while (true) {
				getline(cin, search_id);
				if (!search_id.empty())
					break;
			}
			LinkedListMaterials::node* nodeD = MaterialList.searchList(search_id, materialHead);

			if (nodeD == NULL)
			{
				cout << "Material Not Found" << endl;
			}

			else
			{
				MaterialList.deleteNode(nodeD, materialHead);
				cout << "Deleted" << search_id << "from list of materials" << endl;
			}

		}

		else if (material_input == "4")
		{
			editMaterial();
		}



		else if (material_input == "exit")
		{
			material_repeat = false;
		}

		else
		{
			cout << "Invalid input" << endl;
		}

	}
}
//adds a brand new material to the system based off the user input. Appropriately validated 
Material System::addMaterial()
{
	Material material;

	string id, type, title, format, audio_format, runtime, price, aspect, bonus;
	vector<string> packagings, languages, subtitles;
	bool isEmpty = true;
	bool looping = true;
	cout << "Please enter the material details: " << endl;

	cout << "ID: ";
	while (true) {
		getline(cin, id);
		LinkedListMaterials::node* nodeI = MaterialList.searchListbyID(id, materialHead);

		if (!id.empty())
			if (nodeI == NULL) {
				break;
			}
			else
				cout << "ID taken by other project" << endl;
	}

	cout << "\nType ('single side'/'double side'/'box set'/'vhs'/'blu ray' ";
	while (true) {
		getline(cin, type);
		if (!type.empty())
			break;
	}

	cout << "\nTitle: ";
	while (true) {
		getline(cin, title);
		if (!title.empty())
			break;
	}

	cout << "\nFormat: ";
	while (true) {
		getline(cin, format);
		if (!format.empty())
			break;
	}

	cout << "\nAudio format: ";
	while (true) {
		getline(cin, audio_format);
		if (!audio_format.empty())
			break;
	}

	cout << "\nRuntime (mins): ";
	while (true) {
		getline(cin, runtime);
		if (!runtime.empty())
			break;
	}

	cout << "\nPrice: ";
	while (true) {
		getline(cin, price);
		if (!price.empty())
			break;
	}

	cout << "\nAspect ratio: ";
	while (true) {
		getline(cin, aspect);
		if (!aspect.empty())
			break;
	}

	cout << "\nBonus: ";
	while (true) {
		getline(cin, bonus);
		if (!bonus.empty())
			break;
	}


	cout << "\nTypes of packaging: " << endl;
	while (looping)
	{
		cout << "Enter a packaging, to stop entering packagings type 'done': ";
		string packaging_input = "";
		while (true) {
			getline(cin, packaging_input);
			if (!packaging_input.empty())
				break;
		}

		if (packaging_input != "done")
		{
			packagings.push_back(packaging_input + "%");
			isEmpty = false;
		}

		else if (packaging_input == "done" && isEmpty == false)
			looping = false;
		else
			cout << "Invalid input" << endl;

	}

	isEmpty = true;
	looping = true;
	cout << "\nLanguage/s: " << endl;
	while (looping)
	{
		cout << "Enter a language, to stop entering language's type 'done': ";
		string language_input = "";
		while (true) {
			getline(cin, language_input);
			if (!language_input.empty())
				break;
		}

		if (language_input != "done")
		{
			languages.push_back(language_input + "%");
			isEmpty = false;
		}

		else if (language_input == "done" && isEmpty == false)
			looping = false;
		else
			cout << "Invalid input" << endl;
	}

	isEmpty = true;
	looping = true;
	cout << "\nSubtitles/s: " << endl;
	while (looping)
	{
		cout << "Enter a subtitle, to stop entering subtitle's type 'done': ";
		string subtitles_input = "";
		while (true) {
			getline(cin, subtitles_input);
			if (!subtitles_input.empty())
				break;
		}

		if (subtitles_input != "done")
		{
			subtitles.push_back(subtitles_input + "%");
			isEmpty = false;
		}
		else if (subtitles_input == "done" && isEmpty == false)
			looping = false;
		else
			cout << "Invalid Input" << endl;
	}

	material.id = id;
	material.type = type;
	material.title = title;
	material.format = format;
	material.audio_format = audio_format;
	material.runtime = runtime;
	material.price = price;
	material.aspect = aspect;
	material.bonus = bonus;
	material.packagings = packagings;
	material.languages = languages;
	material.subtitles = subtitles;

	return material;

}
//Edits an existing material on file based off user input
void System::editMaterial()
{
	string search_id = "";
	cout << "Enter the id of the material you want to edit: ";
	while (true) {
		getline(cin, search_id);
		if (!search_id.empty())
			break;
	}
	LinkedListMaterials::node* nodeE = MaterialList.searchList(search_id, materialHead);

	if (nodeE == NULL)
	{
		cout << "Material Not Found" << endl;
	}

	else
	{
		string attribute = "";
		string newAttribute = "";
		bool isEmpty = true;
		bool looping = true;
		cout << "Please choose the attribute to edit: ";
		cout << "'ID' 'type' 'title' 'format' 'audio_format' 'runtime' 'price' 'aspect' 'bonus' 'packagings' 'languages' 'subtitles'";
		while (true) {
			getline(cin, attribute);
			if (!attribute.empty())
				break;
		}

		if (attribute == "ID")
		{
			cout << "Please enter a new ID for" << search_id;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.id = newAttribute;
		}

		else if (attribute == "type")
		{
			cout << "Please enter a new type for" << search_id << " ('single side'/'double side'/'box set'/'vhs'/'blu ray')";
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}

			nodeE->data.type = newAttribute;
		}
		else if (attribute == "title")
		{
			cout << "Please enter a new title for" << search_id;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.title = newAttribute;
		}
		else if (attribute == "format")
		{
			cout << "Please enter a new format for" << search_id;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.format = newAttribute;
		}
		else if (attribute == "audio_format")
		{
			cout << "Please enter a new audio_format for" << search_id;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.audio_format = newAttribute;
		}
		else if (attribute == "runtime")
		{
			cout << "Please enter a new runtime for" << search_id;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.runtime = newAttribute;
		}
		else if (attribute == "price")
		{
			cout << "Please enter a new price for" << search_id;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.price = newAttribute;
		}
		else if (attribute == "aspect")
		{
			cout << "Please enter a new aspect for" << search_id;
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.aspect = newAttribute;
		}
		else if (attribute == "bonus")
		{
			cout << "Please enter a new bonus for" << search_id << "(mins)";
			while (true) {
				getline(cin, newAttribute);
				if (!newAttribute.empty())
					break;
			}
			nodeE->data.bonus = newAttribute + "mins";
		}
		else if (attribute == "packagings('plastic box'/'cardboard box')")
		{
			vector<string> newPackagings;
			while (looping) {
				cout << "Please enter a new packagings for" << search_id << ", type 'done' when finished";
				while (true) {
					getline(cin, newAttribute);
					if (!newAttribute.empty())
						break;
				}
				if (newAttribute != "done") {
					newPackagings.push_back(newAttribute + "%");
					isEmpty = false;
				}
				else if (newAttribute == "done" && isEmpty == false)
					looping = false;
				else
					cout << "Invalid input" << endl;
			}
			nodeE->data.packagings = newPackagings;
		}
		else if (attribute == "languages")
		{
			isEmpty = true;
			looping = true;
			vector<string> newLanguages;
			while (looping) {
				cout << "Please enter new languages for" << search_id << ", type 'done' when finished";
				while (true) {
					getline(cin, newAttribute);
					if (!newAttribute.empty())
						break;
				}
				if (newAttribute != "done") {
					newLanguages.push_back(newAttribute + "%");
					isEmpty = false;
				}
				else if (newAttribute == "done" && isEmpty == false)
					looping = false;
				else
					cout << "Invalid input" << endl;
			}
			nodeE->data.languages = newLanguages;
		}
		else if (attribute == "subtitles")
		{
			isEmpty = true;
			looping = true;
			vector<string> newSubtitles;
			while (looping) {
				cout << "Please enter new subtitles for" << search_id << ", type 'done' when finished";
				while (true) {
					getline(cin, newAttribute);
					if (!newAttribute.empty())
						break;
				}
				if (newAttribute != "done") {
					newSubtitles.push_back(newAttribute + "%");
					isEmpty = false;
				}
				else if (newAttribute == "done" && isEmpty == false)
					looping = false;
				else
					cout << "Invalid input" << endl;
			}
			nodeE->data.subtitles = newSubtitles;
		}

		else
		{
			cout << "Invalid input" << endl;
		}

	}
}
//Runs the user interface to modify the information for a crew
void System::modifyCrew() {
	string crew_input = "";
	string search_producer = "";
	bool crew_repeat = true;

	while (crew_repeat) {
		cout << "\nPlease input: |1| View Crew |2| Add Crew |3| Delete Crew |4| Edit Crew" << endl;
		while (true) {
			getline(cin, crew_input);
			if (!crew_input.empty())
				break;
		}
		cout << "\n---------------------------------------\n";

		if (crew_input == "1")
		{
			CrewList.printLinkedList(crewHead);
		}

		else if (crew_input == "2")
		{
			Crew crew = addCrew();
			CrewList.append(crewHead, crew);
		}

		else if (crew_input == "3")
		{
			cout << "Enter the name of the producer you want to delete: ";
			while (true) {
				getline(cin, search_producer);
				if (!search_producer.empty())
					break;
			}
			LinkedListCrew::node* nodeD = CrewList.searchList(search_producer, crewHead);

			if (nodeD == NULL)
			{
				cout << "Crew Not Found" << endl;
			}

			else
			{
				CrewList.deleteNode(nodeD, crewHead);
				cout << "Deleted" << search_producer << "from list of materials" << endl;
			}

		}

		else if (crew_input == "4")
		{
			editCrew();
		}



		else if (crew_input == "exit")
		{
			crew_repeat = false;
		}

		else
		{
			cout << "Invalid input" << endl;
		}

	}

}
//add a brand new crewt to the system based off the user input. Appropriately validated
Crew System::addCrew() {
	Crew crew;

	string producer, director, writer, editor, production_designer, set_decorator, costume_designer;
	vector<string> cast;
	bool isEmpty = true;
	bool looping = true;

	cout << "Please enter the crew details: " << endl;

	cout << "Producer: ";
	while (true) {
		getline(cin, producer);
		if (!producer.empty())
			break;
	}

	cout << "\ndirector ";
	while (true) {
		getline(cin, director);
		if (!director.empty())
			break;
	}

	cout << "\nwriter: ";
	while (true) {
		getline(cin, writer);
		if (!writer.empty())
			break;
	}

	cout << "\neditor: ";
	while (true) {
		getline(cin, editor);
		if (!editor.empty())
			break;
	}

	cout << "\nproduction_designer: ";
	while (true) {
		getline(cin, production_designer);
		if (!production_designer.empty())
			break;
	}

	cout << "\nset_decorator : ";
	while (true) {
		getline(cin, set_decorator);
		if (!set_decorator.empty())
			break;
	}

	cout << "\ncostume_designer: ";
	while (true) {
		getline(cin, costume_designer);
		if (!costume_designer.empty())
			break;
	}


	cout << "\nCast members: " << endl;
	while (looping)
	{
		cout << "Enter a cast member, to stop entering cast members type 'done': ";
		string cast_input = "";
		while (true) {
			getline(cin, cast_input);
			if (!cast_input.empty())
				break;
		}

		if (cast_input != "done")
		{
			cast.push_back(cast_input + "%");
			isEmpty = false;
		}

		else if (cast_input == "done"&&isEmpty == false)
			looping = false;
		else
			cout << "Invalid Input" << endl;
	}

	crew.producer = producer;
	crew.director = director;
	crew.writer = writer;
	crew.editor = editor;
	crew.production_designer = production_designer;
	crew.set_decorator = set_decorator;
	crew.costume_designer = costume_designer;
	crew.cast = cast;

	return crew;


}
//Edits an existing crew on file based off user input
void System::editCrew() {
	string search_producer = "";
	cout << "Enter the producer of the crew you want to edit: ";
	while (true) {
		getline(cin, search_producer);
		if (!search_producer.empty())
			break;
	}
	LinkedListCrew::node* nodeE = CrewList.searchList(search_producer, crewHead);

	if (nodeE == NULL)
	{
		cout << "Crew Not Found" << endl;
	}

	else
	{
		string attribute = "";
		string newAttribute = "";
		bool isEmpty = true;
		bool looping = true;
		cout << "Please choose the attribute to edit: ";
		cout << "'Producer' 'Director' 'Writer' 'Editor' 'Production Designer' 'Set Decorator' 'Costume Designer' 'Cast''";
		while (true) {
			getline(cin, attribute);
			if (!attribute.empty())
				break;
		}

		if (attribute == "Producer")
		{
			cout << "Please enter a new Producer for" << search_producer;
			while (true) {
				getline(cin, newAttribute);
				if (newAttribute.empty())
					break;
			}
			nodeE->data.producer = newAttribute;
		}

		else if (attribute == "Director")
		{
			cout << "Please enter a new Director for" << search_producer;
			while (true) {
				getline(cin, newAttribute);
				if (newAttribute.empty())
					break;
			}

			nodeE->data.director = newAttribute;
		}
		else if (attribute == "Writer")
		{
			cout << "Please enter a new Writer for" << search_producer;
			while (true) {
				getline(cin, newAttribute);
				if (newAttribute.empty())
					break;
			}
			nodeE->data.writer = newAttribute;
		}
		else if (attribute == "Editor")
		{
			cout << "Please enter a Editor for" << search_producer;
			while (true) {
				getline(cin, newAttribute);
				if (newAttribute.empty())
					break;
			}
			nodeE->data.editor = newAttribute;
		}
		else if (attribute == "Production Designer")
		{
			cout << "Please enter a new Production Designer for" << search_producer;
			while (true) {
				getline(cin, newAttribute);
				if (newAttribute.empty())
					break;
			}
			nodeE->data.production_designer = newAttribute;
		}
		else if (attribute == "Set Decorator")
		{
			cout << "Please enter a new Set Director for" << search_producer;
			while (true) {
				getline(cin, newAttribute);
				if (newAttribute.empty())
					break;
			}
			nodeE->data.set_decorator = newAttribute;
		}
		else if (attribute == "Costume Designer")
		{
			cout << "Please enter a Costume Designer for" << search_producer;
			while (true) {
				getline(cin, newAttribute);
				if (newAttribute.empty())
					break;
			}
			nodeE->data.costume_designer = newAttribute;
		}
		else if (attribute == "Cast")
		{
			vector<string> newCastMembers;
			while (looping) {
				cout << "Please enter a new cast member for" << search_producer << ", type 'done' when finished";
				while (true) {
					getline(cin, newAttribute);
					if (newAttribute.empty())
						break;
				}
				while (true) {
					getline(cin, newAttribute);
					if (newAttribute.empty())
						break;
				}
				if (newAttribute != "done") {
					newCastMembers.push_back(newAttribute + "%");
					isEmpty = false;
				}
				else if (newAttribute == "done" && isEmpty == false)
					looping = false;
				else
					cout << "Invalid input" << endl;
			}
			nodeE->data.cast = newCastMembers;
		}
		else
		{
			cout << "Invalid input" << endl;
		}

	}
}