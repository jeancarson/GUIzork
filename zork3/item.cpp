#include "item.h"
#include <iostream>

using namespace std;

Item::Item() {

}


QString Item::getPathToImage(){
    cout<<"getting path to image"<<endl;
    cout<<pathToImage<<endl;
    return QString::fromStdString(pathToImage);

}


string Item:: getName() const{
    return name;
}


void Item::setNameAndPathToImage(string newName, string path){

    this->name = newName;
    // cout<<"GOT TO HERE"<<endl;

    this->pathToImage = path;
}
