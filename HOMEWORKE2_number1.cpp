#include <iostream>

class Person {
public:
    float weight;
    float height;

    Person(float w, float h) : weight(w), height(h) {}
};

class PeopleData {
public:
    int numPeople;
    Person **people;

    PeopleData(int num) : numPeople(num) {
        people = new Person *[numPeople];
    }

    ~PeopleData() {
        for (int i = 0; i < numPeople; ++i) {
            delete people[i];
        }
        delete[] people;
    }

    void setPersonData(int index, float weight, float height) {
        if (index >= 0 && index < numPeople) {
            people[index] = new Person(weight, height);
        } else {
            std::cout << "Invalid index\n";
        }
    }

    void displayPersonData(int index) {
        if (index >= 0 && index < numPeople) {
            std::cout << "Person " << index + 1 << ": Weight = " << people[index]->weight << ", Height = " << people[index]->height << std::endl;
        } else {
            std::cout << "Invalid index\n";
        }
    }
};

int main() {
    int numPeople = 5;
    PeopleData data(numPeople);

    data.setPersonData(0, 70.5, 175.0);
    data.setPersonData(1, 65.2, 162.4);
    data.setPersonData(2, 80.0, 180.2);
    data.setPersonData(3, 55.5, 160.0);
    data.setPersonData(4, 90.3, 185.8);

    for (int i = 0; i < numPeople; ++i) {
        data.displayPersonData(i);
    }

    return 0;
}
