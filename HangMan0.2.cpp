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
string Word_List[]={"angle", "ant", "apple", "arch", "arm", "army",
                    "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
                    "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
                    "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
                    "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
                    "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
                    "cow", "cup", "curtain", "cushion",
                    "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
                    "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
                    "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
                    "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
                    "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
                    "leaf", "leg", "library", "line", "lip", "lock",
                    "map", "match", "monkey", "moon", "mouth", "muscle",
                    "nail", "neck", "needle", "nerve", "net", "nose", "nut",
                    "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
                    "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
                    "rail", "rat", "receipt", "ring", "rod", "roof", "root",
                    "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
                    "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
                    "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
                    "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
                    "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
                    "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm"};
int sizeOfList = sizeof(Word_List) / sizeof(Word_List[0]);
string chooseWord(){
    
    return Word_List[rand()% sizeOfList];
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
        } while (badGuessCount < MAX_BAD_GUESS && secretWord |= guessedWord);
        renderGame(guessedWord,badGuessCount);
        if(badGuessCount <MAX_BAD_GUESS)cout << "Congratulations! You win!\n";
        else cout << "You lost! The correct word is: "<< secretWord <<endl;
        cout << "Do you wanna play more ?\n Y/N ";
        cin >> playagain;
    }while(playagain == 'y' || playagain =='Y');

    if(playagain == 'n'|| playagain == 'N') cout << "Thanks for playing!\n";
    return 0;
   
}
    