#ifndef ENGINE_IEVENT_HPP
#define ENGINE_IEVENT_HPP

#include <string>
#include <functional>

namespace engine {

enum class EventType {
    NONE = 0,
    WINDOW_CLOSE, WINDOW_RESIZE, WINDOW_FOCUS, WINDOW_LOST_FOCUS, WINDOW_MOVED,
    APPLICATION_TICK, APPLICATION_UPDATE, APPLICATION_RENDER,
    KEY_PRESSED, KEY_RELEASED,
    MOUSE_BUTTON_PRESSED, MOUSE_BUTTON_RELEASED, MOUSE_MOVED, MOUSE_SCROLLED,
};


enum EventCategory {
    NONE = 0,
    EVENT_CATEGORY_APPLICATION  = 1 << 0,
    EVENT_CATEGORY_INPUT        = 1 << 1,
    EVENT_CATEGORY_KEYBOARD     = 1 << 2,
    EVENT_CATEGORY_MOUSE        = 1 << 3,
    EVENT_CATEGORY_MOUSE_BUTTON = 1 << 4,
};


class IEvent {
public:
    virtual ~IEvent();

    virtual EventType get_event_type() const = 0;
    virtual const char* get_name() const = 0;
    virtual int get_category_flags() const = 0;

    virtual inline std::string to_string() const {
        return get_name();
    }

    virtual inline void set_handled(bool _handled) {
        handled = _handled;
    }

    inline bool is_handled() const {
        return handled;
    }

    inline bool is_in_category(EventCategory category) {
        return get_category_flags() & category;
    }

protected:
    bool handled = false;
};


inline std::ostream& operator<<(std::ostream& os, const IEvent& e) {
    return os << e.to_string();
}


#define EVENT_CLASS_TYPE(type) \
    static EventType get_static_type() { \
        return EventType::##type; \
    } \
    virtual EventType get_event_type() const override { \
        return get_static_type(); \
    } \
    virtual const char* get_name() const override { \
        return #type; \
    }


#define EVENT_CLASS_CATEGORY(category) \
    virtual int get_category_flags() const override { \
        return category; \
    }

} // namespace engine

#endif // ENGINE_IEVENT_HPP
