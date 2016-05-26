//
//  Hangman.hpp
//  Hangman
//
//  Created by Maria Vargas Aponte on 5/24/16.
//  Copyright © 2016 Maria Vargas Aponte. All rights reserved.
//

#ifndef Hangman_hpp
#define Hangman_hpp

#include <stdio.h>
#include "Constants.h"
#include "MyString.hpp"

class Hangman {
    
    private:
    
    static const int MAX_LEN = maxArrayLegth;
    static const int MAX_LETTER_LENGTH = maxNumberOFGuessedLetters;
    
    bool activeGame;
    string selectedWord;
    int numberOfLettersInWord = 0;
    char guessedLetters[MAX_LETTER_LENGTH] = {0};
    char wordArray[MAX_LEN] = {0};
    int numLetters = 0;
    int numberOfLettersUsed = 0;
    int numberOfFailedAttempts = 0;
    int maxFailedAttemps = 0;
    
public:
    
    Hangman();
    Hangman(const Hangman &hangman);
    Hangman(string word);
    ~Hangman(void);
    
    void menu();
    bool startGame();
    string getWord();
    void setWord(string word);
    int getNumberOfLettersInWord();
    void setNumberOfLettersInWord(int number);
    int calculateNumberOfLettersInWord();
    void askForLetter();
    void checkIfWordContainsLetter(char letter, int wordSize);
    void printFoundLetters(char array[], int size);
    void drawLetterLines(int number);
    bool checkIfWordIsGuessed(char array[], int size);
    bool guessWord();
    void drawHangMan();
};


#endif /* Hangman_hpp */
