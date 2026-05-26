#pragma once
#include "core/command_context.hpp"
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

class Console {
public:
  using Args = std::vector<std::string>;
  using CommandFn = std::function<void(CommandContext &, const Args &)>;
  // using CommandFn = void(*)(CommandContext&, const Args&);
private:
  std::string input_;                // input entered into the console
  std::vector<std::string> history_; // input history
  std::unordered_map<std::string, CommandFn> commands_;

  static Args tokenize(const std::string &line);

public:
  Console() = default;
  ~Console() = default;

  void execute(CommandContext &cmdCtx, const std::string &line);
  void addCommand(std::string name, CommandFn fn);
  void print(const std::string &text);
  void clear();
};
