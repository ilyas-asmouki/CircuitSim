#include "Circuit.h"

Circuit::Circuit(uint8_t num_nodes, uint8_t num_sources) : num_nodes(num_nodes), num_sources(num_sources) {
    matrices.conductance = Eigen::MatrixXd::Zero(num_nodes + num_soures, num_nodes + num_soures);
    matrices.sources = Eigen::VectorXd::Zero(num_nodes + num_soures);
    matrices.unknowns = Eigen::VectorXd::Zero(num_nodes + num_soures);
    std::cout << "Circuit created with " << (int)num_nodes << " nodes and " 
    << (int)num_sources << " sources" << std::endl;
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
        matrices.conductance.setZero();
        matrices.sources.setZero();

        for (Component* component : components) {
            component->stamp(&matrices, timestep);
        }
        matrices.unknowns = matrices.conductance.partialPivLu().solve(matrices.sources);

        std::cout << "Conductance matrix:" << std::endl << matrices.conductance << std::endl;
        std::cout << "Sources vector:" << std::endl << matrices.sources << std::endl;
        std::cout << "Unknowns vector:" << std::endl << matrices.unknowns << std::endl;

    }
}

