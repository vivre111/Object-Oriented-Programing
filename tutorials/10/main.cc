#include "command.h"
#include "controller.h"
#include "view.h"
#include "model.h"

int main() {
    std::vector<Controller*> c = {new TextController, new LiveDangerously, new AlsoLiveDangerously};
    std::vector<View*> v = {new TextView};

    Model *m = new Model{c, v};
    
    while (!m->finished()) {
        Command *c = m->handleInput(); 
        c->execute(m);
        delete c;
    }


    for (auto x : c) delete x;
    for (auto x : v) delete x;
    delete m;
}
