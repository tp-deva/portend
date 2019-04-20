#ifndef ENGINE_EVENTDISPATCHER_HPP
#define ENGINE_EVENTDISPATCHER_HPP

#include "engine/Event/IEvent.hpp"

namespace engine {

class EventDispatcher {
    template<typename T>
    using EventFn = std::function<bool(T&)>;

public:
    EventDispatcher(IEvent& event)
        : m_event(event) {
    }

    template<typename T>
    bool dispatch(EventFn<T> func) {
        if (m_event.get_event_type() == T::get_static_type()) {
            m_event.set_handled(func(reinterpret_cast<T>(m_event)));
            return true;
        }

        return false;
    }

private:
    IEvent& m_event;
};

} // namespace engine

#endif // ENGINE_EVENTDISPATCHER_HPP
