#include "model.h"
#include "command.h"

void HitCommand::execute(Model *m) {
    m->hit();
}

void StandCommand::execute(Model *m) {
    m->stand();
}
