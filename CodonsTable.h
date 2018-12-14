#ifndef CODONSTABLE_H
#define CODONSTABLE_H
#include <iostream>
#include <cstring>
#include "CodonsTable.h"
#include<fstream>
using namespace std;

class Protein;
struct Codon
{
  	char value[4];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};

// need to create one object of that class to load the AminoAcids table
// into memory
class CodonsTable
{
  	private:
        Codon codons[64];
   	public:
 	 	// constructors and destructor
        CodonsTable();
        ~CodonsTable();
 	 	// function to load all codons from the given text file
        Codon *getCodon();
        void LoadCodonsFromFile(string codonsFileName);
        char getAminoAcid(string invalue);
        void setCodon(char newvalue[4], char newAminoAcid, int index);
};

#endif // CODONSTABLE_H
