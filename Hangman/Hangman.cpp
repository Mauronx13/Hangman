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
    
    this->selectedWord = "";
    
}

Hangman::Hangman(const Hangman &hangman) {
    
    this->selectedWord = hangman.selectedWord;
}

Hangman::Hangman(string word) {
    
    this->selectedWord = word;
}

Hangman::~Hangman(void) {
    
}

int Hangman::calculateNumberOfLettersInWord() {
    
    int numberOfLetters = 0;
    
    numberOfLetters = int(this->selectedWord.length());
    
    return numberOfLetters;
}