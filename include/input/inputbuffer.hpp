#pragma once
#include <string>
#include <vector>

class InputBuffer {
private:
  std::vector<std::string> cmds_{};

public:
  void push(const std::string &cmd);

  void clear();

  const std::vector<std::string> &commands() const;
  std::vector<std::string> &commands();
};
