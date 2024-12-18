#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <iostream>
#include <Eigen/Dense>

class Component {
public:
    Component(const std::string& name);
    virtual ~Component();

    virtual void stamp(Eigen::MatrixXd& conductance, Eigen::VectorXd& sources, double timestep) = 0;

protected:
    std::string name;
};

#endif // COMPONENT_H
