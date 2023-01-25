#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<time.h>
#include<vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <random>
using namespace std;

int z = 1;
string l = "ndadadadfa";

string random_word(string test){
    string line;
    vector<string> lines;
    
    srand(time(0));
    
    //input file stream
    ifstream file("words.txt");
    
    //count number of total lines in the file and store the lines in the string vector
    int total_lines=0;
    while(getline(file,line))
    {
       total_lines++; 
    lines.push_back(line);  
  }
   
    //generate a random number between 0 and count of total lines
    int random_number=rand()%total_lines;
    
    
    //fetch the line where line index (starting from 0) matches with the random number
    string word;
    word = lines[random_number];
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

std::string fun2 (std::string user_guess, std::string word)
{
    int num2 = 0;
    while(num2 < 5){
    cout << "\nEnter guess: ";
    cin >> user_guess;
    static int num = 1; // for 1: , 2: and so on
    cout << num << ": ";
        
    if (user_guess == word) {   /* words are equal, all green */
        std::cout << "\033[30;42m" << user_guess << "\033[0m\n";
        num2 = 5;
        return "Success";
    }
    
    /* loop over each char (up to shorter of either string) */
    for (int i = 0; user_guess[i] && word[i]; i++) {
        if (user_guess[i] == word[i]) {   /* chars match, green */
            std::cout << "\033[30;42m" << user_guess[i] << "\033[0m";
        }
        /* current char found elsewhere in word - yellow */
        else if (word.find_first_of (user_guess[i], 0) != std::string::npos) {
            std::cout << "\033[30;103m" << user_guess[i] << "\033[0m";
        }
        else {  /* current char does not exist in word - red */
            std::cout << "\033[30;41m" << user_guess[i] << "\033[0m";
        }
    }
        num2++;
        num++;
        }
    
    return "\nThe word was "+  word;
}

int main(){
    string user_guess = "ap";
    
    cout << "\nW O R D L E";
    cout << "\nUsing words wtih 5 letters\n\n";
    cout << fun2(user_guess, random_word("a"));
    
    
}

