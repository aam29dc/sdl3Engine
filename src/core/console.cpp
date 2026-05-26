#include "core/console.hpp"
#include "core/command_context.hpp"
#include <iostream>
#include <sstream>
#include <string>

void Console::addCommand(std::string name, CommandFn fn) {
  if (commands_.find(name) == commands_.end())
    commands_[name] = fn;
  else
    std::cout << "addCommand error: " << name << " already exists.\n";
}

void Console::print(const std::string &text) { history_.push_back(text); }

void Console::clear() { history_.clear(); }

void Console::execute(CommandContext &cmdCtx, const std::string &line) {
  input_ = line;
  history_.push_back(line);

  Args args = tokenize(line);
  if (args.empty()) {
    input_.clear();
    return;
  }

  auto it = commands_.find(args[0]);
  if (it != commands_.end()) {
    it->second(cmdCtx, args);
  } else
    print("Unknown cmd " + args[0]);

  input_.clear();
}

Console::Args Console::tokenize(const std::string &line) {
  std::istringstream ss(line);
  std::string token;
  std::vector<std::string> tokens;

  while (ss >> token) {
    tokens.push_back(token);
  }

  return tokens;
}
