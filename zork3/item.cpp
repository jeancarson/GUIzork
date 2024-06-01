#include "item.h"
#include <iostream>

using namespace std;

Item::Item() {
}
//copy constructor
Item::Item(const Item& other) {
    this->name = other.name;
    this->pathToImage = other.pathToImage;
}


QString Item::getPathToImage(){
    cout<<"getting path to image"<<endl;
    cout<<pathToImage<<endl;
    return QString::fromStdString(pathToImage);

}
//operator overloading
bool Item::operator==(const Item& other) const {
    return this->name == other.name;
}


string Item:: getName() const{
    return name;
}


void Item::setNameAndPathToImage(string newName, string path){

    this->name = newName;
    this->pathToImage = path;
}
