#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <chrono>
using namespace std;

// Функция для получения хэш-кода строки
size_t hash_string(const string& s) {
    return hash<string>{}(s);
}

// Функция для удаления дубликатов строк
vector<string> delete_duplicates_strings(const vector<string>& strings) {
    unordered_set<string> unique_strings(strings.begin(), strings.end());
    return vector<string>(unique_strings.begin(), unique_strings.end());
}

// Функция для удаления дубликатов хэш-кодов
vector<size_t> delete_duplicates_hashes(const vector<size_t>& hashes) {
    unordered_set<size_t> unique_hashes(hashes.begin(), hashes.end());
    return vector<size_t>(unique_hashes.begin(), unique_hashes.end());
}

int main() {
    vector<string> strings = {"apple", "orange", "banana", "apple", "kiwi", "banana"};
    vector<size_t> hashes;

    for (const string& s : strings) {
        hashes.push_back(hash_string(s));
    }

    auto start_time = chrono::high_resolution_clock::now();
    vector<string> unique_strings = delete_duplicates_strings(strings);
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_time_strings = end_time - start_time;

    start_time = chrono::high_resolution_clock::now();
    vector<size_t> unique_hashes = delete_duplicates_hashes(hashes);
    end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_time_hashes = end_time - start_time;

    cout << "Time taken to delete duplicates for strings: " << elapsed_time_strings.count() << " seconds\n";
    cout << "Time taken to delete duplicates for hashes: " << elapsed_time_hashes.count() << " seconds\n";

    return 0;
}
