#ifndef ENGINE_SFMLWINDOW_HPP
#define ENGINE_SFMLWINDOW_HPP

#include <SFML/Graphics.hpp>

#include "engine/Window/IWindow.hpp"

namespace engine {

class SFMLWindow : public IWindow {
public:
    SFMLWindow(const WindowProperties& props);
    virtual ~SFMLWindow();

    virtual void on_update() override;

    virtual inline uint get_width() const override {
        return m_window->getSize().x;
    }
    virtual inline uint get_height() const override {
        return m_window->getSize().y;
    }

    virtual inline void set_event_callback(const EventCallbackFn& callback) override {
        m_event_callback = callback;
    }
    virtual void enable_vsync(bool enabled) override;

    virtual inline void* get_native_window() const override {
        return m_window;
    }

private:
    sf::RenderWindow* m_window;
    EventCallbackFn m_event_callback;

};

} // namespace engine

#endif // ENGINE_SFMLWINDOW_HPP
