#include "core/commands.hpp"
#include "core/context/command.hpp"
#include "core/engine.hpp"
#include "core/time.hpp"
#include <string>

void cmd_clear(CommandContext &cmdCtx, const Console::Args &) {
  cmdCtx.engine.console().clear();
}

void cmd_echo(CommandContext &cmdCtx, const Console::Args &args) {
  std::string result;

  for (size_t i = 1; i < args.size(); i++) {
    result += args[i];
    result += " ";
  }
  cmdCtx.engine.console().print(result);
}

void cmd_quit(CommandContext &cmdCtx, const Console::Args &) {
  cmdCtx.engine.quit();
}

void cmd_time(CommandContext &cmdCtx, const Console::Args) {
  cmdCtx.engine.time().elapsed();
}

float stringToFloat(const std::string &s) {
  float result = 0.0f;
  float divisor = 1.0f;

  bool negative = false;
  bool decimal = false;

  size_t i = 0;

  if (!s.empty() && s[0] == '-') {
    negative = true;
    i = 1;
  }

  for (; i < s.size(); ++i) {
    char c = s[i];

    if (c == '.') {
      if (decimal)
        break; // second decimal point

      decimal = true;
      continue;
    }

    if (c < '0' || c > '9')
      break;

    int digit = c - '0';

    if (!decimal) {
      result = result * 10.0f + digit;
    } else {
      divisor *= 10.0f;
      result += digit / divisor;
    }
  }

  return negative ? -result : result;
}

void cmd_timescale(CommandContext &cmdCtx, const Console::Args &args) {
  if (args.size() == 1) {
    cmdCtx.engine.console().print(
        std::to_string(cmdCtx.engine.time().timescale()));
  } else {
    float f = stringToFloat(args.at(1));
    cmdCtx.engine.time().timescale(f);
  }
}
