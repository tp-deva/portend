#include <iostream>

#include "engine/engine.hpp"


class LogTest {
public:
    inline std::string to_string() const {
        return "I'm logger test";
    }
};



inline std::ostream& operator<<(std::ostream& os, const LogTest& test)
{
    return os << test.to_string();
}



int main(int , char **)
{
    engine::Logger::init();

    LOGGER_CORE_TRACE("trace Initialized Logging Module!");
    LOGGER_DEBUG("debug Client Logger here!");

    int a = 5;
    LOGGER_INFO("info Var={0}", a);

    LogTest test;
    LOGGER_WARN("warn test = {0}", test);
    LOGGER_ERROR("error {0}", test);
    LOGGER_CRITICAL("critical {0}", test);
}
