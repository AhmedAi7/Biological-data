#ifndef RNA_H
#define RNA_H
#include <iostream>
#include <cstring>
#include "DNA.h"
#include "Protein.h"
#include "Sequence.h"
#include "CodonsTable.h"

using namespace std;

class DNA ;
enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};
class RNA : public Sequence
{
  	private:
        RNA_Type type;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(string s, RNA_Type atype);
        RNA(RNA& rhs);
        ~RNA();
 	 	// function to be overridden to print all the RNA information
        void Print();
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
        Protein ConvertToProtein(CodonsTable & table);
 	 	// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();
        RNA operator + (RNA &rna);
        void settype (RNA_Type t);
        RNA_Type gettype();
};
#endif // RNA_H
