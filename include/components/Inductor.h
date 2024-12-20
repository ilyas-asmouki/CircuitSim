#ifndef INDUCTOR_H
#define INDUCTOR_H

#include "components/Component.h"

class Inductor : public Component {
public:
    Inductor(const std::string& name, double inductance, uint8_t node1, uint8_t node2);
    ~Inductor();

    void stamp(Matrices* matrices, double timestep) override;

private:
    double inductance = 0;
    uint8_t node1 = 0;
    uint8_t node2 = 0;
    double previous_current = 0;
};


#endif // INDUCTOR_H