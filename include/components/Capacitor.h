#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "components/Component.h"

class Capacitor : public Component {
public:
    Capacitor(const std::string& name, double capacitance, uint8_t node1, uint8_t node2);
    ~Capacitor();

    void stamp(Matrices* matrices, double timestep) override;

private:
    double capacitance = 0;
    uint8_t node1 = 0;
    uint8_t node2 = 0;
    double previous_voltage = 0;
};


#endif // CAPACITOR_H