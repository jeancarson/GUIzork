#include "item.h"
#include <iostream>

using namespace std;

Item::Item(string name, string pathToImage) {
    this->pathToImage = pathToImage;
    this->name = name;
}


QString Item::getPathToImage(){
    cout<<"getting path to image"<<endl;
    cout<<pathToImage<<endl;
    return QString::fromStdString(pathToImage);

}
