#include <bits/stdc++.h>
using namespace std;
const int MAX_BAD_GUESS = 7;
const string FIGURE[] = {
" ------------- \n"
" | \n"
" | \n"
" | \n"
" | \n"
" | \n"
" ----- \n",            
" ------------- \n"
" |           | \n"
" | \n"
" | \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |           | \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |          /| \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |          /|\\ \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |          /|\\ \n"
" |           | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |          /|\\ \n"
" |           | \n"
" |          /\n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |          /|\\ \n"
" |           | \n"
" |          / \\ \n"
" | \n"
" ----- \n"
};  
char playagain;
string chooseWord(){
    ifstream file("word.txt");
    string line;
    vector<string> Word_List;
    if (file.is_open()) {
        while (!file.eof()){
            getline(file, line);
            istringstream ss(line);
            string word;
            while (ss >> word) {
                Word_List.push_back(word);
            }
        }
        file.close();
    } else {
        cerr << "Unable to open file for reading." << endl;
    }
    srand((time(0)));
    return Word_List[rand()% Word_List.size()];
}

void renderGame(string guessedWord,int badGuessCount){
    cout << FIGURE[badGuessCount]<<endl;
    cout << guessedWord <<endl;
    cout << "Number of wrong guesses: " << badGuessCount <<endl;
    if(badGuessCount != MAX_BAD_GUESS)cout <<"Your guess: ";
}

bool contains(string secretWord, char guess){
    return secretWord.find(guess)!= string::npos; //ok
}

string update(string gussedWord, string secretWord,char guess){
    if(contains(secretWord,guess)) 
     for(int i = 0; i < gussedWord.length();i++)
      if(secretWord[i] == guess) 
       gussedWord[i] = guess;
    return gussedWord;
}

char readAGuess(){
    char guess; cin >> guess; return guess;
}
string getNextHangman() 
{
    static int LEN = 4;
    static string FIGURES[] = {
          "   ------------+    \n" 
          "   |          /     \n"     
          "   |         O      \n"      
          "   |        /|\\    \n" 
          "   |        / \\    \n" 
          "   |        \n" 
          " -----      \n" ,
          "   ------------+     \n" 
          "   |           |     \n"     
          "   |           O     \n"      
          "   |          /|\\   \n" 
          "   |           |     \n"
          "   |          / \\   \n" 
          "   |        \n" 
          " -----      \n",  
          "   ------------+      \n" 
          "   |            \\    \n"     
          "   |            O     \n"      
          "   |           /|\\   \n" 
          "   |           / \\   \n" 
          "   |      \n" 
          " -----    \n",   
          "   ------------+     \n" 
          "   |           |     \n"     
          "   |           O     \n"      
          "   |          /|\\   \n" 
          "   |          / \\   \n" 
          "   |        \n" 
          " -----      \n",  
          };
    static int i = 0;
    i = (i + 1) % LEN;

    return FIGURES[i];
}

string getNextStandingman() 
{
    static int LEN = 8;
    static string FIGURES[] = {
          "     O     \n"    
          "    /|\\   \n" 
          "    | |    \n", 
          "     O     \n"    
          "    /|\\   \n" 
          "    / \\   \n", 
          "   __O__   \n"    
          "     |     \n" 
          "    / \\   \n", 
          "    \\O/   \n" 
          "     |     \n" 
          "    / \\   \n", 
          "   __O__   \n"     
          "     |     \n" 
          "    / \\   \n", 
          "     O     \n"      
          "    /|\\   \n" 
          "    / \\   \n" ,
          "    O     \n"      
          "    /|\\   \n" 
          "    / \\   \n" ,
          "     O     \n"      
          "    /|\\   \n" 
          "    / \\   \n" ,
          "      O     \n"      
          "    /|\\   \n" 
          "    / \\   \n" ,
          "     O     \n"      
          "    /|\\   \n" 
          "    / \\   \n" ,
          };
    static int i = 0;
    i = (i + 1) % LEN;

    return FIGURES[i];
}

signed main(){
    //1.0
    do{
        srand(time(0));
        string secretWord = chooseWord();
        string guessedWord = string(secretWord.length(),'-');
        int badGuessCount = 0;
        do{
            renderGame(guessedWord,badGuessCount);
            char guess = readAGuess();
            if(contains(secretWord,guess)) guessedWord = update(guessedWord,secretWord, guess);
            else badGuessCount++;
        } while (badGuessCount < MAX_BAD_GUESS && secretWord != guessedWord);
        renderGame(guessedWord,badGuessCount);
        if(badGuessCount <MAX_BAD_GUESS)cout << "Congratulations! You win!\n";
        else cout << "You lost! The correct word is: "<< secretWord <<endl;
        cout << "Do you wanna play more ?\n Y/N ";
        cin >> playagain;
    }while(playagain == 'y' || playagain =='Y');

    if(playagain == 'n'|| playagain == 'N') cout << "Thanks for playing!\n";
    return 0;
   
}
    