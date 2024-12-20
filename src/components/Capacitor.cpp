#include "components/Capacitor.h"

Capacitor::Capacitor(const std::string& name, double capacitance, uint8_t node1, uint8_t node2)
    : Component(name), capacitance(capacitance), node1(node1), node2(node2) {
    // std::cout << "Capacitor " << name << " created with capacitance " << capacitance << " F between nodes " << (int)node1 << " and " << (int)node2 << std::endl;
}

Capacitor::~Capacitor() {
    // std::cout << "Capacitor " << name << " destroyed" << std::endl;
}

void Capacitor::stamp(Matrices* matrices, double timestep) {
    //in transient behaviour, the capacitor behaves like a non-ideal current source with conductance g = C/dt
    double g = capacitance / timestep;
    double current_contribution = g * previous_voltage;

    if (node1 != 0) {
        matrices->conductance(node1-1, node1-1) += g;
        matrices->sources(node1-1) += current_contribution;
        previous_voltage = matrices->unknowns(node1-1);
    } else if (node2 != 0) {
        matrices->conductance(node2-1, node2-1) += g;
        matrices->sources(node2-1) -= current_contribution;
        previous_voltage = -matrices->unknowns(node2-1);
    } else if (node1 != 0 && node2 != 0) {
        matrices->conductance(node1-1, node2-1) -= g;
        matrices->conductance(node2-1, node1-1) -= g;
        previous_voltage = matrices->unknowns(node1-1) - matrices->unknowns(node2-1);
    } else {
        previous_voltage = 0.0;
    }
}