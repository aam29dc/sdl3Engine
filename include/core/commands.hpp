#pragma once
#include "core/console.hpp"
#include "core/context/command.hpp"

void cmd_clear(CommandContext &frameCtx, const Console::Args &);

void cmd_echo(CommandContext &frameCtx, const Console::Args &args);
