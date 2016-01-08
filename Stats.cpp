#include <iostream>
#include <string>
#include <locale>
#include <fstream>
#include <math.h>
#include "Stats.h"

using namespace std;

Stats::Stats() {
}

Stats::~Stats() {
}

//count number of lines in file
void Stats::countLines(std::string fileName) {

	ifstream file;
	file.open(fileName);
	if (!file.is_open()) {
		cout << "file not open" << endl;
		return;
	}	

	string line;
	numLines = 0;

	while(getline(file, line)) {
		++numLines;
	}

	file.close();
}

//add each character in file
void Stats::sumNucleotides(std::string fileName) {

	//open output file
	ofstream output;
	output.open("Results.out", ios::out | ios::app);

	if(output.is_open()) {

		output << "Data for file: " << fileName << endl;
		//open dna file
		ifstream file;
		file.open(fileName);
		if(!file.is_open()) {
			cout << "file not open" << endl;
			return;
		}

		string line;
		sum = 0;

		while(getline(file, line)) {

			for(int i =0; i<line.length(); ++i) {
				++sum;
			}
		}

		output << "The sum of all nucleotides is: " << sum << endl;

		file.close();
		output.close();
	}

}

//take average of number of nucleotides in file using global variables stored from countLines, sumNucleotides
void Stats::meanNucleotides() {

	ofstream output;
	output.open("Results.out", ios::out | ios::app);

	if(output.is_open()) {
		mean = (static_cast<float>(sum))/(static_cast<float>(numLines));

		output << "The mean number of nucleotides in a line is: " << mean << endl;

		output.close();
	}
}

//calc variance
void Stats::varianceNucleotides(std::string fileName) {

	ofstream output;
	output.open("Results.out", ios::out | ios::app);

	if(output.is_open()) {

		ifstream file;
		file.open(fileName);
		if(!file.is_open()) {
			cout << "file not open" << endl;
			return;
		}

		string line;
		//counter variable for taking average at the end of function
		int counter;
		float varianceHolder = 0.0;
		float rawVar;

		while(getline(file, line)) {

			//variable to hold number of char in line - mean (from entire file)
			rawVar = (static_cast<float>(line.length()) - mean);
			//square rawVar
			varianceHolder += (rawVar*rawVar);
			++counter;
			
		}

		variance = varianceHolder/(static_cast<float>(counter));

		file.close();

		output << "The variance of the number of nucleotides per line is: " << variance << endl;

		output.close();
	}
}

//clac standard deviation
void Stats::stdDevNucleotides() {

	ofstream output;
	output.open("Results.out", ios::out | ios::app);

	if(output.is_open()) {

		stdDeviation = sqrt(variance);

		output << "The standard deviation of the number of nucleotides per line is: " << stdDeviation << endl;

		output.close();
	}
}

//calc probability of each single nucleotide (A,T,C,G)
void Stats::probNucleotides(std::string fileName) {

	ofstream output;
	output.open("Results.out", ios::out | ios::app);

	if(output.is_open()) {

		ifstream file;
		file.open(fileName);
		if(!file.is_open()) {
			cout << "file not open" << endl;
			return;
		}

		string line;
		Acount = 0.0;
		Tcount = 0.0;
		Ccount = 0.0;
		Gcount = 0.0;

		//while loop stores each line in the file while the end of the file has yet to be reached
		while(getline(file, line)) {

			//for each character in the line, check which nucleotide it is, add to that nucleotide's counter
			for(int i=0; i<line.length(); ++i) {
				if(line[i] == 'A' || line[i] == 'a'){
					++Acount;
					continue;
				}
				else if(line[i] == 'T' || line[i] == 't'){
					++Tcount;
					continue;
				}
				else if(line[i] == 'C' || line[i] == 'c'){
					++Ccount;
					continue;
				}
				else if(line[i] == 'G' || line[i] == 'g'){
					++Gcount;
					continue;
				}
			}

		}

		file.close();

		//calculate probability of each nucleotide
		probA = Acount/(float)sum;
		probT = Tcount/(float)sum;
		probC = Ccount/(float)sum;
		probG = Gcount/(float)sum;

		//print to output file
		output << "Probability of Nucleotide A: " << probA << endl;
		output << "Probability of Nucleotide T: " << probT << endl;
		output << "Probability of Nucleotide C: " << probC << endl;
		output << "Probability of Nucleotide G: " << probG << endl;

		output.close();
	}
	else {
		cout << "output file not opened." << endl;
	}	

}

//calc probability of each nucleotide bigram
void Stats::probNucleotideBigrams(std::string fileName) {

	ofstream output;
	output.open("Results.out", ios::out | ios::app);

	if(output.is_open()) {

		ifstream file;
		file.open(fileName);
		if(!file.is_open()) {
			cout << "file not open" << endl;
			return;
		}

		string line;
		//set counter variables for each bigram
		AAcount = 0.0;
		ATcount = 0.0;
		ACcount = 0.0;
		AGcount = 0.0;
		TAcount = 0.0; 
		TTcount = 0.0;
		TCcount = 0.0;
		TGcount = 0.0; 
		CAcount = 0.0;
		CTcount = 0.0;
		CGcount = 0.0;
		CCcount = 0.0;
		GAcount = 0.0;
		GTcount = 0.0;
		GGcount = 0.0;
		GCcount = 0.0;

		//while loop stores each line in the file while the end of the file has yet to be reached
		while(getline(file, line)) {

			//for each character in the line (line[i]), check which nucleotide it is
			//depending on if the nuc is A,T,G,C, check what the next character is
			//add to the counter corresponding to line[i] & line[i+1] 
			for(int i=0; i<line.length(); ++i) {
				if (line[i] == 'A' || line[i] == 'a') {
					if (line[i+1] == 'A' || line[i+1] == 'a') {
						++AAcount;
						continue;
					}
					else if (line[i+1] == 'T' || line[i+1] == 't') {
						++ATcount;
						continue;
					}
					else if (line[i+1] == 'C' || line[i+1] == 'c'){
						++ACcount;
						continue;
					}
					else if (line[i+1] == 'G' || line[i+1] == 'g') {
						++AGcount;
						continue;
					}
				}	
				else if (line[i] == 'T' || line[i] == 't') {
					if (line[i+1] == 'A' || line[i+1] == 'a') {
						++TAcount;
						continue;
					}
					else if (line[i+1] == 'T' || line[i+1] == 't') {
						++TTcount;
						continue;
					}
					else if (line[i+1] == 'C' || line[i+1] == 'c') {
						++TCcount;
						continue;
					}
					else if (line[i+1] == 'G' || line[i+1] == 'g') {
						++TGcount;
						continue;
					}
				}
				else if (line[i] == 'C' || line[i] == 'c') {
					if (line[i+1] == 'A' || line[i+1] == 'a') {
						++CAcount;
						continue;
					}
					else if (line[i+1] == 'T' || line[i+1] == 't') {
						++CTcount;
						continue;
					}
					else if (line[i+1] == 'C' || line[i+1] == 'c') {
						++CCcount;
						continue;
					}
					else if (line[i+1] == 'G' || line[i+1] == 'g') {
						++CGcount;
						continue;
					}
				}
				else if (line[i] == 'G' || line[i] == 'g') {
					if (line[i+1] == 'A' || line[i+1] == 'a') {
						++GAcount;
						continue;
					}
					else if (line[i+1] == 'T' || line[i+1] == 't') {
						++GTcount;
						continue;
					}
					else if (line[i+1] == 'C' || line[i+1] == 'c') {
						++GCcount;
						continue;
					}
					else if (line[i+1] == 'G' || line[i+1] == 'g') {
						++GGcount;
						continue;
					}
				} 
			}
		}
		file.close();

		//calculate the probability of each bigram, using stored counter values and global variable sum
		probAA = AAcount/(float)sum;
		probAT = ATcount/(float)sum;
		probAC = ACcount/(float)sum;
		probAG = AGcount/(float)sum;
		probTT = TTcount/(float)sum;
		probTA = TAcount/(float)sum;
		probTC = TCcount/(float)sum;
		probTG = TGcount/(float)sum;
		probCA = CAcount/(float)sum;
		probCT = CTcount/(float)sum;
		probCC = CCcount/(float)sum;
		probCG = CGcount/(float)sum;
		probGA = GAcount/(float)sum;
		probGT = GTcount/(float)sum;
		probGC = GCcount/(float)sum;
		probGG = GGcount/(float)sum;

		//output probabilities of bigrams to .out file
		output << "Probability AA Bigram: " << probAA << endl;
		output << "Probability AT Bigram: " << probAT << endl;
		output << "Probability AC Bigram: " << probAC << endl;
		output << "Probability AG Bigram: " << probAG << endl;
		output << "Probability TA Bigram: " << probTA << endl;
		output << "Probability TT Bigram: " << probTT << endl;
		output << "Probability TC Bigram: " << probTC << endl;
		output << "Probability TG Bigram: " << probTG << endl;
		output << "Probability CA Bigram: " << probCA << endl;
		output << "Probability CT Bigram: " << probCT << endl;
		output << "Probability CC Bigram: " << probCC << endl;
		output << "Probability CG Bigram: " << probCG << endl;
		output << "Probability GA Bigram: " << probGA << endl;
		output << "Probability GT Bigram: " << probGT << endl;
		output << "Probability GC Bigram: " << probGC << endl;
		output << "Probability GG Bigram: " << probGG << endl;

		output.close();
	}	
}

//calc Gaussian distribution and use it to append new DNA lines to output file
void Stats::calcGaussian() {

	ofstream output;
	output.open("Results.out", ios::out | ios::app);

	if(output.is_open()) {

		//display in output file that new DNA strands will follow
		output << " " << endl;
		output << "1000 new DNA strands: " << endl;

		//create 1000 new strands of DNA
		for(int i=0; i<1000; ++i) {

			//create a variable d w/ Gaussian distributino to represent the length of the new DNA strand
			double a = rand() / (RAND_MAX + 1.0);
			double b = rand() / (RAND_MAX + 1.0);
			double c = (sqrt(-2*log(a)))*(cos(2*M_PI*b));
			d = (stdDeviation*c) + mean;
			
			newDNAline = "";
			int DNAlineLength = 0;
			double randProbability;

			if (d < 0) {
				DNAlineLength = d * -1;
			}
			//set the length of the new DNA string to be created =d so that length follows Gauss dist 
			else {
				DNAlineLength = d;
			}

			//while the desired length is greater than the current actual length of new strand, keep adding nucleotides
			while(DNAlineLength > newDNAline.length()) {
				//create a random probability to compare against probability of each nucleotide
				randProbability = rand() / (RAND_MAX + 1.0);
				
				//compare random probability against probabilities of each nucleotide (from probNucleotides())
				if(randProbability > 0 && randProbability < probA) {
					newDNAline += 'A';
					
				}
				else if(randProbability > probA && randProbability < (probA + probT)) {
					newDNAline += 'T';
					
				}
				else if(randProbability > (probA + probT) && randProbability < (probA + probT + probC)) {
					newDNAline += 'C';
					
				}
				else if(randProbability > (probA + probT + probC) && randProbability < (probA + probT + probC + probG)) {
					newDNAline += 'G';
					
				}
			}
			//once the new DNA line has length d, output it to file
			output << newDNAline << endl;
		}	
		output << " " << endl;
		output.close();
	}	

}
