#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>
using namespace std;

// Функция для рандомной генерации N строк длиной l и создания массива
vector<string> generate_random_strings(int N, int l) {
    vector<string> result;
    string chars = "abcdefghijklmnopqrstuvwxyz"; // Алфавит для рандомной генерации строк

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, chars.size() - 1);

    for (int i = 0; i < N; ++i) {
        string new_string;
        for (int j = 0; j < l; ++j) {
            new_string.push_back(chars[dis(gen)]);
        }
        result.push_back(new_string);
    }

    return result;
}

// Функция для поиска и исключения повторяющихся строк в массиве
vector<string> remove_duplicates(const vector<string>& strings) {
    vector<string> unique_strings = strings;
    sort(unique_strings.begin(), unique_strings.end());
    unique_strings.erase(unique(unique_strings.begin(), unique_strings.end()), unique_strings.end());
    return unique_strings;
}

int main() {
    const int N = 10'000;
    const int l = 3;
    vector<string> strings = generate_random_strings(N, l);
    vector<string> unique_strings = remove_duplicates(strings);
    cout << "Number of unique strings: " << unique_strings.size() << endl;

    return 0;
}
