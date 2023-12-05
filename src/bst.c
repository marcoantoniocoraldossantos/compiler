#include "libraries.h"

// all the reserved words
char* reserved_words[] = 
{
    "else", "if", "int", "return", "void", "while"
};

// function to find the optimal reserved word to be the root of the bst
char *find_optimal_root()
{
    if (reserved_words == NULL || reserved_words[0] == NULL) 
    {
        return NULL; //if there are no reserved words
    }

    printf("\n");
    int num_words = 0;
    int sum_ascii = 0;

    // find the average ascii value of the first letter of each word
    for (int i = 0; reserved_words[i] != NULL; i++) 
    {
        if (isalpha(reserved_words[i][0])) 
        {
            sum_ascii += (int)(unsigned char)reserved_words[i][0];
            num_words++;
        }
    }

    if (num_words == 0) 
    {
        return NULL; 
    }

    int average_ascii = sum_ascii / num_words;
    int min_difference = 255; // max ascii value

    char* optimal_root = NULL;

    // find the word with the smallest difference between its first letter's ascii value and the average ascii value
    for (int i = 0; reserved_words[i] != NULL; i++) 
    {
        if (isalpha(reserved_words[i][0])) 
        {
            int word_ascii = (int)(unsigned char)reserved_words[i][0];
            int difference = abs(average_ascii - word_ascii); // absolute value of the difference between the average ascii value and the word's first letter's ascii value

            if (difference < min_difference) 
            {
                min_difference = difference;
                optimal_root = reserved_words[i]; // the word with the smallest difference is the optimal root
            }
        }
    }

    return optimal_root; // return the optimal root  
}

// function toinitialize the bst
bst_node_t* initialize_bst() 
{
    bst_node_t* root = NULL;

    char *optimal_root = find_optimal_root(); // find the optimal root
    //printf("best root is %s\n", optimal_root);

    root = insert_bst_node(root, optimal_root, reserved_word_token_type(optimal_root)); // insert the optimal word as the root
    
    //insert rest of the reserved words
    for(int i = 0; reserved_words[i] != NULL; i++)
    {
        if(strcmp(reserved_words[i], optimal_root) != 0) // if the word is not the optimal root
        {
            root = insert_bst_node(root, reserved_words[i], reserved_word_token_type(reserved_words[i])); // insert the word
        }
    }

    return root;
}

// function to print the bst
void print_bst(bst_node_t* root, int level) 
{
    if (root == NULL) 
    {
        return;
    }

    print_bst(root->right, level + 1);

    for (int i = 0; i < level; i++) 
    {
        printf("   ");
    }

    printf("%s\n", root->lexeme);
    print_bst(root->left, level + 1);
}

// function to insert a node in the bst
bst_node_t* insert_bst_node(bst_node_t* root, char* lexeme, token_type_t token_type) 
{
    if (root == NULL) 
    {
        bst_node_t* new_node = (bst_node_t*)malloc(sizeof(bst_node_t));
        if (new_node == NULL) 
        {
            memory_alocation_error("bst node");
        }

        strcpy(new_node->lexeme, lexeme);
        new_node->token_type = token_type;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    int comparison_result = strcmp(lexeme, root->lexeme);
    //printf("comparison result between %s and %s is %d\n", lexeme, root->lexeme, comparison_result);

    if (comparison_result < 0) 
    {
        root->left = insert_bst_node(root->left, lexeme, token_type);
    } 
    else if (comparison_result > 0) 
    {
        root->right = insert_bst_node(root->right, lexeme, token_type);
    }

    return root;
}

// function to free the bst
void free_bst(bst_node_t* root) 
{
    if (root == NULL) 
    {
        return;
    }

    free_bst(root->left);
    free_bst(root->right);
    
    free(root);
}