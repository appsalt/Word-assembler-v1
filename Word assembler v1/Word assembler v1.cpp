// Word assembler v1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iterator>
#include <vector>

//count the numer of the words letters in the word
//count the numer of the words letters in the letters
/* 
   Devide the number of the words letter in the letters, 
   by the number of the words letter in the word.
   To get the available number of letters
*/



std::vector<int> letterCounts(std::string &letters, std::string &word)
{
    std::vector<int> wordLetterCounts(word.length());

    for (int i{ 0 }; i < (int)word.length(); i++)
    {
        for (std::string::iterator it = letters.begin(); it != letters.end(); it++)
        {
            if (word[i] == *it)
            {
                wordLetterCounts[i]++;
            }
        }
    }

    return wordLetterCounts;
}

void showLetterCounts(std::vector<int> &wordLetterCounts)
{
    std::cout << "\t";
    for (int i{ 0 }; i < (int)wordLetterCounts.size(); i++)
    {
        std::cout << wordLetterCounts[i];
        std::cout << " ";
    }
    std::cout << std::endl;
}

void letterCountCorrector(std::vector<int>& wordLetterCounts, std::vector<int>& wordWordLetterCounts)
{
    for (int i{ 0 }; i < (int)wordLetterCounts.size(); i++)
    {
        wordLetterCounts[i] /= wordWordLetterCounts[i];
    }
}

int limitingLetterCount(std::vector<int> wordLetterCount)
{
    int retur{0};

    for (std::vector<int>::iterator it = wordLetterCount.begin(); it != wordLetterCount.end(); it++)
    {
        if (*it > retur)
        {
            retur = *it;
        }
    }

    return retur;
}


int main()
{
    std::string letters{ "aaapssslllttt" };
    std::string apa{ "apa" }; //should get 1
    std::string salt{ "salt" }; //should get 3

    std::cout << std::endl; std::cout << "The given letters are: "; std::cout << letters; std::cout << std::endl; std::cout << std::endl;


    std::cout << "\t\t";
    for (int i{ 0 }; i < (int)apa.length(); i++)
    {
        std::cout << apa[i];
        std::cout << " ";
    }
    std::cout << std::endl;

    std::vector<int> apaWordLetterCounts(letterCounts(apa, apa));
    std::cout << "in the word:";
    showLetterCounts(apaWordLetterCounts);
    std::vector<int> apaLetterCounts(letterCounts(letters,apa));
    std::cout << "in the letters:";
    showLetterCounts(apaLetterCounts);
    letterCountCorrector(apaLetterCounts, apaWordLetterCounts);
    std::cout << "available:";
    showLetterCounts(apaLetterCounts);
    std::cout << std::endl; std::cout << "We can make ";
    std::cout << limitingLetterCount(apaLetterCounts);
    std::cout << " words of the form \""; std::cout << apa; std::cout << "\"";

    std::cout << std::endl; std::cout << std::endl;
    

    std::cout << "\t\t";
    for (int i{ 0 }; i < (int)salt.length(); i++)
    {
        std::cout << salt[i];
        std::cout << " ";
    }
    std::cout << std::endl;

    std::vector<int> saltWordLetterCounts(letterCounts(salt, salt));
    std::cout << "in the word:";
    showLetterCounts(saltWordLetterCounts);
    std::vector<int> saltLetterCounts(letterCounts(letters, salt));
    std::cout << "in the letters:";
    showLetterCounts(saltLetterCounts);
    letterCountCorrector(saltLetterCounts, saltWordLetterCounts);
    std::cout << "available:";
    showLetterCounts(saltLetterCounts);
    std::cout << std::endl; std::cout << "We can make ";
    std::cout << limitingLetterCount(saltLetterCounts);
    std::cout << " words of the form \""; std::cout << salt; std::cout << "\"";
    

    
    

    std::cout << "\n\nWord assembler\n\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
