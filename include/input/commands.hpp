#pragma once
#include "core/context/command.hpp"
#include "input/console.hpp"

void cmd_clear(CommandContext &cmdCtx, const Console::Args &);

void cmd_echo(CommandContext &cmdCtx, const Console::Args &args);

void cmd_quit(CommandContext &cmdCtx, const Console::Args &);

void cmd_time(CommandContext &cmdCtx, const Console::Args);

float stringToFloat(const std::string &s);

void cmd_timescale(CommandContext &cmdCtx, const Console::Args &args);
