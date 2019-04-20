#ifndef ENGINE_ILAYER_HPP
#define ENGINE_ILAYER_HPP

#include "engine/Event/IEvent.hpp"

namespace engine {

class ILayer {
public:
    ILayer(const std::string& name = "Layer")
        : m_debug_name(name) {
    }
    virtual ~ILayer() {
    }

    virtual void on_attach();
    virtual void on_detach();
    virtual void on_update();
    virtual void on_render();
    virtual void on_event(IEvent& event);

    inline const std::string& get_name() const {
        return m_debug_name;
    }

protected:
    std::string m_debug_name;
};

} // namespace engine

#endif // ENGINE_ILAYER_HPP
