/**********************
 * File: Pirate.cpp
 * Project: CMSC Project 2, Fall 2020
 * Author: Udaya Garapati
 * Date: 10/8/2020
 * Section: 10/15  (Lec/Dis)
 * Email: udayag1@umbc.edu
 * Description: This file contain the Pirate class that holds all the capabilities of a pirate
 ************************/

#include "Pirate.h"


//Constructors
Pirate::Pirate(){
    m_pirateName = ""; //Name of Pirate
    m_pirateRating = 0; //Rating of Pirate
    m_pirateOrigin = ""; //Country of Origin of Pirate
    m_pirateDesc = ""; //Description of Pirate
    m_pirateCargo = 0; //Tons of cargo earned
    m_pirateDays = 0; //Days elapsed
    Ship m_curShip; //Pirate's current ship
}


Pirate::Pirate(string name, int rating, string origin, string desc){

    m_pirateName = name;
    m_pirateRating = rating;
    m_pirateOrigin = origin;
    m_pirateDesc = desc;
}


string Pirate::GetName(){

    return m_pirateName;
}

int Pirate::GetRating(){

    return m_pirateRating;
}

void Pirate::SetRating(int rating){
    m_pirateRating = rating;
}

string Pirate::GetOrigin(){
    return m_pirateOrigin;
}

string Pirate::GetDesc(){

    return m_pirateDesc;
}

void Pirate::SetCurShip(Ship curShip){

    m_curShip = curShip;

}

void Pirate::CalcTreasure(Ship enemyShip){

    m_pirateCargo += (enemyShip.m_cannon + enemyShip.m_toughness + enemyShip.m_speed)  / 3;
    
}

void Pirate::Battle(Pirate enemyPirate, Ship enemyShip){
    if(m_curShip.m_curToughness < 1){

        cout<<"You cant attack, your ship is damaged and it needs repair"<<endl;
        cout<<"Mission failed, we'll get em next time."<<endl;
    }
    else{

        m_pirateDays += 1;
        bool playerTurn = true;
        cout<<"Battles enemy"<<endl;
        int rand_int;
        int hits = 0;
        cout<<"A naval battle of the ages commences between "<<m_pirateName<<" and "<<enemyPirate.GetName()<<endl;
        while((m_curShip.m_curToughness > 1) && (enemyShip.m_curToughness > 1)){


            if(playerTurn){

                cout<<m_pirateName<< " fires "<<m_curShip.m_cannon<<" rounds"<<endl;
            
                for(int i = 0; i < m_curShip.m_cannon; i++){
                    rand_int = 1+ rand() % 100 < m_pirateRating;
                    if (rand_int) {
                        hits++;
                    }
                
                

                }
                enemyShip.m_curToughness -= hits;
                cout<<hits<<" shots hit!"<<endl;
                hits = 0;
            
                playerTurn = !playerTurn;
            
            }
            else{

                cout<<enemyPirate.GetName()<<" fires "<<enemyShip.m_cannon<<" rounds"<<endl;
                for(int i = 0; i < enemyShip.m_cannon; i++){
                    rand_int = 1+ rand() % 100 < enemyPirate.GetRating();
                    if(rand_int){
                        hits++;
                    }
                
                
                }
                m_curShip.m_curToughness -= hits;
                cout<<hits<<" shots hit!"<<endl;
                hits = 0;
                playerTurn = !playerTurn;
            }        
        }
    if(m_curShip.m_curToughness < 1){
            cout<<"You lose"<<endl;
            m_pirateCargo = m_pirateCargo / 2;
            m_curShip.m_curToughness = 0;
        }
        else{
            cout<<"you win!"<<endl;
            CalcTreasure(enemyShip);
        }
    }        
    
}

void Pirate::RepairShip(){
    int daysNeeded = 0;
    cout<<"Repairs the ship"<<endl;
    daysNeeded += m_curShip.m_toughness - m_curShip.m_curToughness;
    m_curShip.m_curToughness = m_curShip.m_toughness;
    m_pirateDays += daysNeeded;
    cout<<"It takes "<<daysNeeded<< " days to repair your "<<m_curShip.m_type<<endl;
}

void Pirate::Flee(Pirate enemyPirate, Ship enemyShip){


    cout<<"You attempt to flee from "<< enemyPirate.GetName()<<endl;
    m_pirateDays+=1;

    if(m_curShip.m_speed > enemyShip.m_speed){
        cout<<"You narrowly escape from "<<enemyPirate.GetName()<<endl;

    }
    else{
        
        
        Battle(enemyPirate,enemyShip);
        
    }



}

void Pirate::DisplayScore(){
    cout<<"************************"<<endl;
    cout<<"Name: "<<m_pirateName<<endl;
    cout<<"Rating: "<<m_pirateRating<<endl;
    cout<<"Country of Origin: "<<m_pirateOrigin<<endl;
    cout<<"Description: "<<m_pirateDesc<<endl;
    cout<<"Days Sailing: "<<m_pirateDays<<endl;
    cout<<"Cargo Captured: "<<m_pirateCargo<<endl;
    cout<<"Cargo per day: "<<(double)m_pirateCargo / (double)m_pirateDays<<endl;
    cout<<"Ship Type: "<<m_curShip.m_type<<endl;
    cout<<"Ship Cannons: "<<m_curShip.m_cannon<<endl;
    cout<<"Ship Current Toughness: "<<m_curShip.m_curToughness<<endl;
    cout<<"Ship Max Toughness: "<<m_curShip.m_toughness<<endl;
    cout<<"Ship Speed: "<<m_curShip.m_speed<<endl;
    cout<<"************************"<<endl;


    

}


