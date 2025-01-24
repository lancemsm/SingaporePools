#include <iostream>
#include <cstdlib>
#include <set>
#include <random>
using namespace std;

// Globals
int nBetType = 0;
int nNumberOfRowsToGenerate = 0;
int nNumbersToGeneratePerRow = 0;
string sBetType = "";

// Enums
enum E_TOTO_BET_TYPES {
    Ordinary_Entry = 1,     // Select six numbers, between 1 and 49.
    System_7_Entry = 2,     // Select seven numbers, between 1 and 49.
    System_8_Entry = 3,     // Select eight numbers, between 1 and 49.
    System_9_Entry = 4,     // Select nine numbers, between 1 and 49.
    System_10_Entry = 5,    // Select ten numbers, between 1 and 49.
    System_11_Entry = 6,    // Select eleven numbers, between 1 and 49.
    System_12_Entry = 7,    // Select twelve numbers, between 1 and 49.
    System_Roll = 8         // Select five numbers, between 1 and 49.
};

static int SelectBetType(int bet_type) {

    if (bet_type == 1) {
        sBetType = "Ordinary Entry";
        nNumbersToGeneratePerRow = 6;
    }
    else if (bet_type == 2) {
        sBetType = "System 7 Entry";
        nNumbersToGeneratePerRow = 7;
    }
    else if (bet_type == 3) {
        sBetType = "System 8 Entry";
        nNumbersToGeneratePerRow = 8;
    }
    else if (bet_type == 4) {
        sBetType = "System 9 Entry";
        nNumbersToGeneratePerRow = 9;
    }
    else if (bet_type == 5) {
        sBetType = "System 10 Entry";
        nNumbersToGeneratePerRow = 10;
    }
    else if (bet_type == 6) {
        sBetType = "System 11 Entry";
        nNumbersToGeneratePerRow = 11;
    }
    else if (bet_type == 7) {
        sBetType = "System 12 Entry";
        nNumbersToGeneratePerRow = 12;
    }
    else if (bet_type == 8) {
        sBetType = "System Roll";
        nNumbersToGeneratePerRow = 5;
    }

    return 0;
}

void GenerateRandomNumbers(int row) {

    std::set<int> numbers;

    // Generate one line of random numbers between 1-49
    while (true) {

        // Define range
        int min = 1;
        int max = 49;

        // Initialize a random number generator
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(min, max);

        // Generate random number in the range [min, max]
        int randomValue = distrib(gen);

        numbers.insert(randomValue);

        if (numbers.size() == nNumbersToGeneratePerRow) {
            break;
        }
    }

    // Printing the elements of the set
    std::cout << "[" << row << "]: ";
    for (int x : numbers) {

        int y = *prev(numbers.end());

        if (x != y) {
            std::cout << x << ", ";
        }
        else {
            std::cout << x;
        }
        
    }
    std::cout << std::endl;
}

void Generate(int number_of_rows_to_generate) {
    for (int i = 0; i < number_of_rows_to_generate; i++)
    {
        GenerateRandomNumbers(i);
        cout << "\n";
    }
}

int main() {

    while (true) {

        printf("Enter 1 for Ordinary Entry. \n");
        printf("Enter 2 for System 7 Entry. \n");
        printf("Enter 3 for System 8 Entry. \n");
        printf("Enter 4 for System 9 Entry. \n");
        printf("Enter 5 for System 10 Entry. \n");
        printf("Enter 6 for System 11 Entry. \n");
        printf("Enter 7 for System 12 Entry. \n");
        printf("Enter 8 for System Roll. \n");
        printf("Enter 0 to exit. \n\n");

        printf("Select bet type: ");
        cin >> nBetType;

        if (nBetType == 0) {
            printf("Exiting program..\n\n");
            break;
        }

        SelectBetType(nBetType);
        printf("%s selected. \n\n", sBetType.c_str());

        printf("Number of rows to generate: ");
        cin >> nNumberOfRowsToGenerate;
        printf("%d rows will be generated. \n\n", nNumberOfRowsToGenerate);

        Generate(nNumberOfRowsToGenerate);
    }

    return 0;
}