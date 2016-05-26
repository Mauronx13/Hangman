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

void Hangman::checkIfWordContainsLetter(char letter) {
    
    size_t position = this->selectedWord.find(letter, 0);
    
    if (position != std::string::npos) {
        
        cout<<"The letter was found at the position: "<<position<<endl;
        
        
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
        numberOfFailedAttempts++;
    }
        
    checkIfWordContainsLetter(letter);
}

bool Hangman::startGame() {
    

    bool activeGame = true;
    const int numLetters = numberOfLettersInWord;
    
    drawLetterLines(numLetters);
    
    while (activeGame) {
        
        if (this->numberOfFailedAttempts < this->maxFailedAttemps) {
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
                    //ExitGame();
                    invalidSelection = false;
                    break;
                    
                default:
                    //                system("cls");
                    cout << "ERROR: Invalid selection from the menu." << endl;
                    break;
                    
            } // End Switch & Case
        } // End While Loop
    }
