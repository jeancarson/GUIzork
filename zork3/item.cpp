// item.cpp
#include "item.h"
#include <iostream>

using namespace std;

Item::Item() : dataType(DataType::None) {
}

// Copy constructor
Item::Item(const Item& other) : dataType(other.dataType) {
    name = other.name;
    pathToImage = other.pathToImage;
    inIventory = other.inIventory;

    if (dataType == DataType::Colour) {
        new (&itemData.colour) std::string(other.itemData.colour);
    } else if (dataType == DataType::Price) {
        itemData.price = other.itemData.price;
    }
}


// Copy assignment operator
Item& Item::operator=(const Item& other) {
    if (this == &other) {
        return *this;
    }

    name = other.name;
    pathToImage = other.pathToImage;
    inIventory = other.inIventory;

    destroyData();
    dataType = other.dataType;

    if (dataType == DataType::Colour) {
        new (&itemData.colour) std::string(other.itemData.colour);
    } else if (dataType == DataType::Price) {
        itemData.price = other.itemData.price;
    }

    return *this;
}

void Item::destroyData() {
    //need to provide special implementation for non trivial data types (int is done automatically)
    if (dataType == DataType::Colour) {
        using std::string;
        itemData.colour.~string();
    }
    dataType = DataType::None;
}

QString Item::getPathToImage() {
    return QString::fromStdString(pathToImage);
}

bool Item::operator==(const Item& other) const {
    return name == other.name;
}

string Item::getName() const {
    return name;
}

void Item::setNameAndPathToImage(string newName, string path) {
    name = newName;
    pathToImage = path;
}

void Item::setItemData(string colour) {
    destroyData();
    new (&itemData.colour) std::string(colour);
    dataType = DataType::Colour;
    printItemData();
}

void Item::setItemData(int price) {
    destroyData();
    itemData.price = price;
    dataType = DataType::Price;
    printItemData();
}

void Item::printItemData() {
    cout << "Printing item data for: " << getName() << endl;

    if (dataType == DataType::Colour) {
        cout << "The colour of " << getName() << " is: " << itemData.colour << endl;
    } else if (dataType == DataType::Price) {
        cout << "The item " << getName() << " costs $" << to_string(itemData.price) << endl;
    }
}
