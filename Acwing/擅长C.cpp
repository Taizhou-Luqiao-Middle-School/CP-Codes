#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char g[26][7][6];
bool is_first = true;

void output(string word)
{
    if (word.empty()) return;

    if (is_first) is_first = false;
    else cout << endl;

    char str[7][60] = {0};
    for (int i = 0; i < word.size(); i ++ )
        for (int j = 0; j < 7; j ++ )
            for (int k = 0; k < 5; k ++ )
                str[j][i * 6 + k] = g[word[i] - 'A'][j][k];

    for (int i = 1; i < word.size(); i ++ )
        for (int j = 0; j < 7; j ++ )
            str[j][i * 6 - 1] = ' ';

    for (int i = 0; i < 7; i ++ )
        cout << str[i] << endl;
}

int main()
{
    for (int i = 0; i < 26; i ++ )
        for (int j = 0; j < 7; j ++ )
            cin >> g[i][j];

    string word;
    char c;
    while ((c = getchar()) != -1)
    {
        if (c >= 'A' && c <= 'Z') word += c;
        else
        {
            output(word);
            word = "";
        }
    }

    output(word);

    return 0;
}