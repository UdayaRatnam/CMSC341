/**********************
 * File: Game.cpp
 * Project: CMSC Project 2, Fall 2020
 * Author: Udaya Garapati
 * Date: 10/8/2020
 * Section: 10/15  (Lec/Dis)
 * Email: udayag1@umbc.edu
 * Description: This file contains the Game class.
 * The game class has functions that are key parts to the games mechanics
 ************************/
#include "Game.h"



Game::Game(){

    Pirate m_allPirates[MAX_PIRATES]; //All Pirates in game (loaded from file)
    Pirate m_myPirate; //Player's Pirate for the game
    Ship m_ships[MAX_SHIPS]; //All ships in the game (loaded from file)
    LoadShips();
    LoadPirates();
    GameTitle();
    

}
/**
 * This function opens up a file containing all ships
 * and reads them into object by taking each line of the file and splitting
 * it by a comma
 */
void Game::LoadShips(){
    //Variables
    string line, type,desc;
    int toughness, cannon, speed, index = 0;
    ifstream inputstream;
    inputstream.open(PROJ2_SHIPS);
    while(getline(inputstream, line)){
        stringstream ss(line);
        getline(ss,type,',');
        getline(ss,desc,',');
        cannon = std::stoi(desc);
        getline(ss,desc,',');
        toughness = std::stoi(desc);
        getline(ss,desc,',');
        speed = std::stoi(desc);
        getline(ss,desc,'.');
        m_ships[index] = {type, cannon, toughness, speed, desc};
        index++;
    }

}

/**
 * This function opens up a file containing all the pirates
 * and reads them into object by taking each line of the file and splitting
 * it by a comma
 */
void Game::LoadPirates(){
    string line;
    string name, desc, origin;
    int rating, index = 0;
    ifstream inputstream;
    inputstream.open(PROJ2_PIRATES);
    while(getline(inputstream, line)){
        stringstream ss(line);
        getline(ss,name, ',');
        getline(ss,desc,',');
        rating = std::stoi(desc);
        getline(ss,origin,',');
        getline(ss,desc,',');
        m_allPirates[index] = {name, rating, origin, desc};
        index++;
        
    }
}

void Game::StartGame(){
    int randomPirate = rand() % (sizeof(m_allPirates) / sizeof(m_allPirates[0]));
    m_myPirate = m_allPirates[randomPirate];
    int randomShip = rand() % (sizeof(m_ships) / sizeof(m_ships[0]));
    Ship playerShip = m_ships[randomShip];
    m_myPirate.SetCurShip(playerShip);
    cout<<sizeof(m_allPirates) / sizeof(m_allPirates[0])<<", "<<sizeof(m_ships) / sizeof(m_ships[0])<<endl;
    cout<<"Congratulations! "<<m_myPirate.GetName() <<" is now available to plunder!"<<endl;
    cout<<m_myPirate.GetName()<<" is now aboard a "<<playerShip.m_type<<endl;
    int action = MainMenu();
    bool notRetired = true;
    do{
        
        switch(action){
            case 1:
                SearchTreasure();
                action = MainMenu();
                break;
            case 2:
                m_myPirate.RepairShip();
                action = MainMenu();
                break;
            case 3:
                m_myPirate.DisplayScore();
                action = MainMenu();
                break;
            case 4:
                m_myPirate.DisplayScore();
                cout<<m_myPirate.GetName()<<" sails off into retirement"<<endl;
                cout<<"Thanks for playing pirates"<<endl;
                notRetired = false;
                break;
            
        }

    

    }while(notRetired);    

    


}

int Game::MainMenu(){
    int choice;

    do{
        cout<<"What would you like to do?"<<endl;
        cout<<"1. Search for Treasure"<<endl;
        cout<<"2. Repair Ship"<<endl;
        cout<<"3. See Score"<<endl;
        cout<<"4. Retire"<<endl;
        cin >>choice;
    }while((choice < 1) || (choice > 4));

    return choice;
}


void Game::SearchTreasure(){


    int randomEnemy = rand() % (sizeof(m_allPirates) / sizeof(m_allPirates[0]));
    Pirate enemy = m_allPirates[randomEnemy];
    int randomEnemyShip =  rand() % (sizeof(m_ships) / sizeof(m_ships[0]));
    Ship enemyShip = m_ships[randomEnemyShip];
    int choice;
    enemy.SetCurShip(enemyShip);
    cout<<"You scan the horizon for prospective targets..."<<endl;
    
    
    cout<<"Off in the distance you see "<<enemy.GetName()<< " on a "<<enemyShip.m_type<<endl;
    do{

    
        cout<<"What would you like to do?"<<endl;
        cout<<"1. Attack "<<enemy.GetName()<<endl;
        cout<<"2. Attempt to flee from "<<enemy.GetName()<<endl;
        cin >> choice;
    }while(choice < 1 || choice > 2);
    if (choice == 1){
        
        m_myPirate.Battle(enemy, enemyShip);
    }
    else{

        m_myPirate.Flee(enemy, enemyShip);
    }
    

}


