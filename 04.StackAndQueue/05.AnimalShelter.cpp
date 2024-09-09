// An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. You may use the built-in Linked list data structure.

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Animal {
public:
    string type;
    string name;
    int order;  

    Animal(string t, string n, int o) {}

    // Compare two animals based on their order
    bool isOlderThan(const Animal& other) const {
        return this->order < other.order;
    }
};

class AnimalShelter {
private:
    queue<Animal> dogs;
    queue<Animal> cats;
    int order;  

public:
    AnimalShelter() : order(0) {}

    // Enqueue a dog or a cat
    void enqueue(string type, string name) {
        Animal animal(type, name, order++);
        if (type == "dog") {
            dogs.push(animal);
        } else if (type == "cat") {
            cats.push(animal);
        } else {
            cout<< "Unknown animal type!" << endl;
        }
    }

    // Dequeue the oldest animal of any type
    Animal dequeueAny() {
        if (dogs.empty() && cats.empty()) {
            cout << "No animals in the shelter!" << endl;
            return Animal("none", "none", -1);
        } else if (dogs.empty()) {
            return dequeueCat();
        } else if (cats.empty()) {
            return dequeueDog();
        } else {
            Animal dog = dogs.front();
            Animal cat = cats.front();
            if (dog.isOlderThan(cat)) {
                return dequeueDog();
            } else {
                return dequeueCat();
            }
        }
    }

    // Dequeue the oldest dog
    Animal dequeueDog() {
        if (dogs.empty()) {
            cout << "No dogs in the shelter!" << endl;
            return Animal("none", "none", -1);
        }
        Animal oldestDog = dogs.front();
        dogs.pop();
        return oldestDog;
    }

    // Dequeue the oldest cat
    Animal dequeueCat() {
        if (cats.empty()) {
            cout << "No cats in the shelter!" << endl;
            return Animal("none", "none", -1);
        }
        Animal oldestCat = cats.front();
        cats.pop();
        return oldestCat;
    }
};

int main() {
    AnimalShelter shelter;

    // Enqueue some animals
    shelter.enqueue("dog", "Rex");
    shelter.enqueue("cat", "Mittens");
    shelter.enqueue("dog", "Buddy");
    shelter.enqueue("cat", "Whiskers");

    // Dequeue based on different conditions
    cout << "Adopting any animal: " << shelter.dequeueAny().name << endl; 
    cout << "Adopting a dog: " << shelter.dequeueDog().name << endl;     
    cout << "Adopting a cat: " << shelter.dequeueCat().name << endl;    

    return 0;
}
