#include <iostream>
#include "GlobalConfig.h"


const GlobalConfig &GlobalConfig::GetInstance() { return GlobalConfig::INSTANCE; }

void GlobalConfig::Print() {
  std::cout << lang << std::endl;
}
