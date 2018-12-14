#include "CodonsTable.h"
#include <iostream>
#include <cstring>
using namespace std;

 	 	// constructors and destructor
        CodonsTable:: CodonsTable()
        {

        }
        CodonsTable:: ~CodonsTable()
        {
 	 	// function to load all codons from the given text file
        }
         void CodonsTable:: LoadCodonsFromFile(string codonsFileName)
        {
            fstream FILE ;
            FILE.open("RNA_codon_table.txt",ios::in);
            if (FILE.fail())
                cout << "fail ";
            int counter=0;
            while (FILE&&!FILE.eof())
            {
                FILE >> codons[counter].value;
                FILE >> codons[counter].AminoAcid;
                counter++;
            }
            FILE.close();
        }
        Codon *CodonsTable:: getCodon()
        {
            return codons;
        }
        char CodonsTable:: getAminoAcid(string invalue)
        {
            for (int i=0 ; i<64 ; i++)
                if (codons[i].value==invalue && codons[i].AminoAcid!='*')
                    {
                        return codons[i].AminoAcid;
                    }
        }
        void CodonsTable:: setCodon(char newvalue[4], char newAminoAcid, int index)
        {
            codons[index].AminoAcid= newAminoAcid;
            codons[index].value[0]= newvalue[0];
            codons[index].value[1]= newvalue[1];
            codons[index].value[2]= newvalue[2];
        }
