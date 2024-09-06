#include "GlobalConfig.h"
#include <iostream>

// 定义变量
const std::map<LANG, std::string> LANG_DESC_MAP = {{CHINESE, "中文"},
                                                   {ENGLISH, "English"}};

GlobalConfig GlobalConfig::INSTANCE;

// 构造函数的定义
GlobalConfig::GlobalConfig() : lang(CHINESE) {
  // 初始化或其他设置
}

GlobalConfig &GlobalConfig::GetInstance() { return INSTANCE; }

void GlobalConfig::Print() {
  std::cout << LANG_DESC_MAP.at(CHINESE) << std::endl;
}
