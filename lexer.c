#include "lexer.h"

// state_t table to indicate the next state given the current state and the current character class
state_t transition_table[NUM_STATES][NUM_CHAR_CLASSES] = 
{   //space, letter,  digit,      +,      -,      *,      /,      <,      >,      =,      !,      ;,      ,,      (,      ),      [,      ],      {,      },  other
    {ST_SRT, ST_ID , ST_NUM, ST_END, ST_END, ST_END, ST_ENC, ST_CMP, ST_CMP, ST_CMP,  ST_NE, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_ERR}, // ST_SRT
    {ST_END, ST_ID , ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_ID
    {ST_END, ST_END, ST_NUM, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_NUM
    {ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END , ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END, ST_END}, // ST_CMP
    {ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_END, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR, ST_ERR}, // ST_NE
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
    {false, false , false, false, false, false, false, false, false, true , false, false, false, false, false, false, false, false, false, false}, // ST_CMP
    {false, false , false, false, false, false, false, false, false, true , false, false, false, false, false, false, false, false, false, false}, // ST_NE
    {false, false , false, false, false, true , false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_ENC
    {true , true  , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true }, // ST_INC
    {true , true  , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true , true }, // ST_EXC
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}, // ST_ERR
    {false, false , false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}  // ST_END
};

// boolean array to indicate which states are accepting states
bool accept_table[NUM_STATES] = 
{
    false, false, false, 
    false, false, false, 
    false, false, false, 
    true
};

// function to tokenize the source code file
token_list_t* lexical_analyzer(FILE *source_code_file)
{
    //initialize the token list, buffer and bst
    token_list_t *token_list = initialize_token_list();
    buffer_t buffer = allocate_buffer(256);
    bst_node_t *bst_root = initialize_bst();

    //variables to keep track of the current character, state, token and lexeme count
    char current_char;
    state_t current_state, new_state;
    token_t *current_token;

    //variable to keep track of the number of characters in the lexeme
    int lexeme_count = 0;

    //variable to indicate if an error was found
    bool error_found = false;

    while (fill_buffer(source_code_file, &buffer)) 
    {   
        do
        {   
            current_state = ST_SRT;
            current_token = initialize_token();

            current_char = buffer.data[buffer.position];

            current_token->line = buffer.line;

            while (!accept_table[current_state])
            {
                new_state = transition_table[current_state][get_char_type(current_char)];

                if(new_state == ST_ERR)
                {
                    current_token->lexeme[lexeme_count] = current_char;
                    current_token->lexeme[lexeme_count + 1] = '\0';
                    
                    if(strlen(current_token->lexeme) > 0)
                    {
                        lex_error(current_token, buffer, current_token->line, buffer.position);

                        error_found = true;
                    
                        //stop the program
                        //exit(0);
                    }
                
                    advance_input_buffer(&buffer);
                    lexeme_count = 0;
                    free_token(current_token);

                    break;
                }

                if(new_state == ST_INC)
                {
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
                current_token->type = identify_lexeme(bst_root, current_token->lexeme);
                if(strlen(current_token->lexeme) > 0)
                {
                    add_token_to_list(token_list, current_token);
                }
                     
                lexeme_count = 0;
                free_token(current_token);
            }

        } while (current_char != '\n' && current_char != '\0');
    }

    deallocate_buffer(&buffer);
    free_bst(bst_root);

    if(error_found)
    {
        return NULL;
    }

    return token_list;
}