#include "Players.h"

Players::Players(const std::string& name):name(name)
{                                                       //constructor

}

std::string Players::getName() const {
return name;

}

Players::~Players()
{
    //destructor
}
