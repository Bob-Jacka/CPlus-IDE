#include "logger.hpp"
#include "IdeSettings.hpp"
#include "UtilFuncs.hpp"

Logger::Logger()
{
    println("Logger created");
}

Logger::~Logger()
{
    //
}

Logger::log_message(std::string text)
{
    if (is_file_write) {
        //
    } else {
        println(text);
    }
}

Logger::log_error(std::string text)
{
    if (is_file_write) {
        //
    } else {
        println(text);
    }
}
