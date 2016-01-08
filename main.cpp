#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <math.h>
#include "stats.h"

using namespace std;

int main() {

	Stats* obj = new Stats();

	//prompt user for file name to read DNA from
	cout << "Type a file name: (included files called dna.txt, newDNA.txt)" << endl;

	string fileName;

	getline(cin, fileName);

	//test to make sure file has opened. If not, re-enter file name.
	ifstream file;
	file.open(fileName);
	if (!file.is_open()) {
		cout << "Error opening file." << endl;
		cout << "Re-type file name: " << endl;
		getline(cin, fileName);
	}
	else {
		file.close();
	}

	//call statistics methods for file that user entered the name of
	obj->countLines(fileName);

	obj->sumNucleotides(fileName);

	obj->meanNucleotides();

	obj->varianceNucleotides(fileName);

	obj->stdDevNucleotides();

	obj->probNucleotides(fileName);

	obj->probNucleotideBigrams(fileName);

	obj->calcGaussian();

	//Ask user if they want to calculate stats for another DNA file
	cout << "File processed. Process another list? Type yes to proceed, no to exit. " << endl;

	string decision;

	getline(cin, decision);

	//make sure user actually typed yes or no, if not, get new decision
	if(!(decision == "yes" || decision == "no")) {
		cout << "Please type yes or no." << endl;
		cout << "Process another list? " << endl;
		getline(cin, decision);
	}

	//if user wants to process a new file, take a new file name
	if(decision == "yes") {

		cout << "Type a new file name: " << endl;

		getline(cin, fileName);

		Stats* newObj = new Stats();

		obj->sumNucleotides(fileName);
		obj->meanNucleotides();
		obj->varianceNucleotides(fileName);
		obj->stdDevNucleotides();
		obj->probNucleotides(fileName);
		obj->probNucleotideBigrams(fileName);
		obj->calcGaussian();

		cout << "File processed. Thank you." << endl;
	}
	//if user doesnt want to process a new file, exit program
	else if(decision == "no") {

		cout << "Thank you." << endl;
		exit(0);
	}


	return 0;
}
