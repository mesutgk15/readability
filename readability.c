#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);
float calculate_index(float letters, float words, float sentences);
float index;
int index_result;
int letter_counter = 0;
int word_counter = 1;
int sentence_counter = 0;

//count letters, words and sentences for the input text which will be prompted from user and calculate The Coleman-Liau index
//a readability grade result will be printed accordingly
int main(void)
{

    string text = get_string("Text: ");
    printf("%s\n", text);
    count_letters(text);
    count_words(text);
    count_sentences(text);
    calculate_index(letter_counter, word_counter, sentence_counter);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index_result);
    }

}

float count_letters(string text)
{
    int length = strlen(text);
    for (int i = 0; i <= length; i++)
    {
        if (isalpha(text[i]))
        {
            letter_counter += 1;
        }

    }
    return letter_counter;
}

float count_words(string text)
{
    int length = strlen(text);
    for (int i = 1; i < length - 1; i++)
    {
        if (isspace(text[i]))
        {
            word_counter += 1;
        }

    }
    return word_counter;
}

float count_sentences(string text)
{
    int length = strlen(text);
    for (int i = 1; i < length; i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentence_counter += 1;
        }
    }
    return sentence_counter;
}

//calculate The Coleman-Liau index as float and assign index_result as integer to be displayed
float calculate_index(float letters, float words, float sentences)
{
    index = round((0.0588 * ((letters / words) * 100)) - (0.296 * ((sentences / words) * 100)) - 15.8);
    index_result = index;
    return 0;
}