//
//  main.cpp
//  RockPaperScissors
//
//  Created by Kendal Anderson on 5/20/25.
//

#include <iostream>
#include <ctime>


char playerChoice() {
   char choice;
   
   do {
      std::cout << "Choose Rock, Paper, or Scissors:\n";
      std::cout << "Enter r for rock.\n";
      std::cout << "Enter p for paper.\n";
      std::cout << "Enter s for scissors.\n";
      std::cout << "Choice: ";
      std::cin >> choice;
      std::cout << '\n';
   } while (choice != 'r' && choice != 'p' && choice != 's');
   
   return choice;
}

char cpuChoice() {
   //srand(time(0));
   char choice;
   int randNum = (rand() % 3) + 1;
   
   switch (randNum) {
      case 1:
         choice = 'r';
         break;
      case 2:
         choice = 'p';
         break;
      case 3:
         choice = 's';
         break;
   }
   
   return choice;
}


void getPlayerChoice(char choice) {
   switch (choice) {
      case 'r':
         std::cout << "Rock!";
         break;
      case 'p':
         std::cout << "Paper!";
         break;
      case 's':
         std::cout << "Scissors!";
         break;
   }
}

void getCpuChoice(char choice) {
   switch (choice) {
      case 'r':
         std::cout << "Rock!";
         break;
      case 'p':
         std::cout << "Paper!";
         break;
      case 's':
         std::cout << "Scissors!";
         break;
   }
}

void showChoices(char cpu, char player) {
   std::cout << "-----------------------------------\n";
   std::cout << "CPU: ";
   getCpuChoice(cpu);
   std::cout << " * ";
   getPlayerChoice(player);
   std::cout << " :Player";
   std::cout << '\n';
}

void result(char cpu, char player, int& playerScore, int& cpuScore) {
   switch (player) {
      case 'r':
         if (cpu == 'p') {
            std::cout << "Paper beats Rock.\n";
            std::cout << "CPU gets a point!\n";
            cpuScore++;
            std::cout << "Score: Cpu [" << cpuScore << " : " << playerScore << "] Player\n";
            std::cout << "-----------------------------------\n";
         }
         else if (cpu == 's') {
            std::cout << "Rock beats Scissors.\n";
            std::cout << "Player gets a point!\n";
            playerScore++;
            std::cout << "Score: Cpu [" << cpuScore << " : " << playerScore << "] Player\n";
            std::cout << "-----------------------------------\n";
         }
         else {
            std::cout << "Tie. Go again.\n";
            std::cout << "Score: Cpu [" << cpuScore << " : " << playerScore << "] Player\n";
            std::cout << "-----------------------------------\n";
         }
         break;
      case 'p':
         if (cpu == 's') {
            std::cout << "Scissors beat Paper\n";
            std::cout << "CPU gets a point!\n";
            cpuScore++;
            std::cout << "Score: Cpu [" << cpuScore << " : " << playerScore << "] Player\n";
            std::cout << "-----------------------------------\n";
         }
         else if (cpu == 'r') {
            std::cout << "Paper beats Rock.\n";
            std::cout << "Player gets a point!\n";
            playerScore++;
            std::cout << "Score: Cpu [" << cpuScore << " : " << playerScore << "] Player\n";
            std::cout << "-----------------------------------\n";
         }
         else {
            std::cout << "Tie. Go again.\n";
            std::cout << "Score: Cpu [" << cpuScore << " : " << playerScore << "] Player\n";
            std::cout << "-----------------------------------\n";
         }
         break;
      case 's':
         if (cpu == 'r') {
            std::cout << "Rock beats Scissors.\n";
            std::cout << "CPU gets a point!\n";
            cpuScore++;
            std::cout << "Score: Cpu [" << cpuScore << " : " << playerScore << "] Player\n";
            std::cout << "-----------------------------------\n";
         }
         else if (cpu == 'p') {
            std::cout << "Scissors beat Paper\n";
            std::cout << "Player gets a point!\n";
            playerScore++;
            std::cout << "Score: Cpu [" << cpuScore << " : " << playerScore << "] Player\n";
            std::cout << "-----------------------------------\n";
         }
         else {
            std::cout << "Tie. Go again.\n";
            std::cout << "Score: Cpu [" << cpuScore << " : " << playerScore << "] Player\n";
            std::cout << "-----------------------------------\n";
         }
         break;
   }
}


void chooseWinner(int playerScore, int cpuScore, int rounds) {
  if (rounds != 1) {
      if (playerScore > cpuScore && playerScore > (rounds / 2)) {
         std::cout << "Congratulations! You won!\n\n";
      }
      else {
         std::cout << "You lose. Better luck next time.\n";
         std::cout << "Game Over.\n\n";
      }
   }
   
   if (rounds == 1) {
      if (playerScore > cpuScore && playerScore == 1) {
         std::cout << "Congratulations! You won!\n\n";
      }
      else {
         std::cout << "You lose. Better luck next time.\n";
         std::cout << "Game Over.\n\n";
      }
   }
}

bool winCon(int& playerScore, int& cpuScore, int rounds) {
   if (rounds == 1) {
      if (playerScore == 1 || cpuScore == 1) {
         return true;
      }
   }
   
   if ((playerScore > cpuScore && playerScore > rounds / 2) || (cpuScore > playerScore && cpuScore > rounds / 2)) {
      return true;
   }
   
   return false;
}

int main(int argc, const char * argv[]) {
   srand(time(0));
   int rounds;
   char player;
   char computer;
   
   int playerScore = 0;
   int cpuScore = 0;
   
   std::cout << "Let's play Rock, Paper, Scissors!\n";
   do {
      std::cout << "Best of? (Enter 1, 3, or 5)\n";
      std::cin >> rounds;
   } while (rounds != 1 && rounds != 3 && rounds != 5);
   
   do {
      std::cout << "\nReady?\n";
      std::cout << "Rock. Paper. Scissors!\n";
      player = playerChoice();
      computer = cpuChoice();

         
      showChoices(computer, player);
      result(computer, player, playerScore, cpuScore);
      winCon(playerScore, cpuScore, rounds);
   } while (!winCon(playerScore, cpuScore, rounds));
   
   std::cout << '\n';
   chooseWinner(playerScore, cpuScore, rounds);
   
   return 0;
}
