#include "core/commands.hpp"
#include "core/command_context.hpp"
#include "core/engine.hpp"

void cmd_clear(CommandContext &cmdCtx, const Console::Args &) {
  cmdCtx.engine.console().clear();
}

void cmd_echo(CommandContext &cmdCtx, const Console::Args &args) {
  std::string result;

  for (size_t i = 0; i < args.size(); i++) {
    if (i > 1) {
      result += " ";
    }
    result += args[i];
  }
  cmdCtx.engine.console().print(result);
}
