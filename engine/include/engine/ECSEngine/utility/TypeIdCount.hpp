#ifndef ENGINE_TYPEIDCOUNT_HPP
#define ENGINE_TYPEIDCOUNT_HPP

namespace engine {

template<class T>
class TypeIdCount {
public:
    template<class U>
    static unsigned get() {
        static const unsigned s_type_id(s_type_count++);
        return s_type_id;
	}

    static unsigned get() {
        return s_type_count;
    }

private:
    static unsigned s_type_count;
};

} // namespace engine

#endif // ENGINE_TYPEIDCOUNT_HPP
