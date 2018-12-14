#include "Protein.h"
#include <iostream>
#include <cstring>
#include "CodonsTable.h"
using namespace std;

Protein:: Protein()
{

}
Protein:: Protein(string p)
{
    setseq(p);
}
Protein:: ~Protein()
{
    // return an array of DNA sequences that can possibly
    // generate that protein sequence
}
DNA* Protein:: GetDNAStrandsEncodingMe(DNA & bigDNA)
{
    DNA *strands = new DNA [10];
    int counter = 0;
    CodonsTable table ;
    table.LoadCodonsFromFile("DNA_codon_table.txt");
    Codon *codons;
    codons=table.getCodon();
    int endofloop ; //index in which the first loop will end
    endofloop= bigDNA.getseq().length() - 3*getseq().length();
    string singleElements[getseq().length()];
    string newprotein="";
    string newsequence= "";
    for (int i=0; i<=endofloop; i++)
    {
        for (int j=0; j<getseq().length(); j++)
        {
            string element="";
            for (int k=0; k<3; k++)
            {
                element=element+bigDNA.getseq()[j*3+k];
            }
            singleElements[j]=element;
        }
        for (int j=0; j<getseq().length(); j++)
        {
            for (int c=0 ; c<64 ; c++)
            {
                if (codons[c].value==singleElements[j] && codons[c].AminoAcid!='*')
                {
                    newprotein=newprotein+codons[c].AminoAcid;
                }
            }
        }
        if (newprotein==getseq())
        {
            newsequence= "";
            for (int i =0 ; i <getseq().length();i++)
            {
                newsequence=newsequence+singleElements[i];
            }
        }
            strands[counter].setseq(newsequence);
            counter++;
    }
    return strands;
}
Protein Protein:: operator + (Protein &p)
{
    Protein x;
    string SEQ;
    SEQ= this->getseq() + p.getseq();
    x.setseq(SEQ);
    return x;
}
void Protein:: settype (Protein_Type t)
{
    type=t;
}
Protein_Type Protein:: gettype ()
{
    return type;
}
