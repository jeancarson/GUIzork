#include "item.h"

Item::Item() {}


QString Item::getPathToImage(){
    return QString::fromStdString(pathToImage);

}
