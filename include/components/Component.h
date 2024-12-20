#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <iostream>
#include <Eigen/Dense>

struct Matrices {
    Eigen::MatrixXd conductance;
    Eigen::VectorXd sources;
    Eigen::VectorXd unknowns;
};

class Component {
public:
    Component(const std::string& name);
    virtual ~Component();

    virtual void stamp(Matrices* matrices, double timestep) = 0;

protected:
    std::string name;
};

#endif // COMPONENT_H
