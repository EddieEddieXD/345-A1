#include<iostream>
#include<cstdlib>
#include <string>
#include <vector>
#include <random>
#include "Cards.h"
using namespace std;

//********************************* CARD *********************************
//Card has a randomly assigned type at construction. 
//Cards are used in Deck and Hand.
        
        string typeOfCard;
        int Card::typeNumber = 0;
       
        //default constructor
        Card::Card(){ 
            //cycles through the 5 types of card, changes every time a Card object is created.
            typeNumber = typeNumber%5;
            typeNumber++;
            // cout << "type number is " << typeNumber << endl; //for debugging
            switch(typeNumber) {
                case 1  :
                    typeOfCard = "Bomb";
                    break;
                case 2  :
                    typeOfCard = "Reinforcement";
                    break;
                case 3  :
                    typeOfCard = "Blockade";
                    break;
                case 4  :
                    typeOfCard = "Airlift";
                    break;
                case 5  :
                    typeOfCard = "Diplomacy";
                    break;
                default :
                    typeOfCard = "PROBLEM";
            }      
        };

        //copy constructor
        Card::Card(const Card &inputCard){ 
            this->typeOfCard = inputCard.typeOfCard;
            // cout << "\nCard copied." << endl; //for debugging
        };
        
        ostream& operator << (ostream& outputStream, const Card& c){
            outputStream << "Card with type " << c.typeOfCard << endl;
            return outputStream;
        };

        //play() returns an order to be added to a Player's OrdersList, ie. Player p; Card c; p.issueOrder(c.play("orderType"));
        // Orders Card::play(){   
        //     Orders(this.typeOfCard);
        //      createOrder();
        //     void toPlayerOrderList();
        //     void returnToDeck();
        // };

        //destructor
        Card::~Card(){}; 


//********************************* DECK *********************************
//A Deck contains a finite collection of Cards.
    
        int numCardsInDeck;
        std::__1::vector<Card*> deckOfCards;

        //default constructor
        Deck::Deck(){
            //calls Card constructor, creates Deck of random Cards.
            cout << "\n*****New Deck created.*****" << endl;
            cout << "How many cards in this deck? " << endl;
            cin >> numCardsInDeck;
            for (int i = 0; i < numCardsInDeck; i++){
                Card *cardInDeck = new Card();
                deckOfCards.push_back(*cardInDeck);
            }
            cout << "Done creating deck" << endl;
        };

        //copy constructor
        Deck::Deck(const Deck &inputDeck){ 
            this->numCardsInDeck = inputDeck.numCardsInDeck;
            this->deckOfCards = inputDeck.deckOfCards;
            cout << "\nDeck copied." << endl;
        };

        //outstream operator overloading
        ostream& operator << (ostream& outputStream, const Deck& d){
            outputStream << "\n*****Deck contains:*****" << endl;
            for (int i = 0; i < d.deckOfCards.size(); i++){
                outputStream << d.deckOfCards.at(i);
            } 
            return outputStream;
        };

        //draw() draws a Card at random from remaining Cards in Deck and places in a Player's Hand.
        //Then removes chosen Card from Deck.
        int randomCardNumber=0;
        Card Deck::draw(){
            std::random_device rd; //random number generator from slide 16 @ https://view.officeapps.live.com/op/view.aspx?src=http%3a%2f%2fvideo.ch9.ms%2fsessions%2fgonat%2f2013%2fSTLGN13rand.pptx
            std::mt19937 mt(rd());
            std::uniform_real_distribution<double> dist(1.0, deckOfCards.size());
            randomCardNumber = dist(mt);
            // cout << "randomCardNumber is " << randomCardNumber << endl; //for debugging
            Card toReturn; 
            toReturn.typeOfCard = deckOfCards.at(randomCardNumber).typeOfCard; //draw random card
            cout << "\nUsing Deck::draw(), " << toReturn.typeOfCard << " Card drawn from deck." << endl;
            deckOfCards.erase( std::next(deckOfCards.begin(), randomCardNumber)); //erase drawn card from deck
            return toReturn;
        };
       
        //destructor
        Deck::~Deck(){}; 

//********************************* HAND *********************************
//A Hand contains a finite collection of Cards.
        std::__1::vector<Card> handOfCards;

        //default constructor
        Hand::Hand(){       
            cout << "\n*****New Hand created.*****" << endl;
        };

        //copy constructor
        Hand::Hand(const Hand &inputHand){ 
            this->handOfCards = inputHand.handOfCards;
            cout << "\nHand copied." << endl;
        };
        
        //outstream operator overloading
        ostream& operator << (ostream& outputStream, const Hand& h){ 
            outputStream << "\n*****Hand contains:*****" << endl; 
            if (h.handOfCards.size() == 0){
                outputStream << "This hand is empty!" << endl;
                return outputStream;
            }
            for (int i = 0; i < h.handOfCards.size(); i++){
                cout << h.handOfCards.at(i);
            }
            return outputStream;
        };

        void Hand::addCardToHand(Card toAdd){
            handOfCards.push_back(toAdd);
        };

        //destructor
        Hand::~Hand(){}; 
