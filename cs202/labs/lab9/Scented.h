#ifndef SCENTED_H
#define SCENTED_H

#include <iostream>
#include "Birthday.h"

using namespace std;


class Scented: public Birthday{

    public:
        Scented(string name, double burnRate, string flavor);
        void SetFlavor(string flavor);
        string GetFlavor();



    protected:
        string m_flavor;
    
};


#endif