#include "components/CurrentSource.h"

CurrentSource::CurrentSource(const std::string& name, double current, uint8_t node1, uint8_t node2)
    : Component(name), current(current), node1(node1), node2(node2) {
    // std::cout << "Current source " << name << " created with current "<< current << "A between nodes " << (int)node1 << " and " << (int)node2 << std::endl;
}

CurrentSource::~CurrentSource() {
    // std::cout << "Current source " << name << " destroyed" << std::endl;
}

void CurrentSource::stamp(Matrices* matrices, double timestep) {
    if (node1 != 0 && node2 != 0) {
        matrices->sources(node1-1) += current;
        matrices->sources(node2-1) -= current;
    } else if (node1 != 0) {
        matrices->sources(node1-1) += current;
    } else if (node2 != 0) {
        matrices->sources(node2-1) -= current;
    }
}