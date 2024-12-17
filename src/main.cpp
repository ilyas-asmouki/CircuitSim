#include <iostream>
#include "components/Component.h"
#include "components/Resistor.h"

int main(int argc, char** argv) {
    Resistor* r = new Resistor("R1", 1000);
    Eigen::MatrixXd conductance(2, 2);
    Eigen::VectorXd sources(1);
    r->stamp(conductance, sources, 0);
    delete r;
    return 0;
}