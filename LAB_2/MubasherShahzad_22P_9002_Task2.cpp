#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <stdlib.h>

using namespace std;
int main()
{
    // declaring string and character datatypes two variables a and x
    string a;
    char x;
    cout << "Enter a string: ";
    cin >> a;
    int len = a.length();
    // displaying menu
    cout << "Menu:\n";
    do
    {
        cout << "A) Count the number of vowels in the string" << endl;
        cout << "B) Count both the vowels and consonants in the string" << endl;
        cout << "C) Display the most frequent character in the string" << endl;
        cout << "D) Concatenate another string with the existing string" << endl;
        cout << "E) Exit the program." << endl;
        cout << "Enter the option:" << endl;
        cin >> x;
        // condition to check the number of vowels in a string
        if (x == 'A' || x == 'a')
        {
            int count = 0;
            for (int i = 0; i < len; i++)
            {
                if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
                {
                    count++;
                }
            }
            cout << "The number of vowels in a string are:" << count << endl;
        }

        // condition to check the number of consonents in a string
        if (x == 'B' || x == 'b')
        {
            int count = 0;
            for (int i = 0; i < len; i++)
            {
                if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
                {
                    count++;
                }
            }
            cout << "The number of vowels in a string are:" << count << endl;
            cout << "The number of consonents in a string are:" << len - count << endl;
            cout << "Total length of characters. " << len << endl;
        }

        // condition to check most frequent character in a string
        if (x == 'C' || x == 'c')
        {
            int sum = 0;
            char word;
            for (int i = 0; i < len; i++)
            {
                int count = 0;
                for (int j = 0; j < len; j++)
                {
                    if (a[i] == a[j])
                    {
                        count++;
                    }

                    if (count > sum)
                    {
                        sum = count;
                        word = a[i];
                    }
                }
            }

            cout << "Most frequent word. " << word << endl;
        }

        // condition for concatenating new string to the previous one
        if (x == 'D' || x == 'd')
        {
            string b;
            cout << "Enter a another string:";
            cin >> b;
            string result = a + b;
            cout << "Concatenated string. " << result << endl;
        }
        // condition to exit the program
        if (x == 'E' || x == 'e')
        {
            break;
        }

    }

    while (1);

    return 0;
}
