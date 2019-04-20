#include "engine/ECSEngine/utility/TypeIdCount.hpp"


namespace engine {

class IEntity;
class IComponent;
class ISystem;

template class TypeIdCount<IEntity>;
template class TypeIdCount<IComponent>;
template class TypeIdCount<ISystem>;

template<>
unsigned TypeIdCount<IEntity>::s_type_count    = 0u;
template<>
unsigned TypeIdCount<IComponent>::s_type_count = 0u;
template<>
unsigned TypeIdCount<ISystem>::s_type_count    = 0u;

} // namespace engine
