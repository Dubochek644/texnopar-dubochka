#include <iostream>
#include <vector>

class Person {
public:
    float weight;
    float height;

    Person(float w, float h) : weight(w), height(h) {}
};

class PeopleData {
public:
    int numPeople;
    std::vector<Person> people;

    void addPerson(float weight, float height) {
        people.emplace_back(weight, height);
        numPeople++;
    }

    float calculateAverageWeightForHeight(float targetHeight) {
        float totalWeight = 0.0;
        int count = 0;

        for (const auto& person : people) {
            if (person.height == targetHeight) {
                totalWeight += person.weight;
                count++;
            }
        }

        if (count > 0) {
            return totalWeight / count;
        } else {
            return 0.0;
        }
    }
};

int main() {
    PeopleData data;

    data.addPerson(70.5, 175.0);
    data.addPerson(65.2, 162.4);
    data.addPerson(80.0, 180.2);
    data.addPerson(55.5, 162.4);
    data.addPerson(90.3, 175.0);

    float targetHeight = 175.0;
    float averageWeight = data.calculateAverageWeightForHeight(targetHeight);

    if (averageWeight > 0.0) {
        std::cout << "Средний вес для людей с ростом " << targetHeight << " : " << averageWeight << std::endl;
    } else {
        std::cout << "Нет данных о людях" << targetHeight << std::endl;
    }

    return 0;
}
