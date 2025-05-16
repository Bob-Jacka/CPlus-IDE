#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

enum class Log_level { DEBUG, RELEASE, VERBOSE, WARN };

class Logger
{
    QML_ELEMENT
private:
    Log_level log_level = Log_level::DEBUG;

public:
    Logger();
    ~Logger();

    void log_message(std::string);
    void log_error(std::string);
};

#endif // LOGGER_HPP
