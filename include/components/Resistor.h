#ifndef RESISTOR_H
#define RESISTOR_H

#include "components/Component.h"

class Resistor : public Component {
public:
    Resistor(const std::string& name, double resistance, uint8_t node1, uint8_t node2);
    ~Resistor();

    void stamp(Eigen::MatrixXd& conductance, Eigen::VectorXd& sources, double timestep) override;

private:
    double resistance = 0;
    uint8_t node1 = 0;
    uint8_t node2 = 0;
};

#endif // RESISTOR_H