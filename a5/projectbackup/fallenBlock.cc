#include "fallenBlock.h"
#include "fallingBlock.h"
FallenBlock::FallenBlock(FallingBlock &falling):timeCreated{falling.timeCreated},cellsLeft{falling.numCells}{}

void FallenBlock::cellDeleted(){
	cellsLeft--;
}

