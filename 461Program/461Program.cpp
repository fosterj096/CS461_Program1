#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

int main()
{
    //Function Definitions
    void emptyHand(string array[]);
    void resetDeck(string mainDeck[], string copymainDeck[]);
    void loadOneHand(string currHand[], string mainDeck[]);
    int handValueCalc(string currHand[]);
    int returnHighestCard(string currHand[]);

    //Win Counters and other Variables
    float mainHandWin = 0;
    float hand1Win = 0;
    float hand2Win = 0;
    float hand3Win = 0;
    float hand4Win = 0;
    float hand5Win = 0;
    float draw = 0;
    int roundCounter = 0;

    srand(time(0));

    string cardsInUse[35];

    //After trying the more "professional" way of using an actual object class for the cards and not working I'm resorting to a simpler approach
    //Here the first character represents the suit and the second represents the value of the card
    string mainDeck[52] =
    { "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "HJ", "HQ", "HK",
        "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "DJ", "DQ", "DK",
        "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "SJ", "SQ", "SK",
        "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "CJ", "CQ", "CK" };
    //used to reset the deck back to normal
    
    string copymainDeck[52] =
    { "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "HJ", "HQ", "HK",
        "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "DJ", "DQ", "DK",
        "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "SJ", "SQ", "SK",
        "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "CJ", "CQ", "CK" };
    
    //string arrays used to hold the cards
    string staticHand[5] = { "0",  "0",  "0",  "0",  "0" }; //the hand that doesn't change
    string hand1[5] = { "0",  "0",  "0",  "0",  "0" };
    string hand2[5] = { "0",  "0",  "0",  "0",  "0" };
    string hand3[5] = { "0",  "0",  "0",  "0",  "0" };
    string hand4[5] = { "0",  "0",  "0",  "0",  "0" };
    string hand5[5] = { "0",  "0",  "0",  "0",  "0" };

    loadOneHand(hand1, mainDeck);
    handValueCalc(hand1);
    ofstream myCSVFile;
    
    myCSVFile.open("outputData.csv");
    myCSVFile << "The hands correspond to a numerical value. 1 =  One pair, 2 = 2 Pair, 3 = Three of a Kind, etc. \n";

    //Main Game Playing loop
    for (int i = 0; i < 50; i++)
    {
        loadOneHand(staticHand, mainDeck);
        int staticHandValue = handValueCalc(staticHand);
        for (int i = 0; i < 500; i++)
        {
            loadOneHand(hand1, mainDeck);
            loadOneHand(hand2, mainDeck);
            loadOneHand(hand3, mainDeck);
            loadOneHand(hand4, mainDeck);
            loadOneHand(hand5, mainDeck);

            int hand1Val = handValueCalc(hand1);
            int hand2Val = handValueCalc(hand2);
            int hand3Val = handValueCalc(hand3);
            int hand4Val = handValueCalc(hand4);
            int hand5Val = handValueCalc(hand5);

            myCSVFile << "Current Round: " << roundCounter << endl;
            myCSVFile << "Main Hand: " << staticHandValue << endl;
            myCSVFile << "Hand 1: " << hand1Val << endl;
            myCSVFile << "Hand 2: " << hand2Val << endl;
            myCSVFile << "Hand 3: " << hand3Val << endl;
            myCSVFile << "Hand 4: " << hand4Val << endl;
            myCSVFile << "Hand 5: " << hand5Val << endl;

            if ((staticHandValue > hand1Val) && (staticHandValue > hand2Val) && (staticHandValue > hand3Val) && (staticHandValue > hand4Val) && (staticHandValue > hand5Val))
            {
                mainHandWin += 1;
            }
            if ((hand1Val > staticHandValue) && (hand1Val > hand2Val) && (hand1Val > hand3Val) && (hand1Val > hand4Val) && (hand1Val > hand5Val))
            {
                hand1Win += 1;
            }
            if ((hand2Val > staticHandValue) && (hand2Val > hand1Val) && (hand2Val > hand3Val) && (hand2Val > hand4Val) && (hand2Val > hand5Val))
            {
                hand2Win += 1;
            }
            if ((hand3Val > staticHandValue) && (hand3Val > hand1Val) && (hand3Val > hand2Val) && (hand3Val > hand4Val) && (hand3Val > hand5Val))
            {
                hand3Win += 1;
            }
            if ((hand4Val > staticHandValue) && (hand4Val > hand1Val) && (hand4Val > hand2Val) && (hand4Val > hand3Val) && (hand4Val > hand5Val))
            {
                hand4Win += 1;
            }
            if ((hand5Val > staticHandValue) && (hand5Val > hand1Val) && (hand5Val > hand2Val) && (hand5Val > hand3Val) && (hand5Val > hand4Val))
            {
                hand5Win += 1;
            }
            if (hand1Val == hand2Val)
            {
                if (returnHighestCard(hand1) > returnHighestCard(hand2))
                {
                    hand1Win++;
                }
                else {
                    hand2Win++;
                }
            }
            if (hand1Val == hand3Val)
            {
                if (returnHighestCard(hand1) > returnHighestCard(hand3))
                {
                    hand1Win++;
                }
                else {
                    hand3Win++;
                }
            }
            if (hand1Val == hand4Val)
            {
                if (returnHighestCard(hand1) > returnHighestCard(hand4))
                {
                    hand1Win++;
                }
                else {
                    hand4Win++;
                }
            }
            if (hand1Val == hand5Val)
            {
                if (returnHighestCard(hand1) > returnHighestCard(hand5))
                {
                    hand1Win++;
                }
                else {
                    hand5Win++;
                }
            }
            if (hand2Val == hand3Val)
            {
                if (returnHighestCard(hand2) > returnHighestCard(hand3))
                {
                    hand2Win++;
                }
                else {
                    hand3Win++;
                }
            }
            if (hand4Val == hand2Val)
            {
                if (returnHighestCard(hand2) > returnHighestCard(hand4))
                {
                    hand2Win++;
                }
                else {
                    hand4Win++;
                }
            }
            if (hand5Val == hand2Val)
            {
                if (returnHighestCard(hand2) > returnHighestCard(hand5))
                {
                    hand2Win++;
                }
                else {
                    hand5Win++;
                }
            }
            if (hand3Val == hand4Val)
            {
                if (returnHighestCard(hand3) > returnHighestCard(hand4))
                {
                    hand3Win++;
                }
                else {
                    hand4Win++;
                }
            }
            if (hand4Val == hand5Val)
            {
                if (returnHighestCard(hand4) > returnHighestCard(hand5))
                {
                    hand4Win++;
                }
                else {
                    hand5Win++;
                }
            }
            
            emptyHand(hand1);
            emptyHand(hand2);
            emptyHand(hand3);
            emptyHand(hand4);
            emptyHand(hand5);
            resetDeck(mainDeck, copymainDeck);
            roundCounter++;
        }
    }

    //Text File and CSV Outputs
    ofstream myTextFile;
    myTextFile.open("outputData.txt");
    myTextFile << "This is the text file containing the data for the poker simulation.\n";
    myTextFile << "This is a simple summary of the entire process and how often each hand won. More detailed data is in the CSV file.\n";
    myTextFile << "The main static hand won approximately " << (mainHandWin / 2500) << "% of the time!\n";
    myTextFile << "The first hand won approximately " << (hand1Win / 2500) << "% of the time!\n";
    myTextFile << "The second hand won approximately " << (hand2Win / 2500) << "% of the time!\n";
    myTextFile << "The third hand won approximately " << (hand3Win / 2500) << "% of the time!\n";
    myTextFile << "The fourth hand won approximately " << (hand4Win / 2500) << "% of the time!\n";
    myTextFile << "The fifth hand won approximately " << (hand5Win / 2500) << "% of the time!\n";
    myTextFile.close();
    myCSVFile.close();
};

//Reset Hand
void emptyHand(string array[]){
    for (int i = 0; i < 5; i++) {
        array[i] = "0";
    }
}
//Loads a hand with regard to cards already in use
void loadOneHand(string currHand[], string mainDeck[]) {
    int handIterator = 0;
    while (currHand[4] == "0") {

        int randInt = rand() % 52;
        if (mainDeck[randInt] != "0") {
            currHand[handIterator] = mainDeck[randInt];
            mainDeck[randInt] = "0";
            handIterator++;
        }
    }
}
//Reset deck to default
void resetDeck(string mainDeck[], string copymainDeck[]) {
    //mainDeck[52] = copymainDeck[52];
    for (int i = 0; i < 52; i++)
    {
        mainDeck[i] = copymainDeck[i];
    }
}
//Pair, Two Pair, Three Pair, Three of a Kind, Straight(any 5 in order), Flush(5 same suit), Full House(3 kind, 1 pair), 4 of a kind, straight flush(straight + flush)
int handValueCalc(string currHand[]) {
   
    int handValue = 0;
    string cardRead = "";

    for (int i = 0; i < 5; i++) {
        cardRead = cardRead + currHand[i];
    }
    string card1 = currHand[0];
    string card2 = currHand[1];
    string card3 = currHand[2];
    string card4 = currHand[3];
    string card5 = currHand[4];
    //changing from char to int for ease of calculation
    char suit1 = card1[0];
    char value1 = card1[1];
    char suit2 = card2[0];
    char value2 = card2[1];
    char suit3 = card3[0];
    char value3 = card3[1];
    char suit4 = card4[0];
    char value4 = card4[1];
    char suit5 = card5[0];
    char value5 = card5[1];
    //Convoluted conversion from letter char to number char for comparision
    if (value1 == 'J') { value1 = '11'; };
    if (value1 == 'Q') { value1 = '12'; };
    if (value1 == 'K') { value1 = '13'; }
    if (value2 == 'J') { value2 = '11'; };
    if (value2 == 'Q') { value2 = '12'; };
    if (value2 == 'K') { value2 = '13'; }
    if (value3 == 'J') { value3 = '11'; };
    if (value3 == 'Q') { value3 = '12'; };
    if (value3 == 'K') { value3 = '13'; }
    if (value4 == 'J') { value4 = '11'; };
    if (value4 == 'Q') { value4 = '12'; };
    if (value4 == 'K') { value4 = '13'; }
    if (value5 == 'J') { value5 = '11'; };
    if (value5 == 'Q') { value5 = '12'; };
    if (value5 == 'K') { value5 = '13'; }
    //straight flush
    if ((suit1 == suit2 && suit2 == suit3 && suit3 == suit4 && suit4 == suit5) && (value1 > value2 > value3 > value4 > value5))
    {
        handValue = 8;
    }
    //4 of a kind
    if ((value1 == value2 == value3 == value4) || (value2 == value3 == value4 == value5) || (value1 == value2 == value3 == value5) || (value1 == value2 == value4 == value5)
        || (value1 == value3 == value4 == value5))
    {
        handValue = 7;
    }
    //full house
    if ((value1 == value2 == value3) || (value1 == value2 == value4) || (value1 == value2 == value5) || (value1 == value3 == value4) || (value1 == value4 == value5) || (value2 == value3 == value4) || (value2 == value3 == value5) || (value2 == value3 == value4) || (value3 == value4 == value5) &&
        (value1 == value2 || value1 == value3 || value1 == value4 || value1 == value5 || value2 == value3 || value2 == value4 || value2 == value5 || value3 == value4 || value3 == value5 || value4 == value5)) {
        handValue = 6;
    }
    //flush
    if (suit1 == suit2 && suit2 == suit3 && suit3 == suit4 && suit4 == suit5)
    {
        handValue = 5;
    }
    //straight
    if ((value1 > value2 > value3 > value4 > value5) || (value1 < value2 < value3 < value4 < value5))
    {
        handValue = 4;
    }
    //three of a kind
    if (value1==value2==value3 || value1==value2==value4 || value1==value2==value5 || value1==value3==value4 || value1==value4==value5 || value2==value3==value4 || value2==value3==value5 || value2==value3==value4 || value3==value4==value5)
        {
            handValue = 3;
        }
    //two pair
    if ((value1 == value2 && value3 == value4) || (value1 == value2 && value4 == value5) || (value2 == value3 && value1 == value4) || (value2 == value4 && value1 == value3))
    {
        handValue = 2;
    }
    //pair
    if (value1 == value2 || value1 == value3 || value1 == value4 || value1==value5 || value2==value3 || value2==value4 || value2==value5 || value3==value4 || value3==value5 || value4==value5)
    {
        handValue = 1;
    }
    return handValue;
}

int returnHighestCard(string currHand[]) {

    char highest = '0';
    string cardRead = "";
    
    for (int i = 0; i < 5; i++) {
        cardRead = cardRead + currHand[i];
    }

    string card1 = currHand[0];
    string card2 = currHand[1];
    string card3 = currHand[2];
    string card4 = currHand[3];
    string card5 = currHand[4];

    char suit1 = card1[0];
    char value1 = card1[1];
    char suit2 = card2[0];
    char value2 = card2[1];
    char suit3 = card3[0];
    char value3 = card3[1];
    char suit4 = card4[0];
    char value4 = card4[1];
    char suit5 = card5[0];
    char value5 = card5[1];

    char allValues[5] = { value1, value2, value3, value4, value5 };

    for (int i = 0; i < 5; i++)
    {
        if (allValues[i] > highest)
        {
            highest = allValues[i];
        }
    }
    return highest;
}
