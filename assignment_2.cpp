/*
 * Name        : Shoot Out 
 * Author      : Matt Sterkel
 * Description : Western style shoot out game
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include "CinReader.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;


void ClearScreen();


int main() {
  // Set up our CinReader instance
  CinReader reader;


  char again ='Y', player_choice;
  int computer_choice;
  bool user_dead, computer_dead, draw;
  int user_gun;
  int computer_gun;
  int victory = 0;
  int defeat = 0;
  int tie = 0;
  
  // Seed the Random Number Generator
  srand(time(0));

  cout << "Welcome to Shoot out! \n \nPress any key to continue" << endl;
  reader.readString();
  ClearScreen();
  
  // GAME LOOP
  do {
  computer_choice = 0;
  user_dead = false;
  computer_dead = false; 
  draw = false;
  user_gun = 0;
  computer_gun = 1;

  cout << "Ememy Gun: Unloaded                       Your Gun: Unloaded" <<
      endl<<endl;
  cout << "Let's do this! \n\"r\" for reload - "<< endl;
  cout << "\"s\" for shoot (if gun is loaded) - "  << endl;
  cout << "\"b\" for block" << endl;

  player_choice = tolower(reader.readChar("BbRr"));

  ClearScreen();

 if(player_choice == 'r') {
  user_gun = 1;
  cout << "Locked and loaded." << endl;
}
 else {cout << "A little jumpy huh..." << endl;}

  do {
    if (user_gun == 0 && computer_gun == 0) {
     cout << "Ememy Gun: Unloaded                       Your Gun: Unloaded" <<
     endl<<endl;
}
    else if (user_gun == 0 && computer_gun != 0) {
    cout << " Enemy Gun: Loaded                     Your Gun: Unloaded " <<
    endl<<endl;
}
    else if (user_gun != 0 && computer_gun == 0) {
     cout << " Enemy Gun: Unloaded                     Your Gun: Loaded " << 
     endl<<endl;
}
    else { cout << " Enemy Gun: Loaded                     Your Gun: Loaded " <<
      endl<<endl;
}

  cout << "Make your move! \n\"r\" for reload - "<< endl;
  cout << "\"s\" for shoot (if gun is loaded) - "  << endl;
  cout << "\"b\" for block" << endl;

 if(user_gun == 0) {
  player_choice = tolower(reader.readChar("BbRr"));
}
 else {
   player_choice = tolower(reader.readChar("BbSs"));
}

ClearScreen();

 if(computer_gun == 0) {
   computer_choice = rand() % 2;
}
 else {
   computer_choice = rand() % 2 +1;
}

  if(player_choice == 'r' && computer_choice == 0) { 
    user_gun = 1;
    computer_gun = 1;
    cout << "Locked and loaded." << endl; 
}
  else if(player_choice == 'r' && computer_choice == 1) {
    user_gun = 1;
    cout << "Locked and loaded." << endl;
  }
  else if(player_choice == 'r' && computer_choice == 2) {
    user_dead = true;
    cout << "You've been hit! \nGame over pal.\n" << endl;
  }
  
  else if(player_choice == 'b' && computer_choice == 0) {
    computer_gun = 1;
    cout << "Carefull, your opponent's gun is now loaded!" << endl;
  }
  else if(player_choice == 'b' && computer_choice == 1) {
     cout << "Looks like you both blocked...cowards!" << endl;
  }
  else if(player_choice == 'b' && computer_choice == 2) {
      computer_gun = 0;
      cout << "Successful evade!" << endl;
  }
  else if(player_choice == 's' && computer_choice == 0){
    computer_dead = true;
    cout << "You got em'!\n" << endl;
  }
  else if(player_choice == 's' && computer_choice == 1) {
    cout << "Ah shucks...your opponent evaded your shot." << endl;
    user_gun =0;
  }
  else if(player_choice == 's' && computer_choice == 2) {
    draw = true;
    cout << "You got each other... a draw I reckon.\n" << endl;
  }
  
  else{ cout << "Game Has Crashed - Sorry Partner" << endl; }

/*  The following code was used when trouble shooting this program.

cout << "computer_choice=" << computer_choice << " user dead=" << user_dead 
<< "draw = "  << draw << "player_choice= "<<player_choice
<< "computer_dead= " <<  computer_dead <<  "computer_gun =" <<  
computer_gun  <<endl; 
*/

} while(user_dead == false && computer_dead == false &&  draw == false); 

  if(user_dead == true) {
   ++defeat;}
  else if(computer_dead == true) {
    ++victory;}
  else {
    ++tie;}

  cout << "Wins: " << victory << " " << "Losses: " << defeat << " " << "Ties: " 
       << tie << endl;   

    // Prompt user to see if the want to continue to play
    cout << "Would you like to play again? (Y / N)\n";
    again = toupper(reader.readChar("YNyn"));
    cout << endl;
    ClearScreen();
  } while (again == 'Y');


  return 0;
}


void ClearScreen() {
#ifdef _WIN32
  std::system("cls");
#else
  // Assume POSIX
  std::system("clear");
#endif
}

