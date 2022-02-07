#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "library.h" 
using namespace std;

// Collects data into array of structs
bool collect_data(County counties[], unsigned& total_counties){
	string credit;
	ifstream input_file;
	input_file.open("input.dat");
	// Check if file opens or not
	if (input_file.is_open() == false){
		cout << "*File not open*\n\n";
		return false;
	}
	else{
		cout << "*File Successfully Opened*\n\n";
	}
	
	getline(input_file, credit, '\n');
	// Collects data for for each county
	for (int i = 0; i < 10; i++){
		getline(input_file, counties[i].name, '\n');
		// Collects the cases for the current county
		for (int j = 0; j < 5; j++){
			input_file >> counties[i].cases_per_day[j];
		}
		input_file.ignore();
		total_counties++;
	}

	// Sets other data points in struct
	set_total_cases_per_county(counties, total_counties);
	set_highest_cases_per_county(counties, total_counties);

	input_file.close();
	return true;
}

// Sets the total cases per county
void set_total_cases_per_county(County counties[], unsigned total_counties){
		// Gets total cases per county
	for (int i = 0; i < total_counties; i++){
		// Adding up total number of cases for the county
		for (int j = 0; j < 5; j++){
			counties[i].total_cases += counties[i].cases_per_day[j];
		}
	}
}

// Sets the highest cases per county
void set_highest_cases_per_county(County counties[], unsigned total_counties){
	// Gets highest cases per county
	for (int i = 0; i < total_counties; i++){
		// Loop to find highest cases in a county
		for (int j = 0; j < 5; j++){
			// Checks highest cases for county
			if (counties[i].cases_per_day[j] > counties[i].highest_cases || counties[i].highest_cases == -1){
				counties[i].highest_cases = counties[i].cases_per_day[j];
			}
		}
	}
}

// Displays all data in tabular format
void display_all(County counties[], unsigned total_counties){
	cout << " County" << setw(45) << "New Cases (For 5 days, Nov 1 - 5)\n";
	cout << "====================================================\n";
	for (int i = 0; i < total_counties; i++){
		cout << left;
		cout << setw(15) << counties[i].name;
		cout << right;
		for (int j = 0; j < 5; j++){
			cout << setw(7) << counties[i].cases_per_day[j];
		}
		cout << "\n";
	}
	cout << "====================================================\n\n";
}

// Sorts countys by name using insertion sort
void sort_by_name(County counties[], unsigned total_counties){
	// Insertion sort by county name alphabetical
	for (int i = 1; i < total_counties; i++){
		for (int j = i; j > 0 && counties[j - 1].name > counties[j].name; j--){
			swap(counties[j - 1], counties[j]);
		}
	}
	cout << "--Data sorted by county name--\n\n";
}

// Removes a county by name from the array
void remove_by_name(County counties[], unsigned& total_counties){
	int index = 0;
	
	string county_name;
	cout << "Input county you want removed: ";
	cin.ignore();
	getline(cin, county_name);

	// Searches for a county name match
	while (index < total_counties && counties[index].name != county_name){
		index++;
	} // end of searching for the match

	// If match found
	if (index != (total_counties)){
		// Shifts elements based on match
		for (int i = index; i < total_counties; i++) {
			counties[i] = counties[i+ 1];
		} // end of shifting elements forward
		total_counties--;
		cout << "--" << county_name << " County has been removed--\n\n";
		display_all(counties, total_counties);
	}
	else{
		cout << "--" << county_name << " County NOT FOUND--\n\n";
	}
}

// Finds average cases for one county (analyses using one struct object)
void county_average_cases(County counties[], unsigned total_counties){
	int index = 0;
	double average_cases = 0.0;
	string county_name;
	
	cout << "Input county to find average cases: ";
	cin.ignore();
	getline(cin, county_name);

	// Searches for a county name match
	while (index < total_counties && counties[index].name != county_name){
		index++;
	} // end of searching for the match

	// If match found
	if (index != total_counties){
		average_cases = counties[index].total_cases / 5.0;
		cout << "** " << county_name << " has an average of " << average_cases << " cases per day **\n\n";
	}
	else{
		cout << "--" << county_name << " County NOT FOUND--\n\n";
	}
}

// Finds which county has the highest cases out of all counties (analyses using multiple struct objects)
void highest_cases_all_counties(County counties[], unsigned total_counties){
	int index = 0;
	int current_highest_in_one_day = -1;
	for (int i = 0; i < total_counties; i++){
		if (counties[i].highest_cases > current_highest_in_one_day){
			index = i;
			current_highest_in_one_day = counties[i].highest_cases;
		}
	}

	cout << "** " << counties[index].name << " County currently has the highest cases in one day with " << counties[index].highest_cases << " cases **\n\n";
}

// Filters for above a total number of cases and displays filtered counties with total
void filter_above_total_cases_amount(County counties[], unsigned total_counties){
	int total_cases_filter;
	
	cout << "Input number of total cases to filter above: ";
	cin >> total_cases_filter;
	cout << "** Showing counties with above " << total_cases_filter << " total cases **\n";
	
	cout << "\n County" << setw(44) << "New Cases (For 5 days, Nov 1 - 5)" << setw(9) << "Total\n";
	cout << "=============================================================\n";
	
	for (int i = 0; i < total_counties; i++){
		if (counties[i].total_cases > total_cases_filter){
			cout << left;
			cout << setw(15) << counties[i].name;
			cout << right;

			for (int j = 0; j < 5; j++){
				cout << setw(7) << counties[i].cases_per_day[j];
			}
			cout << setw(9) << counties[i].total_cases;
			cout << "\n";
		}
	}
	cout << "=============================================================\n\n";
}