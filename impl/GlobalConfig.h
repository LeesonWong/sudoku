#ifndef GLOBALCONFIG_H
#define GLOBALCONFIG_H

// 语言选择
enum LANG {
  CHINESE,
  ENGLISH
};

class GlobalConfig {
public:
  LANG lang;
};
#endif //GLOBALCONFIG_H
