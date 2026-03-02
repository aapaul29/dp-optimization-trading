#include "../include/utils.h"
#include <iostream>

int main() {
  try {
    ProblemInstance instance = load_instance("data/small_instance.txt");
    print_instance(instance);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
