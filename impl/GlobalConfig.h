#ifndef GLOBALCONFIG_H
#define GLOBALCONFIG_H
#include <map>
#include <string>
// 语言选择
enum LANG {
  CHINESE,
  ENGLISH
};

// 声明变量
extern const std::map<LANG, std::string> LANG_DESC_MAP;

class GlobalConfig {
public:
  static GlobalConfig& GetInstance();
  void Print();

private:
  LANG lang;
  static GlobalConfig INSTANCE;

  GlobalConfig();
  // 禁用拷贝构造函数和赋值操作符
  GlobalConfig(const GlobalConfig&) = delete;
  GlobalConfig& operator=(const GlobalConfig&) = delete;
};
#endif //GLOBALCONFIG_H
