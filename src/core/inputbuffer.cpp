#include "core/inputbuffer.hpp"

void InputBuffer::push(const std::string &cmd) { cmds_.push_back(cmd); }

void InputBuffer::clear() { cmds_.clear(); }

const std::vector<std::string> &InputBuffer::commands() const { return cmds_; }

std::vector<std::string> &InputBuffer::commands() { return cmds_; }
