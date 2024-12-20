#ifndef VOLTAGESOURCE_H
#define VOLTAGESOURCE_H

#include "Component.h"

class VoltageSource : public Component {
public:
    VoltageSource(const std::string& name, double voltage, uint8_t node1, uint8_t node2);
    ~VoltageSource();
    void stamp(Matrices* matrices, double timestep) override;

private:
    double voltage;
    uint8_t node1;
    uint8_t node2;
};


#endif // VOLTAGESOURCE_H