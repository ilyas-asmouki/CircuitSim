#include <iostream>
#include "components/Component.h"
#include "components/Resistor.h"
#include "components/Capacitor.h"
#include "components/Inductor.h"
#include "components/CurrentSource.h"
#include "components/VoltageSource.h"
#include "Circuit.h"

int main(int argc, char** argv) {
    Circuit* c = new Circuit(5);

    c->add_component(new CurrentSource("I_a", 1, 1, 3));
    c->add_component(new CurrentSource("I_b", 3, 0, 2));
    c->add_component(new CurrentSource("I_c", 5, 5, 4));

    c->add_component(new Resistor("R1", 1./1, 1, 2));
    c->add_component(new Resistor("R2", 1./2, 1, 0));
    c->add_component(new Resistor("R3", 1./3, 0, 3));
    c->add_component(new Resistor("R4", 1./4, 4, 2));
    c->add_component(new Resistor("R5", 1./5, 4, 0));
    c->add_component(new Resistor("R6", 1./6, 3, 5));
    

    c->simulate(1e-6, 1e-5);
    delete c;

    return 0;
}