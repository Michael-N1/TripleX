#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    std::cout << " _     _  _______  ___      _______  _______  __   __  _______ \n";
    std::cout << "| | _ | ||       ||   |    |       ||       ||  |_|  ||       |\n";
    std::cout << "| || || ||    ___||   |    |       ||   _   ||       ||    ___|\n";
    std::cout << "|       ||   |___ |   |    |       ||  | |  ||       ||   |___ \n";
    std::cout << "|       ||    ___||   |___ |      _||  |_|  ||       ||    ___|\n";
    std::cout << "|   _   ||   |___ |       ||     |_ |       || ||_|| ||   |___ \n";
    std::cout << "|__| |__||_______||_______||_______||_______||_|   |_||_______|\n";

    std::cout << "You are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room.\nEnter the correct codes to win" << std::endl;
}

bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << "+ There are 3 numbers in the code\n";
    std::cout << "\n+ The codes add up to: " << CodeSum;
    std::cout << "\n+ The codes multiply up to: " << CodeProduct << std::endl;

    //Store player guess
    std::cout << "Enter a guess\n";
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the player's guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "Your code was correct. You broke through to the secure room!\n
        You are moving on to the next level. \n\n";
        return true;
    }
    else
    {
        std::cout << "You were wrong.\n You're staying in the current level.\n\n";
        return false;
    }
}

int main() 
{
    srand(time(NULL));
        
    int LevelDifficulty = 1;
    const int MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) //Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();  //Clears any errors
        std::cin.ignore();  //Discards the buffer

        if (bLevelComplete)
        // increase level difficulty
        {
            ++LevelDifficulty;
        }
        
    }
    std::cout << "\nYou have completed the game. CONGRATULATIONS"
    return 0;
}