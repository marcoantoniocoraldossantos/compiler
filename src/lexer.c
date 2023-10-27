#include "libraries.h"

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
    {ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT, ST_SRT}  // ST_END
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
    {false, false , false, false, false, false, false, false, false, true , false, false, false, false, false, false, false, false, false, false}, // ST_LE
    {false, false , false, false, false, false, false, false, false, true , false, false, false, false, false, false, false, false, false, false}, // ST_GE
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

// function to initialize the token list
token_list_t* lexical_analyzer(FILE *source_code_file)
{
    // initialize the token list, the buffer and the bst
    token_list_t *token_list = initialize_token_list();
    buffer_t buffer = allocate_buffer(256);
    bst_node_t *bst_root = initialize_bst();

    //print_bst(bst_root, 1);

    // variables to control the state machine
    char current_char;
    token_t *current_token;
    state_t previous_state, current_state, new_state;

    // auxiliar variables
    int lexeme_count = 0;

    while (fill_buffer(source_code_file, &buffer)) 
    {   
        do
        {   
            current_state = ST_SRT;
            previous_state = ST_SRT;

            current_token = initialize_token();
            lexeme_count = 0;

            current_char = buffer.data[buffer.position];

            current_token->line = buffer.line;

            while (!accept_table[current_state])
            {
                previous_state = current_state;
                new_state = transition_table[current_state][get_char_type(current_char)];
                
                //printf("char %c, prev state %s, state %s, new state %s\n", current_char, state_to_string(previous_state),state_to_string(current_state), state_to_string(new_state));
                if(new_state == ST_ERR)
                {
                    current_token->lexeme[lexeme_count] = current_char;
                    current_token->lexeme[lexeme_count + 1] = '\0';
                    
                    if(strlen(current_token->lexeme) > 0)
                    {
                        lex_error(current_token, buffer, current_token->line, buffer.position);
                    
                        free_token(current_token);
                        deallocate_buffer(&buffer);
                        free_bst(bst_root);
                        free_token_list(token_list);
                        
                        //stop the program
                        exit(EXIT_FAILURE);
                    }
                
                    advance_input_buffer(&buffer);
                    lexeme_count = 0;

                    free_token(current_token);

                    break;
                }

                if(new_state == ST_INC)
                {
                    lexeme_count = 0;
                    
                    previous_state = current_state;
                    current_state = new_state;
                    while(new_state != ST_SRT)
                    {
                        advance_input_buffer(&buffer);
                        if(buffer.position == buffer.size)
                        {
                            fill_buffer(source_code_file, &buffer);
                        }
                        current_char = buffer.data[buffer.position];
                        new_state = transition_table[current_state][get_char_type(current_char)];
                        previous_state = current_state;
                        current_state = new_state;
                    }
                }

                if (advance_table[current_state][get_char_type(current_char)])
                {
                    if (!isspace(current_char))
                    {
                        current_token->lexeme[lexeme_count] = current_char;
                        lexeme_count++;
                    }

                    advance_input_buffer(&buffer);
                    if(buffer.position == buffer.size)
                    {
                        fill_buffer(source_code_file, &buffer);
                    }
                    current_char = buffer.data[buffer.position];
                }

                current_state = new_state;
                if(current_state == ST_SRT)
                {
                    break;
                }
               
            }
            if (accept_table[current_state])
            {                
                if(previous_state == ST_ID)
                {
                    
                    current_token->type = identify_lexeme(bst_root, current_token->lexeme);
                    if(strlen(current_token->lexeme) > 0)
                    {
                        add_token_to_list(token_list, current_token);
                    }
                }
                else if(previous_state == ST_NUM)
                {
                    current_token->type = NUM;
                    if(strlen(current_token->lexeme) > 0)
                    {
                        add_token_to_list(token_list, current_token);
                    }
                }
                else
                {
                   current_token->type = state_to_token_type(previous_state);
                    if(strlen(current_token->lexeme) > 0)
                    {
                        add_token_to_list(token_list, current_token);
                    }
                }
                
                lexeme_count = 0;
                //free_token(current_token);
            }

            //test memory leak
            advance_input_buffer(&buffer);
            free_token(current_token);

        } while (current_char != '\n' && current_char != '\0');
    }

    deallocate_buffer(&buffer);
    free_bst(bst_root);

    return token_list;
}