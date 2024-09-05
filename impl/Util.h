#ifndef UTIL_H
#define UTIL_H
#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>

class Util {
public:
  static void LOG(const std::string &msg) {
    std::cout << GetDateTime() << "\t" << msg << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
  }

  static std::string GetDateTime() {
    // 获取当前时间点
    auto now = std::chrono::system_clock::now();
    // 将时间点转换为 time_t 类型
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&now_time_t), "%Y-%m-%d %H:%M:%S");
    return oss.str();
  }
};
#endif // UTIL_H
