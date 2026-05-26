#pragma once
#include "core/command_context.hpp"
#include "core/console.hpp"

void cmd_clear(CommandContext &frameCtx, const Console::Args &);

void cmd_echo(CommandContext &frameCtx, const Console::Args &args);
