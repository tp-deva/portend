#ifndef ENGINE_APPLICATION_HPP
#define ENGINE_APPLICATION_HPP

#include <memory>

#include "engine/Window/IWindow.hpp"
#include "engine/Application/LayerChain.hpp"

namespace engine {

class Application {
public:
    virtual ~Application();

    static inline Application& get_instance() {
        static Application s_instance;
        return s_instance;
    }

    inline IWindow& get_window() {
        return *m_window;
    }

    void push_layer(ILayer* layer);
    void push_overlay(ILayer* overlay);

    void on_event(IEvent& event);

    void run();

private:
    bool m_running = true;
    std::unique_ptr<IWindow> m_window;
    LayerChain m_layer_chain;

private:
    Application();
};

} // namespace engine

#endif // ENGINE_APPLICATION_HPP
