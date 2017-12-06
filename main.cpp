#include <iostream>
#include <QDebug>

bool isVowel(const char &c)
{
    bool _isVowel =
            c == 'a' || c == 'A' ||
            c == 'e' || c == 'E' ||
            c == 'i' || c == 'I' ||
            c == 'o' || c == 'O' ||
            c == 'y' || c == 'Y' ||
            c == 'u' || c == 'U';
    return _isVowel;
}


// Index version
void deleteVowel(char str[])
{
    int iVowel = 0, iConsonant = 0;
    char temp, temp2;
    while(str[iConsonant] != '\0' &&
          str[iVowel] != '\0')
    {
        while(!isVowel(str[iVowel])) iVowel++;
        iConsonant = iVowel;
        while(isVowel(str[iConsonant])) iConsonant++;
        temp = str[iVowel];
        temp2 = str[iConsonant];
        str[iVowel] = temp2;
        str[iConsonant] = temp;
        iVowel++;
        iConsonant++;
    }

}
// pointer version
void deleteVowelPointer(char str[])
{
    char* iVowel = str;
    char* iConsonant = str;
    char temp, temp2;
    while(*iConsonant != '\0' &&
          *iVowel != '\0')
    {
        while(!isVowel(*iVowel)) iVowel++;
        iConsonant = iVowel;
        while(isVowel(*iConsonant)) iConsonant++;
        temp = *iVowel;
        temp2 = *iConsonant;
        *iVowel = temp2;
        *iConsonant = temp;
        iVowel++;
        iConsonant++;
    }

}

void print(char e[])
{
    std::cout << "Init string:" << e << std::endl;
    deleteVowelPointer(e);
    std::cout << "Final string:" << e <<
                 std::endl << std::endl;
}

int main()
{
    char e[] = "Hello";print(e);
    char p[] = "People";print(p);
    char a[] = "Are"; print(a);
    char g[] = "You"; print(g);
    char w[] = "";print(w);
    char y[] = "Ready";print(y);
    char z[] = "?!";print(z);

    return 0;
}
