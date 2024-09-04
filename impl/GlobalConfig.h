#ifndef GLOBALCONFIG_H
#define GLOBALCONFIG_H

// 语言选择
enum LANG {
  CHINESE,
  ENGLISH
};

class GlobalConfig {
public:
  static const GlobalConfig& GetInstance();
  void Print();

private:
  LANG lang;
  static GlobalConfig INSTANCE;

  GlobalConfig();
};
#endif //GLOBALCONFIG_H
