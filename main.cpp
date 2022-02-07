// Using data from Nov 1 - 5
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "library.h" 
using namespace std;

int main() {
	const int ARRAY_CAPACITY = 20;
	County county[ARRAY_CAPACITY];
	unsigned array_companion_size = 0;
	int choice;

	// Calls collect_data and exits program if false (file didn't open)
	if (collect_data(county, array_companion_size) == false){
		return 1;
	}
	
	cout << fixed << showpoint << setprecision(1);

	// User options for data
	do{
		cout << "Please Choose an Option:\n";
		cout << "(1) Display all data\n";
		cout << "(2) Sort data by county name\n";
		cout << "(3) Remove data by county name\n";
		cout << "(4) Find average cases for a county\n";
		cout << "(5) Find county with highest cases in one day\n";
		cout << "(6) Filter to show counties with total cases above a number\n";
		cout << "(7) EXIT PROGRAM\n";
		cout << " Option: ";
		cin >> choice;
		cout << endl;

		// Action based on user chosen option
		switch (choice){
			case 1:
				display_all(county, array_companion_size);
				break;
			case 2:
				sort_by_name(county, array_companion_size);
				display_all(county, array_companion_size);
				break;
			case 3:
				remove_by_name(county, array_companion_size);
				break;
			case 4:
				county_average_cases(county, array_companion_size);
				break;
			case 5:
				highest_cases_all_counties(county, array_companion_size);
				break;
			case 6:
				filter_above_total_cases_amount(county, array_companion_size);
				break;
		}
	} while(choice != 7);
	cout << "** Thank you! **\n";
} 