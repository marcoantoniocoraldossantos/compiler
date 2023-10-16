// lexer.h
#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include "token.h"

token_list_t* lexical_analyzer(FILE *source_code_file);

#endif



/*
typedef struct {
    int transitionTable[NUM_STATES][NUM_CHAR_CLASSES];
    int acceptanceTable[NUM_STATES];
    // ... other necessary structures and types
} LexerDFA;


typedef enum {
    START_STATE,
    // Add more states as needed for your DFA
    STATE1,
    STATE2,
    // ...
    FINAL_STATE,
    ERROR_STATE
} DFState;


void initializeLexerDFA(LexerDFA *dfa);
int getNextState(LexerDFA *dfa, int currentState, int charClass);
int isCharUsed(int charClass);
int isAcceptanceState(LexerDFA *dfa, int state);
*/