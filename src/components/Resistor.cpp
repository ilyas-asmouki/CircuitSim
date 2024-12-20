#include "components/Resistor.h"

Resistor::Resistor(const std::string& name, double resistance, uint8_t node1, uint8_t node2)
    : Component(name), resistance(resistance), node1(node1), node2(node2) {
    // std::cout << "Resistor " << name << " created with resistance " << resistance << " ohm" << std::endl;
}

Resistor::~Resistor() {
    // std::cout << "Resistor " << name << " destroyed" << std::endl;
}

void Resistor::stamp(Matrices* matrices, double timestep) {
    double g = 1 / resistance;
    if (node1 != 0) matrices->conductance(node1-1, node1-1) += g;
    if (node2 != 0) matrices->conductance(node2-1, node2-1) += g;
    if (node1 != 0 && node2 != 0) {
        matrices->conductance(node1-1, node2-1) -= g;
        matrices->conductance(node2-1, node1-1) -= g;
    }
}