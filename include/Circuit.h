#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
#include <Eigen/Dense>
#include "components/Component.h"

class Circuit {
public:
    Circuit(uint8_t num_nodes);
    ~Circuit();

    void add_component(Component* component);
    void simulate(double timestep, double endtime);

private:
    std::vector<Component*> components;
    uint8_t num_nodes = 0;
    Eigen::MatrixXd conductance = Eigen::MatrixXd::Zero(0, 0);
    Eigen::VectorXd sources = Eigen::VectorXd::Zero(0);
    Eigen::VectorXd unknowns = Eigen::VectorXd::Zero(0);
};


#endif // CIRCUIT_H