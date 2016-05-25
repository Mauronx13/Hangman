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
#include "MyString.hpp"


class Hangman {
    
    private:
    
    string selectedWord;
    
public:
    
    Hangman();
    Hangman(const Hangman &hangman);
    Hangman(string word);
    ~Hangman(void);
    
    int calculateNumberOfLettersInWord();
};


#endif /* Hangman_hpp */
