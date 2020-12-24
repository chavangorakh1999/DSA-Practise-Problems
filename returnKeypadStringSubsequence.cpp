#include <iostream>
#include <string>
using namespace std;

const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void  printWordsUtil(int inputArr[], int current_digit, char result[], int n)
{
    int i;
    if (current_digit == n)
    {
        cout << result << " ";
        return;
    }

    for ( i = 0; i < strlen(hashTable[inputArr[current_digit]]); i++)
    {
        result[current_digit] = hashTable[inputArr[current_digit]][i];
         printWordsUtil(inputArr, current_digit + 1, result, n);
        if (inputArr[current_digit] == 0 || inputArr[current_digit] == 1)
            return;
    }
}


void printWord(int *inputArray, int n)
{
    char result[n + 1];
    result[n] = '\0';
    printWordsUtil(inputArray, 0, result, n);
}

int main()
{
    int n;
    cin >> n;
    int inputArr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> inputArr[i];
    }
    printWord(inputArr, n);
    return 0;
}