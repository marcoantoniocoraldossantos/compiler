// libraries used
#include <stdio.h>
#include <stdlib.h>

// include all header files
#include "utilities.h"
#include "buffer.h"
#include "token.h"
#include "lexer.h"
#include "error.h"

token_list_t* lexical_analyzer(FILE *source_code_file) 
{
    token_list_t *token_list = initialize_token_list();
    buffer_t buffer = allocate_buffer(256);

    while(!feof(source_code_file))
    {
        fill_buffer(source_code_file, &buffer);
        print_buffer(&buffer);
        // while(buffer.data[buffer.position] != '\0')
        // {
        //     char currentChar = get_next_char(&buffer);
        //     printf("%c", currentChar);
        // }
    }

    // Perform lexical analysis using the lexer
    // The lexer should generate tokens using the lexProcessSourceCode function

    // // Example: Add a sample token to the list
    // token_t sampleToken;
    // sampleToken.type = RESERVED_WORD;
    // sampleToken.line = 1;
    // sampleToken.lexeme = "example";
    // add_token_to_list(token_list, &sampleToken);

    //print_token_list(token_list);
    return token_list;
}


/*

// lexer.c

#include "lexer.h"

// Transition table using the defined DFA states
int transitionTable[NUM_STATES][NUM_CHAR_CLASSES] = {
    // Define transitions between states based on input characters
    // ...
};

void initializeLexerDFA(LexerDFA *dfa) {
    // TODO: Initialize transition table, character classification table, acceptance table, etc.
    // You would populate the tables and other structures needed for the lexer here.
    // This function provides a centralized place to set up the DFA and related components.
    // You can also set default states or configurations for the lexer.
}


void initializeLexerDFA(LexerDFA *dfa) {
    // Initialize transition table, character classification table, acceptance table
    // ...
}

int getNextState(LexerDFA *dfa, int currentState, int charClass) {
    // Retrieve the next state from the transition table
    // ...
}

int isCharUsed(int charClass) {
    // Check if the character is used based on the character classification table
    // ...
}

int isAcceptanceState(LexerDFA *dfa, int state) {
    // Check if the state is an acceptance state based on the acceptance table
    // ...
}

// Other lexer logic implementation
// ...

// lexer.c

#include "lexer.h"
#include "error.h"  // We'll define error handling here

TokenType determineTokenClass(char currentChar) {
    // TODO: Implement logic to determine the token class based on the character
    // You would define your logic here based on the language's lexical rules
    // Return the appropriate TokenType based on the character

    // Placeholder example: assuming simple tokens for demonstration
    switch (currentChar) {
        case '+':
            return PLUS;
        case '-':
            return MINUS;
        // ... add more cases for other characters
        default:
            return UNKNOWN;
    }
}

// lexer.c

// lexer.c

#include "lexer.h"
#include "error.h"

typedef struct {
    char *pattern;
    TokenType tokenType;
} TokenPattern;

// Define token patterns and their corresponding types
TokenPattern tokenPatterns[] = {
    {"ELSE", ELSE},
    {"IF", IF},
    {"INT", INT},
    {"RETURN", RETURN},
    {"VOID", VOID},
    {"WHILE", WHILE},
    // Add more patterns for reserved words and special symbols as needed
};

#define NUM_TOKEN_PATTERNS (sizeof(tokenPatterns) / sizeof(tokenPatterns[0]))

TokenType determineTokenClass(char *lexeme) {
    // TODO: Implement logic to determine the token class based on the lexeme
    // You would define your logic here based on the language's lexical rules
    // Return the appropriate TokenType based on the lexeme

    // Placeholder example: assuming simple tokens for demonstration
    int i;
    for (i = 0; i < NUM_TOKEN_PATTERNS; i++) {
        if (strcmp(lexeme, tokenPatterns[i].pattern) == 0) {
            return tokenPatterns[i].tokenType;
        }
    }

    // Return UNKNOWN for unknown or unmatched lexemes
    return UNKNOWN;
}


char getNextChar(Buffer *buffer) {
    // Implementation to get the next character from the buffer
    char currentChar = buffer->data[buffer->position];
    buffer->position++;

    // TODO: Implement error handling for invalid characters or other errors
    if (currentChar == '\0') {
        // Handle end of buffer or unexpected EOF
        // Log an error or take appropriate action
    }

    // TODO: Implement logic to determine the token class based on the character or lexeme
    // Use the DFA and transition table to recognize tokens and update lexer state
    // Create tokens and handle errors based on the lexer output
    // ...

    // Placeholder example: assuming simple token recognition
    char lexeme[MAX_LEXEME_LENGTH]; // Assuming you have a maximum lexeme length
    int lexemeLength = 0;
    lexeme[lexemeLength++] = currentChar;

    // Determine token class based on the lexeme
    TokenType tokenType = determineTokenClass(lexeme);

    // TODO: Handle multi-character tokens and complete token recognition based on token type
    // This is where you'd accumulate characters to form complete tokens

    return currentChar;
}




 while (1) 
    {
        // Fill the buffer with a line of source code
        fillBuffer(input_file, &buffer);

        // Check if EOF or an error occurred
        if (buffer.data[0] == '\0')
            break;

        while (buffer.data[buffer.position] != '\0') 
        {
            // Get the next character from the buffer
            char currentChar = getNextChar(&buffer);

            // Determine its character class (e.g., digit, letter, special symbol)
            // Use the DFA and transition table to recognize tokens and update lexer state
            // Handle multi-character tokens and complete token recognition based on token type
            // This is where you'd accumulate characters to form complete tokens

            // Print the character for demonstration purposes
            printf("%c", currentChar);
        }
    }

    // TODO: Implement token recognition and handling for multi-character tokens
    // Handle token recognition and complete token formation based on token type
    // Update lexer state and create tokens accordingly

    // Close the input file
    fclose(input_file);

    // TODO: Add code for the rest of the compiler stages (parser, code generation, etc.)
    // ...







    // utilities.c
#include <stdio.h>
#include "utilities.h"
#include "buffer.h"
#include "lexer.h"
#include "error.h"

void lexProcessSourceCode(FILE *inputFile) {
    Buffer buffer;
    buffer.line = 0;

    while (1) {
        fillBuffer(inputFile, &buffer);

        // Check if EOF or an error occurred
        if (buffer.data[0] == '\0')
            break;

        while (buffer.data[buffer.position] != '\0') {
            char currentChar = getNextChar(&buffer);

            // Determine its character class and process accordingly
            // Use functions from lexer.c for token recognition
            // Handle errors using functions from error.c
        }
    }

    // TODO: Implement token recognition and handling for multi-character tokens
    // Handle token recognition and complete token formation based on token type
    // Update lexer state and create tokens accordingly
}

*/