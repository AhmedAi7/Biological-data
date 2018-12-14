#include "RNA.h"
#include <iostream>
#include <cstring>
#include<string>
using namespace std;

RNA:: RNA()
{

}
RNA:: RNA(string s, RNA_Type atype)
{
    setseq(s);
    settype(atype);
}
RNA:: RNA(RNA& rhs)
{
    setseq(rhs.getseq());
    settype(rhs.gettype());
}
RNA:: ~RNA()
{
    // function to be overridden to print all the RNA information
}
void RNA:: Print()
{
    int l;
    l=getseq().length();
    for (int i=0 ; i<l ; i++)
        cout << getseq()[i];
}
Protein RNA:: ConvertToProtein(CodonsTable & table)
{
    Protein p;
    string valueElement;
    string newseq;
    for(int i=0 ; i<getseq().length(); i=i+3)
    {
        valueElement ="";
        for (int j=0;j<3;j++)
        {
            valueElement=valueElement+getseq()[i+j];
        }
        newseq=newseq+table.getAminoAcid(valueElement);
        }
        p.setseq(newseq);
return p;
}
DNA RNA:: ConvertToDNA()
{
    DNA dna ;
    string newseq = "";
    int l = getseq().length();
    for (int i=0 ; i<=l ; i++)
    {
        if (getseq()[i]== 'U')
            newseq=newseq+'T';
        else
            newseq=newseq+getseq()[i];
    }
    dna.setseq(newseq);
    cout << newseq;
return dna;
}
RNA RNA:: operator + (RNA &rna)
{
    RNA x;
    string SEQ;
    SEQ= this->getseq() + rna.getseq();
    x.setseq(SEQ);
    return x;
}
void RNA:: settype (RNA_Type t)
{
 type =t ;
}
RNA_Type RNA:: gettype()
{
    return type;
}
