#include <string>

namespace log_line {
std::string message(std::string line) {
    // return the message
    size_t pos = line.find(": ");
    return line.substr(pos + 2);
}

std::string log_level(std::string line) {
    // return the log level
    size_t pos1 = line.find('[');
    size_t pos2 = line.find(']');
    return line.substr(pos1+1, pos2 - pos1-1);
}

std::string reformat(std::string line) {
    // return the reformatted message
    return message(line) + " (" + log_level(line) + ")";
}
}  // namespace log_line
