/**
 * Copyright 2014-2016 Andreas Schäfer
 * Copyright 2015 Kurt Kanzenbach
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef FLAT_ARRAY_DETAIL_SHORT_VEC_SCALAR_DOUBLE_8_HPP
#define FLAT_ARRAY_DETAIL_SHORT_VEC_SCALAR_DOUBLE_8_HPP

#if (LIBFLATARRAY_WIDEST_VECTOR_ISA == LIBFLATARRAY_SCALAR) ||  \
    (LIBFLATARRAY_WIDEST_VECTOR_ISA == LIBFLATARRAY_ARM_NEON)

#include <libflatarray/config.h>
#include <libflatarray/short_vec_base.hpp>

#ifdef LIBFLATARRAY_WITH_CPP14
#include <initializer_list>
#endif

namespace LibFlatArray {

template<typename CARGO, std::size_t ARITY>
class short_vec;

#ifdef __ICC
// disabling this warning as implicit type conversion is exactly our goal here:
#pragma warning push
#pragma warning (disable: 2304)
#endif

template<>
class short_vec<double, 8> : public short_vec_base<double, 8>
{
public:
    static const std::size_t ARITY = 8;
    typedef unsigned char mask_type;
    typedef short_vec_strategy::scalar strategy;

    template<typename _CharT, typename _Traits>
    friend std::basic_ostream<_CharT, _Traits>& operator<<(
        std::basic_ostream<_CharT, _Traits>& __os,
        const short_vec<double, 8>& vec);

    inline
    short_vec(const double data = 0) :
        val1(data),
        val2(data),
        val3(data),
        val4(data),
        val5(data),
        val6(data),
        val7(data),
        val8(data)
    {}

    inline
    short_vec(const double *data)
    {
        load(data);
    }

    inline
    short_vec(
        const double val1,
        const double val2,
        const double val3,
        const double val4,
        const double val5,
        const double val6,
        const double val7,
        const double val8) :
        val1( val1),
        val2( val2),
        val3( val3),
        val4( val4),
        val5( val5),
        val6( val6),
        val7( val7),
        val8( val8)
    {}

#ifdef LIBFLATARRAY_WITH_CPP14
    inline
    short_vec(const std::initializer_list<double>& il)
    {
        const double *ptr = static_cast<const double *>(&(*il.begin()));
        load(ptr);
    }
#endif

    inline
    bool any() const
    {
        return
            val1 ||
            val2 ||
            val3 ||
            val4 ||
            val5 ||
            val6 ||
            val7 ||
            val8;
    }

    inline
    double operator[](const int i) const
    {
        switch (i) {
        case 0:
            return val1;
        case 1:
            return val2;
        case 2:
            return val3;
        case 3:
            return val4;
        case 4:
            return val5;
        case 5:
            return val6;
        case 6:
            return val7;
        default:
            return val8;
        }
    }

    inline
    void operator-=(const short_vec<double, 8>& other)
    {
        val1  -= other.val1;
        val2  -= other.val2;
        val3  -= other.val3;
        val4  -= other.val4;
        val5  -= other.val5;
        val6  -= other.val6;
        val7  -= other.val7;
        val8  -= other.val8;
    }

    inline
    short_vec<double, 8> operator-(const short_vec<double, 8>& other) const
    {
        return short_vec<double, 8>(
            val1  - other.val1,
            val2  - other.val2,
            val3  - other.val3,
            val4  - other.val4,
            val5  - other.val5,
            val6  - other.val6,
            val7  - other.val7,
            val8  - other.val8);
    }

    inline
    void operator+=(const short_vec<double, 8>& other)
    {
        val1  += other.val1;
        val2  += other.val2;
        val3  += other.val3;
        val4  += other.val4;
        val5  += other.val5;
        val6  += other.val6;
        val7  += other.val7;
        val8  += other.val8;
    }

    inline
    short_vec<double, 8> operator+(const short_vec<double, 8>& other) const
    {
        return short_vec<double, 8>(
            val1  + other.val1,
            val2  + other.val2,
            val3  + other.val3,
            val4  + other.val4,
            val5  + other.val5,
            val6  + other.val6,
            val7  + other.val7,
            val8  + other.val8);
    }

    inline
    void operator*=(const short_vec<double, 8>& other)
    {
        val1  *= other.val1;
        val2  *= other.val2;
        val3  *= other.val3;
        val4  *= other.val4;
        val5  *= other.val5;
        val6  *= other.val6;
        val7  *= other.val7;
        val8  *= other.val8;
    }

    inline
    short_vec<double, 8> operator*(const short_vec<double, 8>& other) const
    {
        return short_vec<double, 8>(
            val1  * other.val1,
            val2  * other.val2,
            val3  * other.val3,
            val4  * other.val4,
            val5  * other.val5,
            val6  * other.val6,
            val7  * other.val7,
            val8  * other.val8);
    }

    inline
    void operator/=(const short_vec<double, 8>& other)
    {
        val1  /= other.val1;
        val2  /= other.val2;
        val3  /= other.val3;
        val4  /= other.val4;
        val5  /= other.val5;
        val6  /= other.val6;
        val7  /= other.val7;
        val8  /= other.val8;
    }

    inline
    short_vec<double, 8> operator/(const short_vec<double, 8>& other) const
    {
        return short_vec<double, 8>(
            val1  / other.val1,
            val2  / other.val2,
            val3  / other.val3,
            val4  / other.val4,
            val5  / other.val5,
            val6  / other.val6,
            val7  / other.val7,
            val8  / other.val8);
    }

#define LFA_SHORTVEC_COMPARE_HELPER(V1, V2, OP) ((V1) OP (V2))
    inline
    mask_type operator<(const short_vec<double, 8>& other) const
    {
        return
            (LFA_SHORTVEC_COMPARE_HELPER(val1,  other.val1,  <) <<  0) +
            (LFA_SHORTVEC_COMPARE_HELPER(val2,  other.val2,  <) <<  1) +
            (LFA_SHORTVEC_COMPARE_HELPER(val3,  other.val3,  <) <<  2) +
            (LFA_SHORTVEC_COMPARE_HELPER(val4,  other.val4,  <) <<  3) +
            (LFA_SHORTVEC_COMPARE_HELPER(val5,  other.val5,  <) <<  4) +
            (LFA_SHORTVEC_COMPARE_HELPER(val6,  other.val6,  <) <<  5) +
            (LFA_SHORTVEC_COMPARE_HELPER(val7,  other.val7,  <) <<  6) +
            (LFA_SHORTVEC_COMPARE_HELPER(val8,  other.val8,  <) <<  7);
    }

    inline
    mask_type operator<=(const short_vec<double, 8>& other) const
    {
        return
            (LFA_SHORTVEC_COMPARE_HELPER(val1,  other.val1,  <=) <<  0) +
            (LFA_SHORTVEC_COMPARE_HELPER(val2,  other.val2,  <=) <<  1) +
            (LFA_SHORTVEC_COMPARE_HELPER(val3,  other.val3,  <=) <<  2) +
            (LFA_SHORTVEC_COMPARE_HELPER(val4,  other.val4,  <=) <<  3) +
            (LFA_SHORTVEC_COMPARE_HELPER(val5,  other.val5,  <=) <<  4) +
            (LFA_SHORTVEC_COMPARE_HELPER(val6,  other.val6,  <=) <<  5) +
            (LFA_SHORTVEC_COMPARE_HELPER(val7,  other.val7,  <=) <<  6) +
            (LFA_SHORTVEC_COMPARE_HELPER(val8,  other.val8,  <=) <<  7);
    }

    inline
    mask_type operator==(const short_vec<double, 8>& other) const
    {
        return
            (LFA_SHORTVEC_COMPARE_HELPER(val1,  other.val1,  ==) <<  0) +
            (LFA_SHORTVEC_COMPARE_HELPER(val2,  other.val2,  ==) <<  1) +
            (LFA_SHORTVEC_COMPARE_HELPER(val3,  other.val3,  ==) <<  2) +
            (LFA_SHORTVEC_COMPARE_HELPER(val4,  other.val4,  ==) <<  3) +
            (LFA_SHORTVEC_COMPARE_HELPER(val5,  other.val5,  ==) <<  4) +
            (LFA_SHORTVEC_COMPARE_HELPER(val6,  other.val6,  ==) <<  5) +
            (LFA_SHORTVEC_COMPARE_HELPER(val7,  other.val7,  ==) <<  6) +
            (LFA_SHORTVEC_COMPARE_HELPER(val8,  other.val8,  ==) <<  7);
    }

    inline
    mask_type operator>(const short_vec<double, 8>& other) const
    {
        return
            (LFA_SHORTVEC_COMPARE_HELPER(val1,  other.val1,  >) <<  0) +
            (LFA_SHORTVEC_COMPARE_HELPER(val2,  other.val2,  >) <<  1) +
            (LFA_SHORTVEC_COMPARE_HELPER(val3,  other.val3,  >) <<  2) +
            (LFA_SHORTVEC_COMPARE_HELPER(val4,  other.val4,  >) <<  3) +
            (LFA_SHORTVEC_COMPARE_HELPER(val5,  other.val5,  >) <<  4) +
            (LFA_SHORTVEC_COMPARE_HELPER(val6,  other.val6,  >) <<  5) +
            (LFA_SHORTVEC_COMPARE_HELPER(val7,  other.val7,  >) <<  6) +
            (LFA_SHORTVEC_COMPARE_HELPER(val8,  other.val8,  >) <<  7);
    }

    inline
    mask_type operator>=(const short_vec<double, 8>& other) const
    {
        return
            (LFA_SHORTVEC_COMPARE_HELPER(val1,  other.val1,  >=) <<  0) +
            (LFA_SHORTVEC_COMPARE_HELPER(val2,  other.val2,  >=) <<  1) +
            (LFA_SHORTVEC_COMPARE_HELPER(val3,  other.val3,  >=) <<  2) +
            (LFA_SHORTVEC_COMPARE_HELPER(val4,  other.val4,  >=) <<  3) +
            (LFA_SHORTVEC_COMPARE_HELPER(val5,  other.val5,  >=) <<  4) +
            (LFA_SHORTVEC_COMPARE_HELPER(val6,  other.val6,  >=) <<  5) +
            (LFA_SHORTVEC_COMPARE_HELPER(val7,  other.val7,  >=) <<  6) +
            (LFA_SHORTVEC_COMPARE_HELPER(val8,  other.val8,  >=) <<  7);
    }
#undef LFA_SHORTVEC_COMPARE_HELPER

    inline
    short_vec<double, 8> sqrt() const
    {
        return short_vec<double, 8>(
            std::sqrt(val1),
            std::sqrt(val2),
            std::sqrt(val3),
            std::sqrt(val4),
            std::sqrt(val5),
            std::sqrt(val6),
            std::sqrt(val7),
            std::sqrt(val8));
    }

    inline
    void load(const double *data)
    {
        val1 = data[0];
        val2 = data[1];
        val3 = data[2];
        val4 = data[3];
        val5 = data[4];
        val6 = data[5];
        val7 = data[6];
        val8 = data[7];
    }

    inline
    void load_aligned(const double *data)
    {
        load(data);
    }

    inline
    void store(double *data) const
    {
        *(data +  0) = val1;
        *(data +  1) = val2;
        *(data +  2) = val3;
        *(data +  3) = val4;
        *(data +  4) = val5;
        *(data +  5) = val6;
        *(data +  6) = val7;
        *(data +  7) = val8;
    }

    inline
    void store_aligned(double *data) const
    {
        store(data);
    }

    inline
    void store_nt(double *data) const
    {
        store(data);
    }

    inline
    void gather(const double *ptr, const int *offsets)
    {
        val1 = ptr[offsets[0]];
        val2 = ptr[offsets[1]];
        val3 = ptr[offsets[2]];
        val4 = ptr[offsets[3]];
        val5 = ptr[offsets[4]];
        val6 = ptr[offsets[5]];
        val7 = ptr[offsets[6]];
        val8 = ptr[offsets[7]];
    }

    inline
    void scatter(double *ptr, const int *offsets) const
    {
        ptr[offsets[0]] = val1;
        ptr[offsets[1]] = val2;
        ptr[offsets[2]] = val3;
        ptr[offsets[3]] = val4;
        ptr[offsets[4]] = val5;
        ptr[offsets[5]] = val6;
        ptr[offsets[6]] = val7;
        ptr[offsets[7]] = val8;
    }

    inline
    void blend(const mask_type& mask, const short_vec<double, 8>& other)
    {
        if (mask & (1 << 0)) {
            val1 = other.val1;
        }
        if (mask & (1 << 1)) {
            val2 = other.val2;
        }
        if (mask & (1 << 2)) {
            val3 = other.val3;
        }
        if (mask & (1 << 3)) {
            val4 = other.val4;
        }
        if (mask & (1 << 4)) {
            val5 = other.val5;
        }
        if (mask & (1 << 5)) {
            val6 = other.val6;
        }
        if (mask & (1 << 6)) {
            val7 = other.val7;
        }
        if (mask & (1 << 7)) {
            val8 = other.val8;
        }
    }

private:
    double val1;
    double val2;
    double val3;
    double val4;
    double val5;
    double val6;
    double val7;
    double val8;
};

inline
void operator<<(double *data, const short_vec<double, 8>& vec)
{
    vec.store(data);
}

#ifdef __ICC
#pragma warning pop
#endif

inline
short_vec<double, 8> sqrt(const short_vec<double, 8>& vec)
{
    return vec.sqrt();
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<<(std::basic_ostream<_CharT, _Traits>& __os,
           const short_vec<double, 8>& vec)
{
    __os << "["  << vec.val1  << ", " << vec.val2  << ", " << vec.val3  << ", " << vec.val4
         << ", " << vec.val5  << ", " << vec.val6  << ", " << vec.val7  << ", " << vec.val8
         << "]";
    return __os;
}

}

#endif

#endif
