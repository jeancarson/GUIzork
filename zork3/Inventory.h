// #ifndef INVENTORY_H
// #define INVENTORY_H

// #endif // INVENTORY_H
// #include <vector>
// #include <string>
// #include <iostream>

// using namespace std;

// //SINGLETON YAYY JOSH
// class Inventory{
// private:
//     std::vector<std::string> items; // Vector to store items
//     static Inventory* instance; // Static member to hold the single instance

// public:
//     static Inventory& getInstance() {
//         if (instance == nullptr) {
//             instance = new Inventory();
//         }
//         return *instance;
//     }
// public:
//     // Constructor
//     Inventory() {}

//     // Function to add an item to the inventory
//     void addItem(const std::string& item) {
//         if (items.size() < 5) { // Check if inventory is full
//             items.push_back(item);
//             std::cout << "Added " << item << " to inventory." << std::endl;
//         } else {
//             std::cout << "Inventory is full. Cannot add more items." << std::endl;
//         }
//     }
//     bool hasItem(const std::string& item) {
//         for (const auto& i : items) {
//             if (i == item) {
//                 return true; // Item found
//             }
//         }
//         return false; // Item not found
//     }
// };
