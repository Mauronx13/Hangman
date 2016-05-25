//
//  main.cpp
//  Hangman
//
//  Created by Maria Vargas Aponte on 5/23/16.
//  Copyright © 2016 Maria Vargas Aponte. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <ctime>

#include "Hangman.hpp"

using namespace std;

#pragma mark - Method Prototypes
void menu();
long wordCounter();
string loadWord(int);
void startGame();

#pragma mark - Main()
int main() {
    
    menu();
    

    
    return 0;
}

#pragma mark - Main Menu Method
void menu() {
    
    int selection;
    bool invalidSelection = true;
    
    while (invalidSelection) {
        
        cout << "*---- Hangman Menu ----*" << endl << endl;
        cout << "1. New Game" << endl
        << "2. Exit Game" << endl;
        cin >> selection;
        
        switch (selection) {
            case 1:
                //New Game Logic
                startGame();
                invalidSelection = false;
                break;
                
            case 2:
                //Exit Game
                cout << "Exit Game." << endl;
                invalidSelection = false;
                break;
                
            default:
//                system("cls");
                cout << "ERROR: Invalid selection from the menu." << endl;
                break;
                
        } // End Switch & Case
    } // End While Loop
}

#pragma mark - Get Random Word Methods
//  The worldCounter function will count the number of words in the "words.txt" file
//  and returns the number. The returned number will be then used by the loadWord function
//  to select a random word from the file.

long wordCounter() {
    
    ifstream file;

    file.open("words.txt");
    file.unsetf(std::ios_base::skipws);
    
    long wordCount = count(istream_iterator<char>(file), istream_iterator<char>(),'\n');
    
    file.close();
    
    return wordCount;
}

string loadWord(int wordCount) {
    
    string word = "Error selecting word";
    ifstream file;
    
    file.open("words.txt");
    
    if (file.fail()) {
        
        cout<<"Error opening file."<<endl;
        
    } else {
        
        // Generate random number between 1 and wordCount
        srand(int(time(0)));
        int wordNumber = rand() % wordCount + 1;
        
        for (int lineNumber = 1; getline(file,word) && lineNumber <= wordNumber; lineNumber++) {
            if (lineNumber == wordNumber) {
                return word;
            }
        }
        
        file.close();
    }
    
    return word;
}

void startGame() {
    
    int wordNumber = int(wordCounter());
    string selectedWord = loadWord(wordNumber);
    
    Hangman game = Hangman(selectedWord);
    
    cout<<endl;
    
    for (int counter = 1; counter <= game.getNumberOfLettersInWord() - 1; counter++) {
        
        cout<<"_ ";
    }
    
    cout<<endl;
    
    game.askForLetter();
    cout<<"The selected word is: "<<game.getWord()<<endl;
    
    
}
