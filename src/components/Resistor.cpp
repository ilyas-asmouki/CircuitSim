#include "components/Resistor.h"

Resistor::Resistor(const std::string& name, double resistance)
    : Component(name), resistance(resistance) {
    std::cout << "Resistor " << name << " created with resistance " << resistance << std::endl;
}

Resistor::~Resistor() {
    std::cout << "Resistor " << name << " destroyed" << std::endl;
}

void Resistor::stamp(Eigen::MatrixXd& conductance, Eigen::VectorXd& sources, int timestep) {
    std::cout << "r stamp" << std::endl;
    std::cout << conductance << std::endl;
    std::cout << sources << std::endl;
}