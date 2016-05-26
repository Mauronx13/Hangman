//
//  Hangman.cpp
//  Hangman
//
//  Created by Maria Vargas Aponte on 5/24/16.
//  Copyright © 2016 Maria Vargas Aponte. All rights reserved.
//

#include "Hangman.hpp"

using namespace std;

Hangman::Hangman() {
    
    this->selectedWord = "default";
    this->maxFailedAttemps = 6;
    this->numberOfLettersInWord = calculateNumberOfLettersInWord();
    
}

Hangman::Hangman(const Hangman &hangman) {
    
    this->selectedWord = hangman.selectedWord;
    this->numberOfLettersInWord = hangman.numberOfLettersInWord;
    this->maxFailedAttemps = hangman.maxFailedAttemps;

}

Hangman::Hangman(string word) {
    
    this->selectedWord = word;
    this->maxFailedAttemps = 6;
    this->numberOfLettersInWord = calculateNumberOfLettersInWord();
}

Hangman::~Hangman(void) {
    
}

void Hangman::menu() {
    
    int selection;
    bool invalidSelection = true;
    
    while (invalidSelection) {
        
        cout << "*---- Hangman Game Menu ----*" << endl << endl;
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
                invalidSelection = false;
                break;
                
            default:
                //                system("cls");
                cout << "ERROR: Invalid selection from the menu." << endl;
                break;
                
        } // End Switch & Case
    } // End While Loop
}

string Hangman::getWord() {
    
    return this->selectedWord;
}

void Hangman::setWord(string word) {
    
    this->selectedWord = word;
}

int Hangman::getNumberOfLettersInWord() {
    
    return this->numberOfLettersInWord;
}

void Hangman::setNumberOfLettersInWord(int number) {
    
    this->numberOfLettersInWord = number;
}

int Hangman::calculateNumberOfLettersInWord() {
    
    int numberOfLetters = 0;
    
    numberOfLetters = int(this->selectedWord.length());
    
    return numberOfLetters;
}

void Hangman::checkIfWordContainsLetter(char letter, int wordSize) {
    
    size_t position = this->selectedWord.find(letter, 0);
    
    if (position != std::string::npos) {
        
        wordArray[position] = letter;
        printFoundLetters(wordArray, wordSize);
        
        bool status = checkIfWordIsGuessed(wordArray, wordSize);
        
        if (status) {
            cout<<"\nWinner Winner Chicken Dinner!"<<endl;
            activeGame = false;
        }
        
        bool guessedCorreclty = guessWord();
        
        if (guessedCorreclty) {
            activeGame = false;
        }
        
        
    } else {
        
        cout<<"Wrong letter"<<endl;
        this->numberOfFailedAttempts++;
    }
}

void Hangman::askForLetter() {
    
    char letter;
    bool letterUsed = false;
    
    cout<<"\nEnter a letter: "<<endl;
    cin>>letter;
    
    for (int counter = 0; counter < 27; counter++) {
        
        char foundLetter = this->guessedLetters[counter];
        
        if (foundLetter == letter) {
            
            cout<<"Letter already used, please try a different letter"<<endl;
            letterUsed = true;
            break;
            
        }
    }
    
    if (!letterUsed) {
        
        guessedLetters[numberOfLettersUsed] = letter;
        numberOfLettersUsed++;
        
    }
        
    checkIfWordContainsLetter(letter, numLetters);
}

bool Hangman::startGame() {
    

    activeGame = true;
    numLetters = numberOfLettersInWord;
    
    drawLetterLines(numLetters);
    
    while (activeGame) {
        
        if (numberOfFailedAttempts < maxFailedAttemps) {
            askForLetter();

        } else {
            activeGame = false;
        }
    }
    
    return true;
}

void Hangman::drawLetterLines(int number) {
    
    for (int counter = 1; counter <= number - 1; counter++) {
        
        cout<<"_ ";
    }
    
    cout<<endl;
}

void Hangman::printFoundLetters(char array[], int size) {
    
    for (int counter = 0; counter < size - 1; counter++) {
        
        char currentLetter = wordArray[counter];
        
        if (currentLetter != NULL) {
            
            cout<<currentLetter<<" ";
            
        } else {
            
            cout<<"_ ";
        }
    }
}

bool Hangman::checkIfWordIsGuessed(char arra[], int size) {
    
    bool status = false;
    
    for (int counter = 0; counter < size - 1; counter++) {
        
        char currentLetter = wordArray[counter];
        
        if (currentLetter != NULL && counter == (size - 2)) {
            
            status = true;
            
        } else if (currentLetter == NULL) {
            
            return false;
        }
    }
    
    return status;
}

bool Hangman::guessWord() {
    
    char selection = 'N';
    string word;
    
    cout<<"Do you want to guess the word? (Y/N)"<<endl;
    cin>>selection;
    
    if (selection == 'y' || selection == 'Y') {
        
        cout<<"Enter the word: "<<endl;
        cin>>word;
        
        word = word + "\r";
        
        if (word == selectedWord) {
            
            cout<<"\nWinner Winner Chicken Dinner!!!"<<endl;
            
            return true;
            
        } else {
            
            cout<<"\nWrong Guess"<<endl;
        }

    }
    
    return false;
}




