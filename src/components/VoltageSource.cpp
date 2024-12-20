#include "components/VoltageSource.h"

VoltageSource::VoltageSource(const std::string& name, double voltage, uint8_t node1, uint8_t node2)
    : Component(name), voltage(voltage), node1(node1), node2(node2) {
    if (node1 == node2) {
        throw std::invalid_argument("Voltage source " + name + " cannot be short-circuited");
    }
    // std::cout << "Voltage source " << name << " created with voltage " << voltage << " V between nodes " << (int)node1 << " and " << (int)node2 << std::endl;
}

VoltageSource::~VoltageSource() {
    // std::cout << "Voltage source " << name << " destroyed" << std::endl;
}

void VoltageSource::stamp(Matrices* matrices, double timestep) {
    if (node1 != 0) {
        matrices->conductance(node1-1, node1-1) += 1;
        matrices->sources(node1-1) += voltage;
    } else if (node2 != 0) {
        matrices->conductance(node2-1, node2-1) += 1;
        matrices->sources(node2-1) -= voltage;
    } else if (node1 != 0 && node2 != 0) {
        matrices->conductance(node1-1, node2-1) -= 1;
        matrices->conductance(node2-1, node1-1) -= 1;
    }
}