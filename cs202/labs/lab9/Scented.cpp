#include "Scented.h"




Scented::Scented(string name, double burnRate, string flavor):Birthday(name,burnRate,true){


    m_flavor = flavor;
    //SetIsNoExtinguish(isNoExtinguish);
    
}

string Scented::GetFlavor(){

    return m_flavor;
}


void Scented::SetFlavor(string flavor){

    m_flavor = flavor;
}
