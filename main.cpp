//
//  main.cpp
//  project2
//
//  Created by Darin Hunt on 9/30/18.
//  Copyright © 2018 Darin Hunt. All rights reserved.
//

#include <iostream>
#include "Header.h"
#include "d_node.h"
#include <time.h>





float makeScore(card &card1, float &score)
{
	int value = card1.getValue();
	string suit = card1.getSuit();
	
	switch(value)
	{
		case(1):
			score=score+10;
			break;
		case(2):
			score=0;
			break;
		case(3):
			score=0;
			break;
		case(4):
			score=0;
		case(5):
			score=0;
			break;
		case(6):
			score=0;
			break;
		case(7):
			score=score/2;
			break;
		case(8):
			break;
		case(9):
			break;
		case(10):
			break;
		case(11):
			score=score+5;
			break;
		case(12):
			score=score+5;
			break;
		case(13):
			score=score+5;
			break;
			

	}
	
	if (suit == "Spades")
	{
			score=score+1;
	}
	
	else if (suit == "Diamonds" || suit == "Hearts" || suit == "Clubs")
		cout << "Nothing added for suit" << endl;
		
	else
		{
		cout << "That is invalid pick again" << endl;
		
		}
		return score;
}

void playFlip()
{
	char ans='y';
	float score=0;
	deck deck1;
	cout << deck1 << endl;
    system("PAUSE");
    for (int i=0; i<3; i++)
    {
	
    deck1.shuffle();
    
	}
    cout << deck1 <<endl;
    
    cout << "Prease enter to see your deal..." << endl;
    system("PAUSE");
    
    deck1.printGameDeck(0);
    
    int count = 1 ;
    
    while (ans=='y')
    {
    	char response;
    	int pick;
    	cout << "Enter a card number between 1 and "<< 24-count+1 <<endl;
    	cin >> pick;
    	pick=pick-1;
    	if (pick>=24-count+1)
    	{
    		playFlip();
    		cout << "Please input a number no greater than " << 24-count+1 << endl;
    		
		}
		
    	card placeholder(deck1.deal(pick));
		makeScore(placeholder, score);
		deck1.replace(placeholder);
		cout << "You picked - " << placeholder << ". Your score is " << score<< endl;
		
		cout << "Press 'o' to see other deck, press 'c' to see the current deck or any other if you just would like to continue" << endl;
		cin >> response;
		
		if (response=='o')
		{
			deck1.printOtherDeck(count);
		}
		
		else if (response == 'c')
		{
		deck1.printGameDeck(count);
		}
		else
		{
			
		}
		
		
		count++;

		
		cout << "Do you wish to play again?" << endl;
		cin >> ans;
	}
	
}

int main()
{
	srand(time(NULL));
    
    playFlip();
    return 0;
}
