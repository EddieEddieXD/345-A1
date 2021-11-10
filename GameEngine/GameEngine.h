#pragma once

#include "CommandProcessing.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <random>

using namespace std;
//all class we have
class Map;
class Player;
class Card;
class Orders;
class Territory;
class Continent;
class Deck;
class Hand;

class GameEngine{
    
    public:
    CommandProcessor cp; //GameEngine must use a Command Processor for getting input commands
    //default construction
    GameEngine();
    //copy constuction
    GameEngine(const GameEngine& GE);
    GameEngine& operator = (const GameEngine& GE);
    friend std::ostream& operator<<(std::ostream& stream, const GameEngine& g);
    std::string input;
    int state;
    /*
    * state 0 = Start();
    *       1 = MapLoaded();
    *       2 = MapValidated();
    *       3 = PlayersAdded();
    *       4 = AssignReinforcement();
    *       5 = IssueOrders();
    *       6 = ExecuteOrders();
    *       7 = Win();
    */
   
    //step from requirement
    void Start();
    void MapLoaded();
    void MapValidated();
    void PlayersAdded();
    void AssignReinforcement();
    void IssueOrders();
    void ExecuteOrders();
    void Win();
    //for running program
    void Loop();

    //Assignment 2:
    void startupPhase();

};
 