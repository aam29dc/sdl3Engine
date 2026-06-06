#pragma once
#include "core/console.hpp"
#include "core/context/command.hpp"

void cmd_clear(CommandContext &cmdCtx, const Console::Args &);

void cmd_echo(CommandContext &cmdCtx, const Console::Args &args);
