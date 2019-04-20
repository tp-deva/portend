#ifndef ENGINE_IENTITY_HPP
#define ENGINE_IENTITY_HPP

#include "engine/ECSEngine/ComponentManager.hpp"

namespace engine {

using EntityTypeId = unsigned;
using EntityId = unsigned;

class IEntity {
    friend class EntityManager;

public:
    IEntity()
        : m_active(true) {
    }

    virtual ~IEntity() {
    }

    virtual const EntityTypeId get_static_entity_type_id() const = 0;

    template<class T, class ...P>
    T* add_component(P&&... param) {
        return m_component_manager->add_component<T>(m_entity_id, std::forward<P>(param)...);
    }

    template<class T>
    T* get_component() const {
        return m_component_manager->get_component<T>(m_entity_id);
    }

    template<class T>
    void RemoveComponent() {
        m_component_manager->remove_component<T>(m_entity_id);
    }

    inline bool operator==(const IEntity& r) const {
        return m_entity_id == r.m_entity_id;
    }
    inline bool operator!=(const IEntity& r) const {
        return m_entity_id != r.m_entity_id;
    }
    inline bool operator==(const IEntity* r) const {
        return m_entity_id == r->m_entity_id;
    }
    inline bool operator!=(const IEntity* r) const {
        return m_entity_id != r->m_entity_id;
    }

    inline EntityId get_entity_id() const {
        return m_entity_id;
    }

    void set_active(bool active) {
        if (m_active == active) {
            return;
        }

        if (active == false) {
            on_disable();
        }
        else {
            on_enable();
        }

        m_active = active;
}

    inline bool IsActive() const {
        return m_active;
    }

    virtual void on_enable() {
    }
    virtual void on_disable() {
    }

protected:
    bool m_active;
    EntityId m_entity_id;

private:
    ComponentManager* m_component_manager;
};

} // namespace engine

#endif // ENGINE_IENTITY_HPP
