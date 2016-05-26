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
    
    string selectedWord;
    int numberOfLettersInWord = 0;
    char guessedLetters[MAX_LETTER_LENGTH];
    char wordArray[MAX_LEN];
    int numberOfLettersUsed = 0;
    int numberOfFailedAttempts = 0;
    int maxFailedAttemps = 0;
    
public:
    
    Hangman();
    Hangman(const Hangman &hangman);
    Hangman(string word);
    ~Hangman(void);
    
    string getWord();
    void setWord(string word);
    int getNumberOfLettersInWord();
    void setNumberOfLettersInWord(int number);
    int calculateNumberOfLettersInWord();
    void askForLetter();
    void checkIfWordContainsLetter(char letter);
    
    bool startGame();
    void drawLetterLines(int number);
};


#endif /* Hangman_hpp */
