#include "libraries.h"

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

// function to initialize the token list
token_list_t* lexical_analyzer(FILE *source_code_file)
{
    token_list_t *token_list = initialize_token_list();
    buffer_t buffer = allocate_buffer(256);
    bst_node_t *bst_root = NULL;
    bst_root = initialize_bst();
    //print_bst(bst_root, 0);

    //variables used
    char current_char;
    state_t new_state, current_state = ST_SRT;
    token_t *current_token;
    int lexeme_count = 0;
    bool error_found = false;

    while (fill_buffer(source_code_file, &buffer)) 
    {   
        //print_buffer(&buffer);
        do
        {   
            current_state = ST_SRT;
            current_token = initialize_token();

            current_char = buffer.data[buffer.position];

            current_token->line = buffer.line;

            while (!accept_table[current_state])
            {
                new_state = transition_table[current_state][get_char_type(current_char)];

                //printf("char %c, state %s, new state %s\n", current_char, state_to_string(current_state), state_to_string(new_state));

                if(new_state == ST_ERR)
                {
                    current_token->lexeme[lexeme_count] = current_char;
                    current_token->lexeme[lexeme_count + 1] = '\0';
                    
                    //pass all the buffer
                    if(strlen(current_token->lexeme) > 0)
                    {
                        lex_error(current_token, buffer, current_token->line, buffer.position);

                        //keep going but save the error
                        error_found = true;
                    
                        //stop the program
                        //exit(0);
                    }
                
                    
                    advance_input_buffer(&buffer);
                    lexeme_count = 0;
                    free_token(current_token);

                    break;
                }

                //printf("char %c, state %s, new state %s\n", current_char, state_to_string(current_state), state_to_string(new_state));
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
                        //printf("char %c, state %s, new state %s\n", current_char, state_to_string(current_state), state_to_string(new_state));
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
                //printf("line: %d, token: , lexeme: \'%s\'\n", current_token->line, current_token->lexeme);
                
                current_token->type = identify_lexeme(bst_root, current_token->lexeme);
                if(strlen(current_token->lexeme) > 0)
                    add_token_to_list(token_list, current_token);
                
                lexeme_count = 0;
                free_token(current_token);
            }

        } while (current_char != '\n' && current_char != '\0');
        
        //print_buffer(&buffer);
    }

    deallocate_buffer(&buffer);
    free_bst(bst_root);

    if(error_found)
    {
        return NULL;
    }

    return token_list;
}

char *state_to_string(state_t state)
{
    if(state == ST_SRT)
    {
        return "ST_SRT";
    }
    else if(state == ST_ID)
    {
        return "ST_ID";
    }
    else if(state == ST_NUM)
    {
        return "ST_NUM";
    }
    else if(state == ST_CMP)
    {
        return "ST_CMP";
    }
    else if(state == ST_NE)
    {
        return "ST_NE";
    }
    else if(state == ST_ENC)
    {
        return "ST_ENC";
    }
    else if(state == ST_INC)
    {
        return "ST_INC";
    }
    else if(state == ST_EXC)
    {
        return "ST_EXC";
    }
    else if(state == ST_ERR)
    {
        return "ST_ERR";
    }
    else if(state == ST_END)
    {
        return "ST_END";
    }
}

char_t get_char_type(char c) 
{
    if (isspace(c))
    {
        return CHAR_SPACE;
    } 
    else if (isalpha(c)) 
    {
        return CHAR_LETTER;
    } 
    else if (isdigit(c)) 
    {
        return CHAR_DIGIT;
    } 
    else if (c == '+')
    {
        return CHAR_PLUS;
    }   
    else if (c == '-')
    {
        return CHAR_MINUS;
    } 
    else if (c == '*')
    {
        return CHAR_ASTERISK;
    } 
    else if (c == '/')
    {
        return CHAR_SLASH;
    } 
    else if (c == '<')
    {
        return CHAR_LESS_THAN;
    } 
    else if (c == '>')
    {
        return CHAR_GREATER_THAN;
    } 
    else if (c == '!')
    {
        return CHAR_EXCLAMATION;
    } 
    else if (c == '=')
    {
        return CHAR_EQUALS;
    } 
    else if (c == ';')
    {
        return CHAR_SEMICOLON;
    } 
    else if (c == ',')
    {
        return CHAR_COMMA;
    } 
    else if (c == '(')
    {
        return CHAR_LPAREN;
    } 
    else if (c == ')')
    {
        return CHAR_RPAREN;
    } 
    else if (c == '{')
    {
        return CHAR_LBRACE;
    } 
    else if (c == '}')
    {
        return CHAR_RBRACE;
    } 
    else if (c == '[')
    {
        return CHAR_LBRACKET;
    } 
    else if (c == ']')
    {
        return CHAR_RBRACKET;
    } 
    else 
    {
        return CHAR_OTHER;
    }
}