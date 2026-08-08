#include <string>
#include <iostream>
#include <cctype>
#include <vector>
using namespace std;
enum enWhatToCount {SmallLeters = 0 , CapitalLetters = 1, All = 2};

namespace StrLib
{
    string ReadString(string Message){
        string Str;
        cout << Message << endl;
        getline(cin , Str);
        return Str;
    }
    void PrintFirstPrintFirstLetterFromAllWords(string Str){
    cout << "First letter from all words in your text: " << endl;
    bool isFirstLetter = true;
    for (int i = 0; i < Str.length(); i++)
    {
        if (Str[i] != ' ' && isFirstLetter)
        {
            cout << Str[i] << endl;
        }
        isFirstLetter = (Str[i] == ' ' ? true : false);
    }
    }
    string UpperFirstFromAllWords(string &Str){
    bool isFirstLetter = true;
    for (int i = 0; i < Str.length(); i++)
    {
        if (Str[i] != ' ' && isFirstLetter)
        {
            Str[i] = tolower(Str[i]);
        }
        isFirstLetter = (Str[i] == ' ' ? true : false);
    }
    return Str;
    }
    string UpperAllString(string &Str){
    for (int i = 0; i < Str.length(); i++)
    {

            Str[i] = toupper(Str[i]);
    }
    return Str;
    }
    string LowerAllString(string &Str){
   for (int i = 0; i < Str.length(); i++)
    {

            Str[i] = tolower(Str[i]);
    }
    return Str;
    
    }
    char invertedCharCase(char ch){
    return (isupper(int(ch)) ? tolower(ch) : toupper(ch));
    }    
    string invertedAllStringCase(string &S1){
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = invertedCharCase(S1[i]);
    }
    return S1;
    }
    int countCapitalLetters(string &S1){
    int countCapital = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (isupper(S1[i]))
        {
            countCapital++;
        }
        
    }
    return countCapital;
    }
    int countSmallLetters(string &S1){
    int countSmall = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (islower(S1[i]))
        {
            countSmall++;
        }
        
    }
    return countSmall;
    }
    int CountLetters(string S1 , enWhatToCount WhatToCount = enWhatToCount::All){
    if (WhatToCount == enWhatToCount::All)
    {
        return S1.length();
    }
    int count = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
        {
            count++;
        }
        if (WhatToCount == enWhatToCount::SmallLeters && islower(S1[i]))
        {
            count++;
        }
        
    }
    return count;
    }
    int CountLetter(string S1 , char ch , bool MatchCase = true){
    int count = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (MatchCase == true && S1[i] == ch)
        {
            count++;
        }
        if (MatchCase == false && tolower(S1[i]) == tolower(ch))
        {
            count++;
        }
        
    }
    return count;
        }
    char ReadCharToSeeCount(string Message){
        char ch;
        cout << Message << endl;
        cin >> ch;    
        return ch;
    } 
    bool IsVowel(char C1){
    C1 = tolower(C1);
    return ((C1== 'a') || (C1 == 'e') || (C1 == 'i') || (C1 == 'o') || (C1 == 'u'));
    } 
    int countvowels(string S1){
    short count = 0;
    for (int i = 0; i < S1.length(); i++)
    {
        if (StrLib::IsVowel(S1[i]))
        {
            count++;
        }
        
    }
    return count;
    } 
    void PrintAllvowelsinString(string S1){
    cout << "All vowels in This String:" << endl;
    for (int i = 0; i < S1.length(); i++)
    {
        if (StrLib::IsVowel(S1[i]))
        {
            cout << S1[i] << "  ";
        }
        
    }
    cout << endl;
    } 
    void PrintAllWordsOfStrings(string S1 , string delim){
    
    int pos = 0;
    string sWord;
    while ((pos = S1.find(delim)) != string::npos)
    {
        sWord = S1.substr(0 , pos);
        if (sWord != "")
        {
            cout << sWord << endl;
        }
        
        
        S1.erase(0 , pos + delim.length());
    }
    if (S1 != "")
        {
            cout << S1 << endl;
        }
    
    } 
    short countWordOnString(string S1 , string delim){
    short count = 0;
    int pos = 0;
    string sWord;
    while ((pos = S1.find(delim)) != string::npos)
    {
        sWord = S1.substr(0 , pos);
        if (sWord != "")
        {
            count++;
        }
        
        
        S1.erase(0 , pos + delim.length());
    }
    if (S1 != "")
        {
            count++;
        }
    return count;
    } 
    vector<string> FillvectorsWithStringWords(string S1 , string delim){
    std::vector<string> vWords; 
    int pos = 0;
    string sWord;
    while ((pos = S1.find(delim)) != string::npos)
    {
        sWord = S1.substr(0 , pos);
        if (sWord != "")
        {
            vWords.push_back(sWord);
        }
        
        
        S1.erase(0 , pos + delim.length());
    }
    if (S1 != "")
        {
            vWords.push_back(S1);
        }
    return vWords;
    } 
    string TrimLeft(string S1){
    for (int i = 0; i < S1.length(); i++)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(i , S1.length() - 1);
        }
        
    }
        return " ";
    
} 
    string TrimRight(string S1){
    short spaces = 0;
    for (int i = S1.length() - 1; i >= 0; i--)
    {
        if (S1[i] != ' ')
        {
            return S1.substr(0 , i + 1);
        }
        
    }
        return " ";
    
}
    string Trim(string &S1){
   return TrimLeft(TrimRight(S1));
}
    string JoinString(std::vector<string>Vtokens , string Delim ,  string S1 = ""){
    for (string &i : Vtokens)
    {
        S1.append(i);
        S1.append(Delim);
    }
    return S1.substr(0 , S1.length() - Delim.length());
}
    string JoinStringusingArray(string arrtokens[] , string Delim , int arrlenght , string S1 = ""){
    for (int i = 0; i < arrlenght; i++)
    {
        S1.append(arrtokens[i]);
        if (i < arrlenght - 1)
        {
            S1.append(Delim);
        }
        
    }
    return S1;
}
    string ReverseWordsInString(string S1 , string Delim){
    std::vector<string> ReverseWords =  StrLib::FillvectorsWithStringWords(S1 , Delim);
    std::vector<string>::iterator iter = ReverseWords.end();
    string S2 = "";
    while (iter != ReverseWords.begin())
    {
        iter--;
        S2 += *iter + Delim;
    }
    
    return S2;
} 
    string ReplaceWord(string S1 , string wordToreplace , string newWord){
    int pos = 0;
    while ((pos = S1.find(wordToreplace)) != std::string::npos)
    {
        S1.replace(pos , wordToreplace.length() , newWord);
    }
    
    return S1;
} 
    string ReplaceWordv2(string &S1 , string wordToreplace , string newWord , bool MatchCase = false){
    std::vector<string> vWords = StrLib::FillvectorsWithStringWords(S1 , " ");
    for (string &s : vWords)
    {
        if (MatchCase)
        {
            if (s == wordToreplace)
            {
                s = newWord;
            }
        }
        else
            {
                if (StrLib::LowerAllString(s) == StrLib::LowerAllString(wordToreplace))
                {
                    s = newWord;
                }
                
            }
            
        
        
    }
    
    
    return StrLib::JoinString(vWords , " ");
} 

}