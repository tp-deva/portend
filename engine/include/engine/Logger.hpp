#ifndef ENGINE_LOGGER_HPP
#define ENGINE_LOGGER_HPP

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace engine {

class Logger {
public:
    static void init();

    inline static std::shared_ptr<spdlog::logger>& get_core_logger() {
        return s_core_logger;
    }
    inline static std::shared_ptr<spdlog::logger>& get_client_logger() {
        return s_client_logger;
    }

private:
    static std::shared_ptr<spdlog::logger> s_core_logger;
    static std::shared_ptr<spdlog::logger> s_client_logger;
};

} // namespace engine

// Core logging macros
#define LOGGER_CORE_TRACE(...)    ::engine::Logger::get_core_logger()->trace(__VA_ARGS__)
#define LOGGER_CORE_DEBUG(...)    ::engine::Logger::get_core_logger()->debug(__VA_ARGS__)
#define LOGGER_CORE_INFO(...)     ::engine::Logger::get_core_logger()->info(__VA_ARGS__)
#define LOGGER_CORE_WARN(...)     ::engine::Logger::get_core_logger()->warn(__VA_ARGS__)
#define LOGGER_CORE_ERROR(...)    ::engine::Logger::get_core_logger()->error(__VA_ARGS__)
#define LOGGER_CORE_CRITICAL(...) ::engine::Logger::get_core_logger()->critical(__VA_ARGS__)

// Client logging macros
#define LOGGER_TRACE(...)    ::engine::Logger::get_client_logger()->trace(__VA_ARGS__)
#define LOGGER_DEBUG(...)    ::engine::Logger::get_client_logger()->debug(__VA_ARGS__)
#define LOGGER_INFO(...)     ::engine::Logger::get_client_logger()->info(__VA_ARGS__)
#define LOGGER_WARN(...)     ::engine::Logger::get_client_logger()->warn(__VA_ARGS__)
#define LOGGER_ERROR(...)    ::engine::Logger::get_client_logger()->error(__VA_ARGS__)
#define LOGGER_CRITICAL(...) ::engine::Logger::get_client_logger()->critical(__VA_ARGS__)

// if logging needs to be desabled redefine macros to empty

#endif // ENGINE_LOGGER_HPP
