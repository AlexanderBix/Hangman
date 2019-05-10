//Default Dictionary File Obtained from: http://www.gwicks.net/dictionaries.htm (English 512Kb version was used)
//This is a singleplayer version of Hangman

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
using namespace std;

//Printing The Hangman
void Graphics(int DeathToll){
  if(DeathToll == 0){
    cout << "    -----|" << endl;
    cout << "    |    " << endl;
    cout << "    |    " << endl;
    cout << "    |    " << endl;
    cout << "  -----  " << endl;
  }
  if(DeathToll == 1){
    cout << "    -----|" << endl;
    cout << "    |    0 " << endl;
    cout << "    |    " << endl;
    cout << "    |    " << endl;
    cout << "  -----  " << endl;
  }
  if(DeathToll == 2){
    cout << "    -----|" << endl;
    cout << "    |    0 " << endl;
    cout << "    |    | " << endl;
    cout << "    |    " << endl;
    cout << "  -----  " << endl;

  }
  if(DeathToll == 3){
    cout << "    -----|" << endl;
    cout << "    |    0 " << endl;
    cout << "    |   /| " << endl;
    cout << "    |    " << endl;
    cout << "  -----  " << endl;

  }
  if(DeathToll == 4){
    cout << "    -----|" << endl;
    cout << "    |    0 " << endl;
    cout << "    |   /|\\ " << endl;
    cout << "    |    " << endl;
    cout << "  -----  " << endl;

  }
  if(DeathToll == 5){
    cout << "    -----|" << endl;
    cout << "    |    0 " << endl;
    cout << "    |   /|\\ " << endl;
    cout << "    |   /" << endl;
    cout << "  -----  " << endl;
  }
  if(DeathToll == 6){
    cout << "    -----|" << endl;
    cout << "    |    0 " << endl;
    cout << "    |   /|\\ " << endl;
    cout << "    |   / \\ " << endl;
    cout << "  -----  " << endl;
  }
  
}

//Counts the amount of words from the text file
int CountWords(){
  int WordCounter = 0;
  ifstream File;
  string cache;
  File.open("dictionary.txt");
  
  if(!File){
    cout << "Error opening dictionary File" << endl;
    return -1;
  }
  else{
    
    while(File >> cache){
      WordCounter++;
    }
    
  }

  //Sets to read file from start
  File.clear();
  File.seekg(0, ios::beg);
  File.close();
  
  return WordCounter;
}

//Stores dictionary words into an array
void StoreWords(int WordCounter, string *Words){
  ifstream File;
  string cache;
  File.open("dictionary.txt");
  int i = 0;

  while(File >> cache){
    Words[i] = cache;
    i++;
  }
  
}

//Picking a word randomly
string PickWord(int WordCounter, string *Words){
  srand(time(NULL));
  int minwords = 0;
  int maxwords = WordCounter;
  int wordrandom (minwords + (rand() %(int)(maxwords - minwords + 1)));
  string WordChosen = Words[wordrandom];
  return WordChosen;
}


//playing
void play(){
  string Word;
  char Guess;
  int DeathToll = 0;
  int numguess = 0;
  int winning = 0;

  
  //Amount of words in dictionary file
  int WordCounter = CountWords();
  string Words[WordCounter];
  
  //Insert words into an array
  StoreWords(WordCounter, Words);
  
    
  //Picking a word randomly
  Word = PickWord(WordCounter, Words);

  //Array used for printing
  string Printing[Word.length()];
  for(int k = 0; k < Word.length(); k++){
    Printing[k] = "_ ";
  }
  
  //Core loop of the program
  while(DeathToll < 6){
      
    //Print Noose
    system("clear");
    Graphics(DeathToll);

    //Word shown: FOR DEBUGGING ONLY
    //cout << Word << endl;
    
    //Printing blank letters and selected letters
    for(int i = 0; i < Word.length(); i++){

      //If guess letter is present
      if(Word[i] == Guess){
	Printing[i] = Guess;
	numguess++;
      }   

      //If the entire word has been found
      if(numguess == Word.length()){
	winning = 1;
      }

      //Print out letter
      if(Printing[i] != "_ "){
	cout << Printing[i] << " ";
      }
      else{
      cout << Printing[i];
      }
      
    }
    
    cout << endl;

    //If player wins
    if(winning == 1){
      cout << "You win!" << endl;
      return;
    }
    
    //Guessing a letter
    cout << "Guess a letter: ";
    cin >> Guess;
    
    //Lowercasing the letter just in case
    Guess = tolower(Guess);
    int GuessCounter = 0;

    //If a letter has already been used - make it always wrong
    for(int l = 0; l < Word.length(); l++){
      if(Guess == Printing[l][0]){
	Guess = '!';
      }
    }
    
    //Seeing if a letter is present in the word
    for(int j = 0; j < Word.length(); j++){
      
      if(Guess == Word[j]){
	GuessCounter++;
      }
      
    }

    if(GuessCounter == 0){
      DeathToll++;
    }
    
  }
  
  //If player lost
  system("clear");
  Graphics(DeathToll);
  cout << "You lose" << endl;
  cout << "The word was: " << Word << endl; 
  return;
  
}


//Main function
int main(){
  
  //Logo
  cout << "HANGMAN- Singleplayer" << endl;
  cout << "Developed by: Alexander Bix" << endl;
  
  char PlayAgain = 'y';
  
  while(PlayAgain == 'y'){
    play();
    cout << "Do you want to play again (y/n): ";
    cin >> PlayAgain;
    PlayAgain = tolower(PlayAgain);
  }
  
}
