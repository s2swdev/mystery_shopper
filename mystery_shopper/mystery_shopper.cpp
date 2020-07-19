// mystery_shopper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int checkWinner(vector<vector<string>> codeList, vector<string> shoppingCart)
{
    // Insert code here
    int currentCartIndex = 0;
    int currentCartIndexFinal = 0;

    cout << "codeList size: " << codeList.size() << endl;

    for (int i = 0; i < codeList.size(); i++)
    {
        currentCartIndexFinal = currentCartIndex;
        for (int j = 0; j < codeList[i].size(); j++)
        {
            if (codeList[i][j] == shoppingCart[currentCartIndex] || codeList[i][j] == "anything")
            {
                cout << "Matched: " << codeList[i][j] << shoppingCart[currentCartIndex] << endl;
                currentCartIndex++;
            }
            else
            {
                cout << "Not matched: " << codeList[i][j] << shoppingCart[currentCartIndex] << endl;
                currentCartIndex = currentCartIndexFinal;
            }
        }
    }

    if (currentCartIndex == shoppingCart.size())
        return 1;
    else
        return 0;
}

int main()
{
    vector<vector<string> > prize{ { "orange" },
                               { "orange", "anything", "apple" },
                               { "anything", "orange", "apple" } };

    vector<string> cart{ "orange", "orange", "orange", "bannana", "orange", "orange", "apple" };

    int winner;
    winner = checkWinner(prize, cart);
    cout << "Winner: " << winner << endl;
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
