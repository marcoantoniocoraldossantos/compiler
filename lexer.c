// libraries used
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// include all header files
#include "utilities.h"
#include "buffer.h"
#include "token.h"
#include "lexer.h"
#include "error.h"

// state_t table to indicate the next state given the current state and the current character class
state_t transition_table[NUM_STATES][NUM_CHAR_CLASSES] = 
{   //space, letter,  digit,      +,      -,      *,      /,      <,      >,      =,      !,      ;,      ,,      (,      ),      [,      ],      {,      },  other
    {ST_SRT, ST_ID , ST_NUM, ST_ADD, ST_SUB, ST_MUL, ST_ENC,  ST_LT,  ST_GT,  ST_EQ,  ST_NE, ST_SEM, ST_COM, ST_LPA, ST_RPA, ST_LBK, ST_RBK, ST_LBC, ST_RBC, ST_ERR}, // ST_SRT
    {ST_END, ST_ID , ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_ID
    {ST_END, ST_END, ST_NUM, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_NUM
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_ADD
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_SUB
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_MUL
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_LE , ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_LT
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_GE , ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_GT
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_LE
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_GE
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_ASG, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_EQ
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_ASG
    {ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_END, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR}, // ST_NE
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_SEM
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_COM
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_LPA
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_RPA
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_LBK
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_RBK
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_LBC
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_RBC
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_INC, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_ENC
    {ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_EXC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC}, // ST_INC
    {ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_SRT, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC, ST_INC}, // ST_EXC
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_ERR
    {ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT} // ST_END
};

// boolean to indicate if should advance the input buffer
bool advance_table[NUM_STATES][NUM_CHAR_CLASSES] = 
{  //space, letter, digit,     +,     -,     *,     /,     <,     >,     =,     !,     ;,     ,,     (,     ),     [,     ],     {,     }, other
    {true , true  , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true }, // ST_SRT
    {false, true  , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_ID
    {false, false , true , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_NUM
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_ADD
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_SUB
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_MUL
    {false, false , false, false, false, false, false, false, false, true , false, false, false, false, false, false, false, false, false, false}, // ST_LT
    {false, false , false, false, false, false, false, false, false, true , false, false, false, false, false, false, false, false, false, false}, // ST_GT
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_LE
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_GE
    {false, false , false, false, false, false, false, false, false, true , false, false, false, false, false, false, false, false, false, false}, // ST_EQ
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_ASG
    {false, false , false, false, false, false, false, false, false, true , false, false, false, false, false, false, false, false, false, false}, // ST_NE
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_SEM
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_COM
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_LPA
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_RPA
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_LBK
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_RBK
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_LBC
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_RBC
    {false, false , false, false, false, true , false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_ENC
    {true , true  , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true }, // ST_INC
    {true , true  , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true }, // ST_EXC
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_ERR
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}  // ST_END
};

// boolean array to indicate which states are accepting states
bool accept_table[NUM_STATES] = 
{
    false, false, false, false, false, false, false, false, false, false, 
    false, false, false, false, false, false, false, false, false, false, 
    false, false, false, false, false, true
};

token_list_t* lexical_analyzer(FILE *source_code_file)
{
    token_list_t *token_list = initialize_token_list();
    buffer_t buffer = allocate_buffer(256);

    //variables used
    char current_char;

    while (fill_buffer(source_code_file, &buffer)) 
    {   
        do
        {
            current_char = buffer.data[buffer.position];
            //printf("%c", current_char);
            printf("analisa o char %c\n", current_char);
            advance_input_buffer(&buffer);
        } while (current_char != '\n' && current_char != '\0');
        
        print_buffer(&buffer);
    }

    deallocate_buffer(&buffer);

    return token_list;
}

