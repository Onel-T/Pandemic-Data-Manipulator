#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// County struct contains county data
struct County{
	string name;
	unsigned cases_per_day[5];
	int highest_cases = -1;
	unsigned total_cases = 0;
};

// Collects data from input file and places into array of County structs
bool collect_data(County counties[], unsigned& total_counties);

// Sets the total cases in a county 
void set_total_cases_per_county(County counties[], unsigned total_counties);

// Sets the highest cases in a county
void set_highest_cases_per_county(County counties[], unsigned total_counties);

// Displays all counties and data in a tabular format
void display_all(County counties[], unsigned total_counties);

// Sorts all the data by county name alphabetical
void sort_by_name(County counties[], unsigned total_counties);

// Removes county by name from array of County structs
void remove_by_name(County counties[], unsigned& total_counties);

// Gets average cases in a single county (analyses of data within one group)
void county_average_cases(County counties[], unsigned total_counties);

// Gets highest cases in one day out of all the counties (analyses of data within multiple groups)
void highest_cases_all_counties(County counties[], unsigned total_counties);

// Filter for showing only counties that have total cases above the given number of total cases
void filter_above_total_cases_amount(County counties[], unsigned total_counties);