template <typename T>
Array<T>::Array() {
    _size = 0;
    _array = new T[0];
};

template <typename T>
Array<T>::Array(unsigned int n) {
    _array = new T[n];
};

template <typename T>
Array<T>::Array(const Array &b) {
    _array = new T[b.size()];
    for (unsigned int i = 0; i < b.size(); i++) {
        _array[i] = b[i];
    }
};

template <typename T>
Array &Array<T>::operator=(const Array &b) {
    if (this != &b) {
        delete[] _array;
        _array = new T[b.size()];
        for (unsigned int i = 0; i < b.size(); i++) {
            _array[i] = b[i];
        }
    }
    return *this;
};

template <typename T>
Array<T>::~Array() {
    delete[] _array;
};