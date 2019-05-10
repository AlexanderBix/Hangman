#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
using namespace std;

//Printing the Hangman
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

//playing;
void play(){
  string Word;
  char Guess;
  int DeathToll = 0;
  int numguess = 0;
  int winning = 0;

  //Player1: Enter the word
  cout << "Player1, Enter a word for Player2 to guess." << endl << "Make sure they can't see you typing it: ";
  cin >> Word;

  //Lowercases every letter in the word just in case
  for(int n = 0 ; n < Word.length(); n++){
    Word[n] = tolower(Word[n]);
  }

  //Array used for printing
  string Printing[Word.length()];
  for(int k = 0; k < Word.length(); k++){
    Printing[k] = "_ ";
  }
  
  //Core loop of the program
  while(DeathToll < 6){
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

      //Printing out letter
      if(Printing[i] != "_ "){
	cout << Printing[i] << " ";
      }
      else{
	cout << Printing[i];
      }
      
    }

    cout << endl;

    //If Player2 wins
    if(winning == 1){
      cout << "Player2 wins!" << endl;
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

  //If Player1 Wins
  system("clear");
  Graphics(DeathToll);
  cout << "Player1 Wins" << endl;
  cout << "The word was: " << Word << endl;
  return;
  
}

//Main Function
int main(){
  //Logo
  cout << "HANGMAN- Multiplayer" << endl;
  cout << "Developed by: Alexander Bix" << endl;

  char PlayAgain = 'y';
  
  while(PlayAgain == 'y'){
    play();
    cout << "Do you want to play again (y/n): ";
    cin >> PlayAgain;
    system("clear");
    PlayAgain = tolower(PlayAgain);
  }
  
}
