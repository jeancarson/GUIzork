// item.h
#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
#include <QString>

class Item {
public:
    Item();
    Item(const Item& other);
    Item& operator=(const Item& other);
    bool operator==(const Item& other) const;

    QString getPathToImage();
    std::string getName() const;
    void setNameAndPathToImage(std::string newName, std::string path);
    void setItemData(std::string colour);
    void setItemData(int price);
    void printItemData();

private:
    std::string name;
    std::string pathToImage;
    bool inIventory;

    enum class DataType {
        None,
        Colour,
        Price
    } dataType;

    union ItemData {
        std::string colour;
        int price;

        ItemData() { new (&colour) std::string(); }
        ~ItemData() {}
    } itemData;

    void destroyData();
};
#endif // ITEM_H
