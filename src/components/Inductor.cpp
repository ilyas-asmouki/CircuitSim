#include "components/Inductor.h"

Inductor::Inductor(const std::string& name, double inductance, uint8_t node1, uint8_t node2)
    : Component(name), inductance(inductance), node1(node1), node2(node2) {
    // std::cout << "Inductor " << name << " created with inductance " << inductance << " H between nodes " << (int)node1 << " and " << (int)node2 << std::endl;
}

Inductor::~Inductor() {
    // std::cout << "Inductor " << name << " destroyed" << std::endl;
}

void Inductor::stamp(Matrices* matrices, double timestep) {
    //in transient behaviour, the inductor behaves like a non-ideal voltage source with conductance g = dt/L
    double g = timestep / inductance;
    double voltage_contribution = g * previous_current;

    if (node1 != 0) {
        matrices->conductance(node1-1, node1-1) += g;
        matrices->sources(node1-1) += voltage_contribution;
        previous_current = matrices->unknowns(node1-1);
    } else if (node2 != 0) {
        matrices->conductance(node2-1, node2-1) += g;
        matrices->sources(node2-1) -= voltage_contribution;
        previous_current = -matrices->unknowns(node2-1);
    } else if (node1 != 0 && node2 != 0) {
        matrices->conductance(node1-1, node2-1) -= g;
        matrices->conductance(node2-1, node1-1) -= g;
        previous_current = matrices->unknowns(node1-1) - matrices->unknowns(node2-1);
    } else {
        previous_current = 0.0;
    }
}