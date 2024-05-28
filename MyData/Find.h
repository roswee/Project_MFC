#pragma once

template<typename T>
int Find(const T* array, int size, const T& value)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i] == value)
            return i;
    }
    return -1;  // Return -1 if value not found
}
