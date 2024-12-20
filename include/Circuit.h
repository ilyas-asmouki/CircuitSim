#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
#include <Eigen/Dense>
#include "components/Component.h"

class Circuit {
public:
    Circuit(uint8_t num_nodes, uint8_t num_sources);
    ~Circuit();

    void add_component(Component* component);
    void simulate(double timestep, double endtime);

private:
    std::vector<Component*> components;
    uint8_t num_nodes = 0;
    uint8_t num_sources = 0; //number of independent voltage sources

    Matrices matrices = {Eigen::MatrixXd::Zero(0, 0), Eigen::VectorXd::Zero(0), Eigen::VectorXd::Zero(0)};
};


#endif // CIRCUIT_H