#include <iostream>
#include <string>
// Abstract base class "Pet" with pure virtual methods
class Pet {
protected:
    std::string name;
    int age;
    int hunger;
    int happiness;
    int energy;

public:
    // Constructor - Initializing object attributes
    Pet(const std::string& petName, int petAge)
        : name(petName), age(petAge), hunger(50), happiness(50), energy(50) {}

    
    // Pure virtual methods to be implemented by derived classes
    virtual void feed() = 0;
    virtual void play() = 0;
    virtual void sleep() = 0;
    virtual void displayStatus() = 0;
    virtual void simulateTimePassing() = 0;

     // Destructor
    virtual ~Pet() {
        std::cout << name << " has been deleted." << std::endl;
    }
};
// Derived class "Dog" inheriting from "Pet"
class Dog : public Pet {
public:
    Dog(const std::string& petName, int petAge)
        : Pet(petName, petAge) {}
    
    // Encapsulation - Private attributes with public getter and setter methods
    void feed() override{
        if (hunger >= 10) {
            hunger -= 10;
            std::cout << "You fed " << name << ". Hunger level decreased." << std::endl;
        } else {
            std::cout << name << " is not hungry." << std::endl;
        }
    }

    void play() override{
        if (energy >= 20 && happiness <= 100) {
            energy -= 20;
            if(energy<=90){
            happiness += 10;}

            std::cout << "You played with " << name << ". Happiness increased." << std::endl;
            
        } else {
            std::cout << name << " is too tired to play." << std::endl;
        }
    }

    void sleep() override{
        if (energy <= 80) {
            energy += 20;
            std::cout << name << " is sleeping. Energy level increased." << std::endl;
        } else {
            std::cout << name << " is not sleepy." << std::endl;
        }
    }

    void displayStatus() override{
        std::cout << "----- " << name << "'s Status -----" << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Hunger: " << hunger << std::endl;
        std::cout << "Happiness: " << happiness << std::endl;
        std::cout << "Energy: " << energy << std::endl;
        std::cout << "--------------------------" << std::endl;
    }

    // Simulate time passing
    void simulateTimePassing() override{
        age++;  // Increment the age of the pet
        hunger += 10;  // Increase hunger level
        happiness -= 5;  // Decrease happiness level
        energy -= 10;  // Decrease energy level

        std::cout << name << " is getting older." << std::endl;
        std::cout << "Hunger level increased." << std::endl;
        std::cout << "Happiness level decreased." << std::endl;
        std::cout << "Energy level decreased." << std::endl;
    }

     // Destructor
    ~Dog() override {
        std::cout << name << " (Dog) has been deleted." << std::endl;
    }
};

int main() {
    std::string petName;
    int petAge;

    std::cout << "Welcome to the Virtual Pet Simulation Game!" << std::endl;
    std::cout << "Please enter your pet's name: ";
    std::cin >> petName;
    std::cout << "Please enter your pet's age: ";
    std::cin >> petAge;

   // Creating a Dog object dynamically
   Pet* myPet = new Dog(petName, petAge);

    int choice;
    int cycle = 0;  // Counter for game cycles
    while (true) {
        std::cout << "----- Menu -----" << std::endl;
        std::cout << "1. Feed" << std::endl;
        std::cout << "2. Play" << std::endl;
        std::cout << "3. Sleep" << std::endl;
        std::cout << "4. Display Status"<<std::endl;
        std::cout << "5. Simulate Time Passing" << std::endl;  // Added menu option
        std::cout << "6. Quit" << std::endl;
        std::cout << "----------------" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                 myPet->feed();
                break;
            case 2:
                myPet->play();
                break;
            case 3:
               myPet->sleep();
                break;
            case 4:
                 myPet->displayStatus();
                break;
            case 5:
                myPet->simulateTimePassing();
                break;
            case 6:
                std::cout << "Thank you for playing the Virtual Pet Simulation Game!" << std::endl;
                delete myPet; // Deallocate memory
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

        cycle++;  // Increment the game cycle

        // Simulate time passing every 10 game cycles
        if (cycle % 10 == 0) {
            myPet->simulateTimePassing();
        }
    }

    return 0;
}
