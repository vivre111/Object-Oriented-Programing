#include "decorator.h"

Decorator::Decorator(Image* im): component{im}{}

Decorator::~Decorator(){delete component;}

