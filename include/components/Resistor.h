#ifndef RESISTOR_H
#define RESISTOR_H

#include "components/Component.h"

class Resistor : public Component {
public:
    Resistor(const std::string& name, double resistance);
    ~Resistor();

    void stamp(Eigen::MatrixXd& conductance, Eigen::VectorXd& sources, int timestep) override;

private:
    double resistance = 0;
};

#endif // RESISTOR_H