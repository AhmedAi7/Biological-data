#ifndef PROTEIN_H
#define PROTEIN_H
#include <iostream>
#include <cstring>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "CodonsTable.h"

using namespace std;
class DNA;
enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
  	private:
        Protein_Type type;
      public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(string p);
 	 	~Protein();
 	 	// return an array of DNA sequences that can possibly
                // generate that protein sequence
        DNA *GetDNAStrandsEncodingMe(DNA &bigDNA);
        Protein operator + (Protein &p);
        void settype (Protein_Type t);
        Protein_Type gettype ();
};

#endif // PROTEIN_H
