#pragma once
#include <cstddef>
#include <iostream>

// Moi thanh vien trong nhom tao feature branch, roi lam task duoc
// giao o comment trong cac function. Thanh vien nhom co the tao
// file source code moi, edit file FloatVector.cxx, viet thang vao
// header tuy so thich.
//
// Sau khi cac thanh vien da hoan thanh, nhom truong merge cac
// branch thanh vien vao main, hoac tao 1 dev branch de merge vao,
// sau do tao pull request len upstream (repo goc ma minh fork ve).
//
// Khi merge feature branch vao dev hoac main, neu xay ra conflict
// thi gio tay de co nguoi cuu.

class FloatVector {
public:
        // Thanh vien 1
        FloatVector::FloatVector() {
    _capacity = 10;
    _size = 0;
    _data = new float[_capacity];
}
        FloatVector();  // Tao moi array _data bang new hoac malloc().
void FloatVector::_realloc(size_t new_capacity) {
    float* newData = new float[new_capacity];

    for (size_t i = 0; i < _size; i++) {
        newData[i] = _data[i];
    }

    delete[] _data;
    _data = newData;
    _capacity = new_capacity;
}

void FloatVector::push(float n) {
    if (_size == _capacity) {
        _realloc(_capacity * 2);
    }
    _data[_size++] = n;
}

float FloatVector::pop() {
    if (_size == 0) {
        std::cerr << "Vector rong!\n";
        return 0;
    }
    return _data[--_size];
}

        // Thanh vien 2
        float &operator[](size_t idx);
        float operator[](size_t idx) const;

        // Thanh vien 2 luu y: ham nay thuc hien deep copy. Thay vi
        // chi gan _data cua FloatVector nay vao _data cua FloatVector
        // kia thi phai copy tung phan tu cua FloatVector kia, de tranh
        // bug double free.
        FloatVector &operator=(const FloatVector); // Gan vector nay
                                                   // vao vector kia.

        // Thanh vien 3
        bool operator==(const FloatVector&) const; // So sanh 2 vector.
        FloatVector operator*(float n) const;   // Nhan moi phan tu voi n.
        FloatVector operator+(float n) const;   // Cong moi phan tu voi n.

        // Thanh vien 4 (neu co)
        ~FloatVector(); // Don dep bo nho. Dung delete hoac free() tuy vao
                        // quyet dinh cua thanh vien 1 trong FloatVector().
        size_t get_size() const;
        size_t get_capacity() const;

        bool operator!=(const FloatVector &n) const
        {
                return !(*this == n);
        }

        FloatVector operator-(float n) const
        {
                return *this + (-n);
        }

        FloatVector operator/(float n) const
        {
                return *this * (1.0f/n);
        }
private:
        // Thanh vien 1.
        // Cap lai bo nho moi cho pointer _data. Co the cap truoc
        // bo nho cho nhieu phan tu de tang toc do xu li.
        void _realloc(size_t new_size);

        float *_data;
        size_t _size, _capacity;
};

