#ifndef ENGINE_ENTITY_HPP
#define ENGINE_ENTITY_HPP

#include "engine/ECSEngine/IEntity.hpp"
#include "engine/ECSEngine/utility/TypeIdCount.hpp"

namespace engine {

template<class E>
class Entity : public IEntity {
public:
    Entity() {
    }

    virtual ~Entity() {
    }

    virtual const EntityTypeId get_static_entity_type_id() const override {
        return s_entity_type_id;
    }

protected:
    static const EntityTypeId s_entity_type_id;
};


template<class E>
const EntityTypeId Entity<E>::s_entity_type_id = TypeIdCount<IEntity>::get<E>();

} // namespace engine

#endif // ENGINE_ENTITY_HPP
