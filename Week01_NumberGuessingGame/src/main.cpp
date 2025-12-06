#include <iostream>

int main() {
  int num;
  int guess;

  char playAgain;

  srand(time(NULL));

  do {
    num = (rand() % 100) + 1;

    std::cout << "******* NUMBER GUESSING GAME *******" << std::endl;
    int tries = 0;
    do {
      std::cout << "Enter a guess between (1-100):";
      std::cin >> guess;
      tries++;
      if (guess > num) {
        std::cout << "Too high!" << std::endl;
      } else if (guess < num) {
        std::cout << "Too low!" << std::endl;
      } else {
        std::cout << "CORRECT! # of tries: " << tries << std::endl;
      }

    } while (guess != num);
    std::cout << "Would you like to play again (Y/N)?" << std::endl;
    std::cin >> playAgain;
  } while (playAgain == 'y' || playAgain == 'Y');
  std::cout << "***************************************" << std::endl;
}