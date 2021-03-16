#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int count_letters(string theInput);
int count_words(string theInput);
int count_sentences(string theInput);
int letter_total = 0;
int word_total = 0;
int sentence_total = 0;


int main(void)
{
    string the_user_input = get_string("Text: ");
    letter_total = count_letters(the_user_input);
    word_total = count_words(the_user_input);
    sentence_total = count_sentences(the_user_input);

    float L = ((float)letter_total / (float)word_total) * 100.00;
    float S = ((float)sentence_total / (float)word_total) * 100.00;

    // Calculate the reading level score
    int the_index = round((0.0588 * L) - (0.296 * S) - 15.8);

    // Display the Reading level.
    if ((the_index >= 1) && (the_index <= 16))
    {
        printf("Grade %i\n", the_index);
    }
    else
    {
        if ((the_index < 1))
        {
            printf("Before Grade 1\n");
        }
        else
        {
            printf("Grade 16+\n");
        }
    }

}



// determine how many letters are in the input string
int count_letters(string theInput)
{
    int character_counter = 0;
    int letter_counter = 0;
    while (theInput[character_counter] != '\0')
    {
        if (((int)theInput[character_counter] >= 65 && (int)theInput[character_counter] <= 90) || ((int)theInput[character_counter] >= 97
            && (int)theInput[character_counter] <= 122))
        {
            letter_counter++;
        }
        character_counter++;
    }
    return letter_counter;
};

// determine how many words are in the input string
int count_words(string theInput)
{
    int character_counter = 0;
    int word_counter = 1;
    int test_character;
    bool beginig_of_word_found = true;
    bool end_of_word_found = false;
    while (theInput[character_counter] != '\0')
    {
        test_character = (int)theInput[character_counter];

        if (!beginig_of_word_found && end_of_word_found && isalpha(test_character))
        {
            word_counter++;
            beginig_of_word_found = true;
            end_of_word_found = false;
        }
        if (beginig_of_word_found && isblank(test_character))
        {
           end_of_word_found = true;
           beginig_of_word_found = false;
        }
        character_counter++;
    }
    return word_counter;
};

// determine how many sentences are in the input string
int count_sentences(string theInput)
{
    int character_counter = 0;
    int sentence_counter = 0;
    int test_character;
    while (theInput[character_counter] != '\0')
    {
        test_character = (int)theInput[character_counter];
        if ((test_character == 33) || (test_character == 46) || (test_character == 63))
        {
            sentence_counter++;
        }
        character_counter++;
    }
    return sentence_counter;
};