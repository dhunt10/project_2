//
//  Header.h
//  project2
//
//  Created by Darin Hunt on 9/30/18.
//  Copyright © 2018 Darin Hunt. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include "d_node.h"
#include <vector>
#include <queue>
#include <time.h>

using namespace std;

class card
{
    friend class Deck;
public:
    card();
    card(const card &card1);
    void setValue(int m);
    void setSuit(string suitType);
    int getValue();
    string getSuit();
    friend ostream& operator << (ostream& ostr, const card &lhs);
    card operator = (const card &rhs); //not sure
private:
    int value;
    string suit;
};

card::card()
{
    value=0;
    suit= "Null";
	
}
card::card(const card &card1)
{
	value = card1.value;
	suit = card1.suit;	
	
}

void card::setValue(int m)
{
    value=m;
}

void card::setSuit(string suitType)
{
    suit=suitType;
}

string card::getSuit()
{
    return suit;
}

int card::getValue()
{
    return value;
}

ostream& operator << (ostream& ostr, const card &lhs)
{
   
    
    if (lhs.value == 1)
    {
    	 ostr << "Card is: " << endl << "Ace of " << lhs.suit << endl;
	}
	
	else if (lhs.value==11)
	{
		ostr << "Card is: " << endl << "Jack of " << lhs.suit << endl;
	}
	
	else if (lhs.value==12)
	{
		ostr << "Card is: " << endl << "Queen of " << lhs.suit << endl;
	}
	
	else if (lhs.value==13)
	{
		ostr << "Card is: " << endl << "King of " << lhs.suit << endl;
	}
	else 
	{
		ostr << "Card is: " << endl << lhs.value << " of " << lhs.suit << endl;
	}
	
	return ostr;
}

card card::operator = (const card &rhs)
{
	card newCard;
	newCard.suit=rhs.suit;
	newCard.value=rhs.value;
	return newCard;
}

class deck
{
public:
    deck();
    friend ostream& operator << (ostream& ostr, const deck &lhs);
    void shuffle();
    int getCards();
    void printDeck();
    void printGameDeck(int n);
    void printOtherDeck(int n);
    void replace (const card &bottomCard);
    card deal(int n);
    ~deck();
private:
    int numberinDeck;
    node <card> *front = NULL;
    node <card> *curr;
    node <card> *prev;
    node <card> *newNode;
    card sendCard;
    
};

void deck::printDeck()
{
	node <card> *list;
    list=front;
    int value;
    for (value=0;value<52;value++)
    {
     	cout << list->nodeValue << endl;
        list = list->next;
       
    }
}

ostream& operator << (ostream& ostr, const deck &lhs)
{
	node <card> *list;
    list=lhs.front;
    int value;
    for (value=0;value<52;value++)
    {
     	ostr << list->nodeValue << endl;
        list = list->next;
       
    }	
    return ostr;
}

void deck::printOtherDeck(int n)
{
	node <card> *list;
    list=front;
    int value;
    for (value=0;value<52;value++)
    {
     	
        list = list->next;
       
       if (value>=25-n && value <=50)
       {
    		cout << list->nodeValue << "  " << endl;
    	}
    	
		else
		{
			
		}
    }
}

void deck::printGameDeck(int n)
{
	node <card> *list;
    list=front;
    int value;
    for (value=0;value<24-n;value++)
    {
     	cout << list->nodeValue << endl;
        list = list->next;
       
    }
}


deck::deck()
{	int value = 0;
    string suit;
        for (int i=1; i<=4; i++)
       
	   { 
            for (int j=1; j<=13; j++)
            {
                
                switch(i)
                {
                    case(1):
                        suit = "Clubs";
                        break;
                    case(2):
                        suit = "Diamonds";
                        break;
                    case(3):
                        suit = "Hearts";
                        break;
                    case(4):
                        suit = "Spades";
                        break;
                    default:
                        suit = "Null";
                        break;
                }
                
                sendCard.setValue(j);
                sendCard.setSuit(suit);

                newNode = new node <card> (sendCard);
                if (value==0)
                {
                	front=newNode; //list is empty so both are set to the newnode
                	prev=newNode;

				}
				else 
				{	
					
					prev->next=newNode; //when list is not previously empty it assigns the next node to newNode
					prev=newNode; //assigns currewnt node to newNode

				}
				value++;
	}

}

}

void deck::shuffle()
{

	
       for (int i=0; i<10000; i++)
       {
       	node <card> *tmp=NULL;
        curr=front;
       	int x = rand()%52;
       	
        for (int j=0; j<x; j++)
        {
        	prev=curr; //sets previous to current value
        	curr=curr->next; //sets current to the next value
        	tmp=curr;
         }
           if (tmp) {                  // ensure the card you choose is valid
               prev->next=tmp->next; //removes node
               tmp->next=front;
               front=tmp;
           }
       }

}



card deck::deal(int n)
{
	node <card> *tmp1=NULL;
	node <card> *tmp2=NULL;
	node <card> *tmp3=NULL;
	tmp2=front;
	//cout << tmp2->nodeValue<<endl;
	if (n!=0)
	{

	for (int i=0; i<n; i++) 
	{
		tmp1=tmp2;
		tmp2=tmp2->next;
		tmp3=tmp2;
	}
	if (tmp3)
	{
	card temp=tmp2->nodeValue;
	cout << endl << endl << "You picked the card: " << temp << endl<< endl;
	tmp1->next=tmp3->next;
	return temp;
	}
}
	else 
	{
		card temp=front->nodeValue;
		return temp;
	}
	
}


void deck::replace(const card &bottomCard)
{
	node <card> *tmp1=NULL;
	node <card> *tmp2=NULL;
	node <card> *tmp3=NULL;
	newNode = new node <card> (bottomCard);

	tmp2=front;
	while (tmp2->next!=NULL)
	{
		tmp1=tmp2;
		tmp2=tmp2->next;
		tmp3=tmp2;
	}
	tmp2->next=newNode;
	newNode->next=NULL;
	//*tmp3=bottomCard;
}



deck::~deck()
{
	delete front;	
}


#endif /* Header_h */
