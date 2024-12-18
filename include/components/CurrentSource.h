#ifndef CURRENTSOURCE_H
#define CURRENTSOURCE_H

#include "components/Component.h"

class CurrentSource : public Component {
public:
    CurrentSource(const std::string& name, double current, uint8_t node1, uint8_t node2);
    ~CurrentSource();

    void stamp(Eigen::MatrixXd& conductance, Eigen::VectorXd& sources, double timestep) override;

private:
    double current = 0;
    uint8_t node1 = 0;
    uint8_t node2 = 0;
};

#endif // CURRENTSOURCE_H