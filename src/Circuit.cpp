#include "Circuit.h"

Circuit::Circuit(uint8_t num_nodes) : num_nodes(num_nodes) {
    conductance = Eigen::MatrixXd::Zero(num_nodes, num_nodes);
    sources = Eigen::VectorXd::Zero(num_nodes);
    unknowns = Eigen::VectorXd::Zero(num_nodes);
    std::cout << "Circuit created with " << (int)num_nodes << " nodes" << std::endl;
}

Circuit::~Circuit() {
    std::cout << "Circuit destroyed" << std::endl;
    for (Component* component : components) {
        delete component;
    }
}

void Circuit::add_component(Component* component) {
    components.push_back(component);
}

void Circuit::simulate(double timestep, double endtime) {
    for (double t = 0; t < endtime; t += timestep) {
        conductance.setZero();
        sources.setZero();
        for (Component* component : components) {
            component->stamp(conductance, sources, timestep);
        }
        unknowns = conductance.partialPivLu().solve(sources);

        std::cout << "Conductance matrix:" << std::endl << conductance << std::endl;
        std::cout << "Sources vector:" << std::endl << sources << std::endl;
        std::cout << "Unknowns vector:" << std::endl << unknowns << std::endl;

    }
}

