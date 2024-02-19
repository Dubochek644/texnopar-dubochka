#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void playHangman(std::string word) { // создаем слово
    std::string guessedChars(word.length(), '_');
    int attempts = 10;
    std::vector<char> missedChars;

    while (attempts > 0 && guessedChars != word) { // начало цикла игры, который продолжается до исчерпания попыток или до угадывания всего слова.
        std::cout << "Word: " << guessedChars << std::endl;
        std::cout << "Missed letters: ";
        for (char missedChar : missedChars) {
            std::cout << missedChar << " ";
        }
        std::cout << std::endl;

        char guess;
        std::cout << "Enter a letter: ";
        std::cin >> guess;

        if (std::find(missedChars.begin(), missedChars.end(), guess) != missedChars.end() || std::find(guessedChars.begin(), guessedChars.end(), guess) != guessedChars.end()) { //Проверка, была ли уже введенная буква.
            std::cout << "You already guessed that letter. Try again." << std::endl;
            continue;
        }

        bool found = false; // Поиск введенной буквы в слове и обновление guessedChars и missedChars соответственно.
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess) {
                guessedChars[i] = guess;
                found = true;
            }
        }

        if (!found) {
            missedChars.push_back(guess);
            attempts--;
            std::cout << "Incorrect guess. Attempts left: " << attempts << std::endl;
        } else {
            std::cout << "Correct guess! Keep it up." << std::endl;
        }
    }

    if (guessedChars == word) {
        std::cout << "Congratulations! You guessed the word: " << word << std::endl;
    } else {
        std::cout << "Out of attempts! The word was: " << word << std::endl;
    }
}

int main() {
    std::string wordToGuess;
    std::cout << "Enter the word to guess: ";
    std::cin >> wordToGuess;
    std::transform(wordToGuess.begin(), wordToGuess.end(), wordToGuess.begin(), ::tolower);

    playHangman(wordToGuess);

    return 0;
}
