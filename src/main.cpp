#include <iostream>
#include "components/Component.h"
#include "components/Resistor.h"
#include "components/CurrentSource.h"
#include "Circuit.h"

int main(int argc, char** argv) {
    Circuit* c = new Circuit(3);
    c->add_component(new Resistor("R1", 1000, 1, 0));
    c->add_component(new Resistor("R2", 2000, 1, 2));
    c->add_component(new Resistor("R3", 1000, 2, 0));
    c->add_component(new CurrentSource("I1", 1e-3, 1, 3));
    c->add_component(new Resistor("R4", 3000, 3, 0));
    c->simulate(1e-3, 1e-2);
    delete c;

    return 0;
}