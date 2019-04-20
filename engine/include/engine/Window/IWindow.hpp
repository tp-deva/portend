#ifndef ENGINE_IWINDOW_HPP
#define ENGINE_IWINDOW_HPP

#include <string>
#include <functional>

#include "engine/Event/IEvent.hpp"

namespace engine {

struct WindowProperties {
    std::string title;
    uint width;
    uint height;

    WindowProperties(const std::string& _title = "Default window",
                     uint _width = 1280,
                     uint _height = 720)
        : title(_title)
        , width(_width)
        , height(_height) {
    }
};


class IWindow {
public:
    using EventCallbackFn = std::function<void(IEvent&)>;

    virtual ~IWindow() {
    }

    virtual void on_update() = 0;

    virtual uint get_width() const = 0;
    virtual uint get_height() const = 0;

    virtual void set_event_callback(const EventCallbackFn& callback) = 0;
    virtual void enable_vsync(bool enabled) = 0;

    virtual void* get_native_window() const = 0;

    static IWindow* create_window(const WindowProperties& props = WindowProperties());
};

} // namespace engine

#endif // ENGINE_IWINDOW_HPP
