#ifndef FIND_H
#define FIND_H

template <class T, class Key>
T* find(const T* p_begin, const T* p_end, const Key& k) {
    for (const T* it = p_begin; it != p_end; ++it) {
        if (*it == k) {
            return const_cast<T*>(it);
        }
    }
    return nullptr;
}

#endif // FIND_H
