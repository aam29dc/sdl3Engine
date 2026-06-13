#include "io/jsonloader.hpp"

#include <fstream>
#include <sstream>
#include <stdexcept>

std::string JsonLoader::loadText(const std::string &path) {
  std::ifstream file(path);

  if (!file) {
    throw std::runtime_error("failed to open: " + path);
  }

  std::stringstream buffer;
  buffer << file.rdbuf();

  return buffer.str();
}
