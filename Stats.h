#ifndef STATS_H_
#define STATS_H_

using namespace std;

class Stats{
public:

	Stats();
	~Stats();

	//make global variables that can be stored by certain methods to be used in later methods
	float Acount;
	float Tcount;
	float Ccount;
	float Gcount;

	float probA;
	float probT;
	float probC;
	float probG;

	float AAcount;
	float ATcount;
	float ACcount;
	float AGcount;
	float TAcount; 
	float TTcount;
	float TCcount;
	float TGcount;
	float CAcount;
	float CTcount;
	float CGcount;
	float CCcount;
	float GAcount;
	float GTcount;
	float GGcount;
	float GCcount;

	float probAA;
	float probAT;
	float probAC;
	float probAG;
	float probTA;
	float probTT;
	float probTC;
	float probTG;
	float probCA;
	float probCT;
	float probCC;
	float probCG;
	float probGA;
	float probGT;
	float probGC;
	float probGG;

	int numLines;
	int sum;
	float mean;
	float variance;
	string fileName;
	float stdDeviation;
	float d;

	string newDNAline;

	void countLines(string fileName);
	void sumNucleotides(string fileName);
	void meanNucleotides();
	void varianceNucleotides(string fileName);
	void stdDevNucleotides();
	void probNucleotides(string fileName);
	void probNucleotideBigrams(string fileName);
	void calcGaussian();

};

#endif /* STATS_H_ */
