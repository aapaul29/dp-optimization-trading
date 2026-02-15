#ifndef UTILS_H
#define UTILS_H

#include "problem_definition.h"
#include <string>


// Load Problem Instance from a txt file
ProblemInstance load_instance(const std::string &filename);

// Print the instance
void print_instance(const ProblemInstance &instance);

#endif
