#include "components/Component.h"
#include <iostream>

Component::Component(const std::string& name) : name(name) {
    std::cout << "Component " << name << " created" << std::endl;
}

Component::~Component() {
    std::cout << "Component " << name << " destroyed" << std::endl;
}