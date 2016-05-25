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
    this->numberOfLettersInWord = calculateNumberOfLettersInWord();
    
}

Hangman::Hangman(const Hangman &hangman) {
    
    this->selectedWord = hangman.selectedWord;
    this->numberOfLettersInWord = hangman.numberOfLettersInWord;
}

Hangman::Hangman(string word) {
    
    this->selectedWord = word;
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

bool Hangman::checkIfWordContainsLetter(char letter) {
    
    size_t position = this->selectedWord.find(letter, 0);
    
    if (position != std::string::npos) {
        
        cout<<"The letter was found at the position: "<<position<<endl;
        return true;
        
    } else {
        
        cout<<"Wrong letter"<<endl;
    }
    
    return false;
}

void Hangman::askForLetter() {
    
    char letter;
    
    cout<<"Enter a letter: "<<endl;
    cin>>letter;
    
    checkIfWordContainsLetter(letter);
}
