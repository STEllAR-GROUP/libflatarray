/**
 * Copyright 2014-2016 Andreas Schäfer
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef FLAT_ARRAY_DETAIL_SHORT_VEC_SCALAR_DOUBLE_32_HPP
#define FLAT_ARRAY_DETAIL_SHORT_VEC_SCALAR_DOUBLE_32_HPP

#if (LIBFLATARRAY_WIDEST_VECTOR_ISA == LIBFLATARRAY_SCALAR) ||  \
    (LIBFLATARRAY_WIDEST_VECTOR_ISA == LIBFLATARRAY_ARM_NEON)

#include <libflatarray/config.h>

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
class short_vec<double, 32>
{
public:
    static const std::size_t ARITY = 32;
    typedef unsigned mask_type;
    typedef short_vec_strategy::scalar strategy;

    template<typename _CharT, typename _Traits>
    friend std::basic_ostream<_CharT, _Traits>& operator<<(
        std::basic_ostream<_CharT, _Traits>& __os,
        const short_vec<double, 32>& vec);

    inline
    short_vec(const double data = 0) :
        val1(data),
        val2(data),
        val3(data),
        val4(data),
        val5(data),
        val6(data),
        val7(data),
        val8(data),
        val9(data),
        val10(data),
        val11(data),
        val12(data),
        val13(data),
        val14(data),
        val15(data),
        val16(data),
        val17(data),
        val18(data),
        val19(data),
        val20(data),
        val21(data),
        val22(data),
        val23(data),
        val24(data),
        val25(data),
        val26(data),
        val27(data),
        val28(data),
        val29(data),
        val30(data),
        val31(data),
        val32(data)
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
        const double val8,
        const double val9,
        const double val10,
        const double val11,
        const double val12,
        const double val13,
        const double val14,
        const double val15,
        const double val16,
        const double val17,
        const double val18,
        const double val19,
        const double val20,
        const double val21,
        const double val22,
        const double val23,
        const double val24,
        const double val25,
        const double val26,
        const double val27,
        const double val28,
        const double val29,
        const double val30,
        const double val31,
        const double val32) :
        val1( val1),
        val2( val2),
        val3( val3),
        val4( val4),
        val5( val5),
        val6( val6),
        val7( val7),
        val8( val8),
        val9( val9),
        val10(val10),
        val11(val11),
        val12(val12),
        val13(val13),
        val14(val14),
        val15(val15),
        val16(val16),
        val17(val17),
        val18(val18),
        val19(val19),
        val20(val20),
        val21(val21),
        val22(val22),
        val23(val23),
        val24(val24),
        val25(val25),
        val26(val26),
        val27(val27),
        val28(val28),
        val29(val29),
        val30(val30),
        val31(val31),
        val32(val32)
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
            val8 ||
            val9 ||
            val10 ||
            val11 ||
            val12 ||
            val13 ||
            val14 ||
            val15 ||
            val16 ||
            val17 ||
            val18 ||
            val19 ||
            val20 ||
            val21 ||
            val22 ||
            val23 ||
            val24 ||
            val25 ||
            val26 ||
            val27 ||
            val28 ||
            val29 ||
            val30 ||
            val31 ||
            val32;
    }

    inline
    double get(const int i) const
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
        case 7:
            return val8;
        case 8:
            return val9;
        case 9:
            return val10;
        case 10:
            return val11;
        case 11:
            return val12;
        case 12:
            return val13;
        case 13:
            return val14;
        case 14:
            return val15;
        case 15:
            return val16;
        case 16:
            return val17;
        case 17:
            return val18;
        case 18:
            return val19;
        case 19:
            return val20;
        case 20:
            return val21;
        case 21:
            return val22;
        case 22:
            return val23;
        case 23:
            return val24;
        case 24:
            return val25;
        case 25:
            return val26;
        case 26:
            return val27;
        case 27:
            return val28;
        case 28:
            return val29;
        case 29:
            return val30;
        case 30:
            return val31;
        default:
            return val32;
        }
    }

    inline
    void operator-=(const short_vec<double, 32>& other)
    {
        val1  -= other.val1;
        val2  -= other.val2;
        val3  -= other.val3;
        val4  -= other.val4;
        val5  -= other.val5;
        val6  -= other.val6;
        val7  -= other.val7;
        val8  -= other.val8;
        val9  -= other.val9;
        val10 -= other.val10;
        val11 -= other.val11;
        val12 -= other.val12;
        val13 -= other.val13;
        val14 -= other.val14;
        val15 -= other.val15;
        val16 -= other.val16;
        val17 -= other.val17;
        val18 -= other.val18;
        val19 -= other.val19;
        val20 -= other.val20;
        val21 -= other.val21;
        val22 -= other.val22;
        val23 -= other.val23;
        val24 -= other.val24;
        val25 -= other.val25;
        val26 -= other.val26;
        val27 -= other.val27;
        val28 -= other.val28;
        val29 -= other.val29;
        val30 -= other.val30;
        val31 -= other.val31;
        val32 -= other.val32;
    }

    inline
    short_vec<double, 32> operator-(const short_vec<double, 32>& other) const
    {
        return short_vec<double, 32>(
            val1  - other.val1,
            val2  - other.val2,
            val3  - other.val3,
            val4  - other.val4,
            val5  - other.val5,
            val6  - other.val6,
            val7  - other.val7,
            val8  - other.val8,
            val9  - other.val9,
            val10 - other.val10,
            val11 - other.val11,
            val12 - other.val12,
            val13 - other.val13,
            val14 - other.val14,
            val15 - other.val15,
            val16 - other.val16,
            val17 - other.val17,
            val18 - other.val18,
            val19 - other.val19,
            val20 - other.val20,
            val21 - other.val21,
            val22 - other.val22,
            val23 - other.val23,
            val24 - other.val24,
            val25 - other.val25,
            val26 - other.val26,
            val27 - other.val27,
            val28 - other.val28,
            val29 - other.val29,
            val30 - other.val30,
            val31 - other.val31,
            val32 - other.val32);
    }

    inline
    void operator+=(const short_vec<double, 32>& other)
    {
        val1  += other.val1;
        val2  += other.val2;
        val3  += other.val3;
        val4  += other.val4;
        val5  += other.val5;
        val6  += other.val6;
        val7  += other.val7;
        val8  += other.val8;
        val9  += other.val9;
        val10 += other.val10;
        val11 += other.val11;
        val12 += other.val12;
        val13 += other.val13;
        val14 += other.val14;
        val15 += other.val15;
        val16 += other.val16;
        val17 += other.val17;
        val18 += other.val18;
        val19 += other.val19;
        val20 += other.val20;
        val21 += other.val21;
        val22 += other.val22;
        val23 += other.val23;
        val24 += other.val24;
        val25 += other.val25;
        val26 += other.val26;
        val27 += other.val27;
        val28 += other.val28;
        val29 += other.val29;
        val30 += other.val30;
        val31 += other.val31;
        val32 += other.val32;
    }

    inline
    short_vec<double, 32> operator+(const short_vec<double, 32>& other) const
    {
        return short_vec<double, 32>(
            val1  + other.val1,
            val2  + other.val2,
            val3  + other.val3,
            val4  + other.val4,
            val5  + other.val5,
            val6  + other.val6,
            val7  + other.val7,
            val8  + other.val8,
            val9  + other.val9,
            val10 + other.val10,
            val11 + other.val11,
            val12 + other.val12,
            val13 + other.val13,
            val14 + other.val14,
            val15 + other.val15,
            val16 + other.val16,
            val17 + other.val17,
            val18 + other.val18,
            val19 + other.val19,
            val20 + other.val20,
            val21 + other.val21,
            val22 + other.val22,
            val23 + other.val23,
            val24 + other.val24,
            val25 + other.val25,
            val26 + other.val26,
            val27 + other.val27,
            val28 + other.val28,
            val29 + other.val29,
            val30 + other.val30,
            val31 + other.val31,
            val32 + other.val32);
    }

    inline
    void operator*=(const short_vec<double, 32>& other)
    {
        val1  *= other.val1;
        val2  *= other.val2;
        val3  *= other.val3;
        val4  *= other.val4;
        val5  *= other.val5;
        val6  *= other.val6;
        val7  *= other.val7;
        val8  *= other.val8;
        val9  *= other.val9;
        val10 *= other.val10;
        val11 *= other.val11;
        val12 *= other.val12;
        val13 *= other.val13;
        val14 *= other.val14;
        val15 *= other.val15;
        val16 *= other.val16;
        val17 *= other.val17;
        val18 *= other.val18;
        val19 *= other.val19;
        val20 *= other.val20;
        val21 *= other.val21;
        val22 *= other.val22;
        val23 *= other.val23;
        val24 *= other.val24;
        val25 *= other.val25;
        val26 *= other.val26;
        val27 *= other.val27;
        val28 *= other.val28;
        val29 *= other.val29;
        val30 *= other.val30;
        val31 *= other.val31;
        val32 *= other.val32;
    }

    inline
    short_vec<double, 32> operator*(const short_vec<double, 32>& other) const
    {
        return short_vec<double, 32>(
            val1  * other.val1,
            val2  * other.val2,
            val3  * other.val3,
            val4  * other.val4,
            val5  * other.val5,
            val6  * other.val6,
            val7  * other.val7,
            val8  * other.val8,
            val9  * other.val9,
            val10 * other.val10,
            val11 * other.val11,
            val12 * other.val12,
            val13 * other.val13,
            val14 * other.val14,
            val15 * other.val15,
            val16 * other.val16,
            val17 * other.val17,
            val18 * other.val18,
            val19 * other.val19,
            val20 * other.val20,
            val21 * other.val21,
            val22 * other.val22,
            val23 * other.val23,
            val24 * other.val24,
            val25 * other.val25,
            val26 * other.val26,
            val27 * other.val27,
            val28 * other.val28,
            val29 * other.val29,
            val30 * other.val30,
            val31 * other.val31,
            val32 * other.val32);
    }

    inline
    void operator/=(const short_vec<double, 32>& other)
    {
        val1  /= other.val1;
        val2  /= other.val2;
        val3  /= other.val3;
        val4  /= other.val4;
        val5  /= other.val5;
        val6  /= other.val6;
        val7  /= other.val7;
        val8  /= other.val8;
        val9  /= other.val9;
        val10 /= other.val10;
        val11 /= other.val11;
        val12 /= other.val12;
        val13 /= other.val13;
        val14 /= other.val14;
        val15 /= other.val15;
        val16 /= other.val16;
        val17 /= other.val17;
        val18 /= other.val18;
        val19 /= other.val19;
        val20 /= other.val20;
        val21 /= other.val21;
        val22 /= other.val22;
        val23 /= other.val23;
        val24 /= other.val24;
        val25 /= other.val25;
        val26 /= other.val26;
        val27 /= other.val27;
        val28 /= other.val28;
        val29 /= other.val29;
        val30 /= other.val30;
        val31 /= other.val31;
        val32 /= other.val32;
    }

    inline
    short_vec<double, 32> operator/(const short_vec<double, 32>& other) const
    {
        return short_vec<double, 32>(
            val1  / other.val1,
            val2  / other.val2,
            val3  / other.val3,
            val4  / other.val4,
            val5  / other.val5,
            val6  / other.val6,
            val7  / other.val7,
            val8  / other.val8,
            val9  / other.val9,
            val10 / other.val10,
            val11 / other.val11,
            val12 / other.val12,
            val13 / other.val13,
            val14 / other.val14,
            val15 / other.val15,
            val16 / other.val16,
            val17 / other.val17,
            val18 / other.val18,
            val19 / other.val19,
            val20 / other.val20,
            val21 / other.val21,
            val22 / other.val22,
            val23 / other.val23,
            val24 / other.val24,
            val25 / other.val25,
            val26 / other.val26,
            val27 / other.val27,
            val28 / other.val28,
            val29 / other.val29,
            val30 / other.val30,
            val31 / other.val31,
            val32 / other.val32);
    }

#define LFA_SHORTVEC_COMPARE_HELPER(V1, V2, OP) ((V1) OP (V2))
    inline
    mask_type operator<(const short_vec<double, 32>& other) const
    {
        return
            (LFA_SHORTVEC_COMPARE_HELPER(val1,  other.val1,  <) <<  0) +
            (LFA_SHORTVEC_COMPARE_HELPER(val2,  other.val2,  <) <<  1) +
            (LFA_SHORTVEC_COMPARE_HELPER(val3,  other.val3,  <) <<  2) +
            (LFA_SHORTVEC_COMPARE_HELPER(val4,  other.val4,  <) <<  3) +
            (LFA_SHORTVEC_COMPARE_HELPER(val5,  other.val5,  <) <<  4) +
            (LFA_SHORTVEC_COMPARE_HELPER(val6,  other.val6,  <) <<  5) +
            (LFA_SHORTVEC_COMPARE_HELPER(val7,  other.val7,  <) <<  6) +
            (LFA_SHORTVEC_COMPARE_HELPER(val8,  other.val8,  <) <<  7) +
            (LFA_SHORTVEC_COMPARE_HELPER(val9,  other.val9,  <) <<  8) +
            (LFA_SHORTVEC_COMPARE_HELPER(val10, other.val10, <) <<  9) +
            (LFA_SHORTVEC_COMPARE_HELPER(val11, other.val11, <) << 10) +
            (LFA_SHORTVEC_COMPARE_HELPER(val12, other.val12, <) << 11) +
            (LFA_SHORTVEC_COMPARE_HELPER(val13, other.val13, <) << 12) +
            (LFA_SHORTVEC_COMPARE_HELPER(val14, other.val14, <) << 13) +
            (LFA_SHORTVEC_COMPARE_HELPER(val15, other.val15, <) << 14) +
            (LFA_SHORTVEC_COMPARE_HELPER(val16, other.val16, <) << 15) +
            (LFA_SHORTVEC_COMPARE_HELPER(val17, other.val17, <) << 16) +
            (LFA_SHORTVEC_COMPARE_HELPER(val18, other.val18, <) << 17) +
            (LFA_SHORTVEC_COMPARE_HELPER(val19, other.val19, <) << 18) +
            (LFA_SHORTVEC_COMPARE_HELPER(val20, other.val20, <) << 19) +
            (LFA_SHORTVEC_COMPARE_HELPER(val21, other.val21, <) << 20) +
            (LFA_SHORTVEC_COMPARE_HELPER(val22, other.val22, <) << 21) +
            (LFA_SHORTVEC_COMPARE_HELPER(val23, other.val23, <) << 22) +
            (LFA_SHORTVEC_COMPARE_HELPER(val24, other.val24, <) << 23) +
            (LFA_SHORTVEC_COMPARE_HELPER(val25, other.val25, <) << 24) +
            (LFA_SHORTVEC_COMPARE_HELPER(val26, other.val26, <) << 25) +
            (LFA_SHORTVEC_COMPARE_HELPER(val27, other.val27, <) << 26) +
            (LFA_SHORTVEC_COMPARE_HELPER(val28, other.val28, <) << 27) +
            (LFA_SHORTVEC_COMPARE_HELPER(val29, other.val29, <) << 28) +
            (LFA_SHORTVEC_COMPARE_HELPER(val30, other.val30, <) << 29) +
            (LFA_SHORTVEC_COMPARE_HELPER(val31, other.val31, <) << 30) +
            (LFA_SHORTVEC_COMPARE_HELPER(val32, other.val32, <) << 31);
    }

    inline
    mask_type operator<=(const short_vec<double, 32>& other) const
    {
        return
            (LFA_SHORTVEC_COMPARE_HELPER(val1,  other.val1,  <=) <<  0) +
            (LFA_SHORTVEC_COMPARE_HELPER(val2,  other.val2,  <=) <<  1) +
            (LFA_SHORTVEC_COMPARE_HELPER(val3,  other.val3,  <=) <<  2) +
            (LFA_SHORTVEC_COMPARE_HELPER(val4,  other.val4,  <=) <<  3) +
            (LFA_SHORTVEC_COMPARE_HELPER(val5,  other.val5,  <=) <<  4) +
            (LFA_SHORTVEC_COMPARE_HELPER(val6,  other.val6,  <=) <<  5) +
            (LFA_SHORTVEC_COMPARE_HELPER(val7,  other.val7,  <=) <<  6) +
            (LFA_SHORTVEC_COMPARE_HELPER(val8,  other.val8,  <=) <<  7) +
            (LFA_SHORTVEC_COMPARE_HELPER(val9,  other.val9,  <=) <<  8) +
            (LFA_SHORTVEC_COMPARE_HELPER(val10, other.val10, <=) <<  9) +
            (LFA_SHORTVEC_COMPARE_HELPER(val11, other.val11, <=) << 10) +
            (LFA_SHORTVEC_COMPARE_HELPER(val12, other.val12, <=) << 11) +
            (LFA_SHORTVEC_COMPARE_HELPER(val13, other.val13, <=) << 12) +
            (LFA_SHORTVEC_COMPARE_HELPER(val14, other.val14, <=) << 13) +
            (LFA_SHORTVEC_COMPARE_HELPER(val15, other.val15, <=) << 14) +
            (LFA_SHORTVEC_COMPARE_HELPER(val16, other.val16, <=) << 15) +
            (LFA_SHORTVEC_COMPARE_HELPER(val17, other.val17, <=) << 16) +
            (LFA_SHORTVEC_COMPARE_HELPER(val18, other.val18, <=) << 17) +
            (LFA_SHORTVEC_COMPARE_HELPER(val19, other.val19, <=) << 18) +
            (LFA_SHORTVEC_COMPARE_HELPER(val20, other.val20, <=) << 19) +
            (LFA_SHORTVEC_COMPARE_HELPER(val21, other.val21, <=) << 20) +
            (LFA_SHORTVEC_COMPARE_HELPER(val22, other.val22, <=) << 21) +
            (LFA_SHORTVEC_COMPARE_HELPER(val23, other.val23, <=) << 22) +
            (LFA_SHORTVEC_COMPARE_HELPER(val24, other.val24, <=) << 23) +
            (LFA_SHORTVEC_COMPARE_HELPER(val25, other.val25, <=) << 24) +
            (LFA_SHORTVEC_COMPARE_HELPER(val26, other.val26, <=) << 25) +
            (LFA_SHORTVEC_COMPARE_HELPER(val27, other.val27, <=) << 26) +
            (LFA_SHORTVEC_COMPARE_HELPER(val28, other.val28, <=) << 27) +
            (LFA_SHORTVEC_COMPARE_HELPER(val29, other.val29, <=) << 28) +
            (LFA_SHORTVEC_COMPARE_HELPER(val30, other.val30, <=) << 29) +
            (LFA_SHORTVEC_COMPARE_HELPER(val31, other.val31, <=) << 30) +
            (LFA_SHORTVEC_COMPARE_HELPER(val32, other.val32, <=) << 31);
    }

    inline
    mask_type operator==(const short_vec<double, 32>& other) const
    {
        return
            (LFA_SHORTVEC_COMPARE_HELPER(val1,  other.val1,  ==) <<  0) +
            (LFA_SHORTVEC_COMPARE_HELPER(val2,  other.val2,  ==) <<  1) +
            (LFA_SHORTVEC_COMPARE_HELPER(val3,  other.val3,  ==) <<  2) +
            (LFA_SHORTVEC_COMPARE_HELPER(val4,  other.val4,  ==) <<  3) +
            (LFA_SHORTVEC_COMPARE_HELPER(val5,  other.val5,  ==) <<  4) +
            (LFA_SHORTVEC_COMPARE_HELPER(val6,  other.val6,  ==) <<  5) +
            (LFA_SHORTVEC_COMPARE_HELPER(val7,  other.val7,  ==) <<  6) +
            (LFA_SHORTVEC_COMPARE_HELPER(val8,  other.val8,  ==) <<  7) +
            (LFA_SHORTVEC_COMPARE_HELPER(val9,  other.val9,  ==) <<  8) +
            (LFA_SHORTVEC_COMPARE_HELPER(val10, other.val10, ==) <<  9) +
            (LFA_SHORTVEC_COMPARE_HELPER(val11, other.val11, ==) << 10) +
            (LFA_SHORTVEC_COMPARE_HELPER(val12, other.val12, ==) << 11) +
            (LFA_SHORTVEC_COMPARE_HELPER(val13, other.val13, ==) << 12) +
            (LFA_SHORTVEC_COMPARE_HELPER(val14, other.val14, ==) << 13) +
            (LFA_SHORTVEC_COMPARE_HELPER(val15, other.val15, ==) << 14) +
            (LFA_SHORTVEC_COMPARE_HELPER(val16, other.val16, ==) << 15) +
            (LFA_SHORTVEC_COMPARE_HELPER(val17, other.val17, ==) << 16) +
            (LFA_SHORTVEC_COMPARE_HELPER(val18, other.val18, ==) << 17) +
            (LFA_SHORTVEC_COMPARE_HELPER(val19, other.val19, ==) << 18) +
            (LFA_SHORTVEC_COMPARE_HELPER(val20, other.val20, ==) << 19) +
            (LFA_SHORTVEC_COMPARE_HELPER(val21, other.val21, ==) << 20) +
            (LFA_SHORTVEC_COMPARE_HELPER(val22, other.val22, ==) << 21) +
            (LFA_SHORTVEC_COMPARE_HELPER(val23, other.val23, ==) << 22) +
            (LFA_SHORTVEC_COMPARE_HELPER(val24, other.val24, ==) << 23) +
            (LFA_SHORTVEC_COMPARE_HELPER(val25, other.val25, ==) << 24) +
            (LFA_SHORTVEC_COMPARE_HELPER(val26, other.val26, ==) << 25) +
            (LFA_SHORTVEC_COMPARE_HELPER(val27, other.val27, ==) << 26) +
            (LFA_SHORTVEC_COMPARE_HELPER(val28, other.val28, ==) << 27) +
            (LFA_SHORTVEC_COMPARE_HELPER(val29, other.val29, ==) << 28) +
            (LFA_SHORTVEC_COMPARE_HELPER(val30, other.val30, ==) << 29) +
            (LFA_SHORTVEC_COMPARE_HELPER(val31, other.val31, ==) << 30) +
            (LFA_SHORTVEC_COMPARE_HELPER(val32, other.val32, ==) << 31);
    }

    inline
    mask_type operator>(const short_vec<double, 32>& other) const
    {
        return
            (LFA_SHORTVEC_COMPARE_HELPER(val1,  other.val1,  >) <<  0) +
            (LFA_SHORTVEC_COMPARE_HELPER(val2,  other.val2,  >) <<  1) +
            (LFA_SHORTVEC_COMPARE_HELPER(val3,  other.val3,  >) <<  2) +
            (LFA_SHORTVEC_COMPARE_HELPER(val4,  other.val4,  >) <<  3) +
            (LFA_SHORTVEC_COMPARE_HELPER(val5,  other.val5,  >) <<  4) +
            (LFA_SHORTVEC_COMPARE_HELPER(val6,  other.val6,  >) <<  5) +
            (LFA_SHORTVEC_COMPARE_HELPER(val7,  other.val7,  >) <<  6) +
            (LFA_SHORTVEC_COMPARE_HELPER(val8,  other.val8,  >) <<  7) +
            (LFA_SHORTVEC_COMPARE_HELPER(val9,  other.val9,  >) <<  8) +
            (LFA_SHORTVEC_COMPARE_HELPER(val10, other.val10, >) <<  9) +
            (LFA_SHORTVEC_COMPARE_HELPER(val11, other.val11, >) << 10) +
            (LFA_SHORTVEC_COMPARE_HELPER(val12, other.val12, >) << 11) +
            (LFA_SHORTVEC_COMPARE_HELPER(val13, other.val13, >) << 12) +
            (LFA_SHORTVEC_COMPARE_HELPER(val14, other.val14, >) << 13) +
            (LFA_SHORTVEC_COMPARE_HELPER(val15, other.val15, >) << 14) +
            (LFA_SHORTVEC_COMPARE_HELPER(val16, other.val16, >) << 15) +
            (LFA_SHORTVEC_COMPARE_HELPER(val17, other.val17, >) << 16) +
            (LFA_SHORTVEC_COMPARE_HELPER(val18, other.val18, >) << 17) +
            (LFA_SHORTVEC_COMPARE_HELPER(val19, other.val19, >) << 18) +
            (LFA_SHORTVEC_COMPARE_HELPER(val20, other.val20, >) << 19) +
            (LFA_SHORTVEC_COMPARE_HELPER(val21, other.val21, >) << 20) +
            (LFA_SHORTVEC_COMPARE_HELPER(val22, other.val22, >) << 21) +
            (LFA_SHORTVEC_COMPARE_HELPER(val23, other.val23, >) << 22) +
            (LFA_SHORTVEC_COMPARE_HELPER(val24, other.val24, >) << 23) +
            (LFA_SHORTVEC_COMPARE_HELPER(val25, other.val25, >) << 24) +
            (LFA_SHORTVEC_COMPARE_HELPER(val26, other.val26, >) << 25) +
            (LFA_SHORTVEC_COMPARE_HELPER(val27, other.val27, >) << 26) +
            (LFA_SHORTVEC_COMPARE_HELPER(val28, other.val28, >) << 27) +
            (LFA_SHORTVEC_COMPARE_HELPER(val29, other.val29, >) << 28) +
            (LFA_SHORTVEC_COMPARE_HELPER(val30, other.val30, >) << 29) +
            (LFA_SHORTVEC_COMPARE_HELPER(val31, other.val31, >) << 30) +
            (LFA_SHORTVEC_COMPARE_HELPER(val32, other.val32, >) << 31);
    }

    inline
    mask_type operator>=(const short_vec<double, 32>& other) const
    {
        return
            (LFA_SHORTVEC_COMPARE_HELPER(val1,  other.val1,  >=) <<  0) +
            (LFA_SHORTVEC_COMPARE_HELPER(val2,  other.val2,  >=) <<  1) +
            (LFA_SHORTVEC_COMPARE_HELPER(val3,  other.val3,  >=) <<  2) +
            (LFA_SHORTVEC_COMPARE_HELPER(val4,  other.val4,  >=) <<  3) +
            (LFA_SHORTVEC_COMPARE_HELPER(val5,  other.val5,  >=) <<  4) +
            (LFA_SHORTVEC_COMPARE_HELPER(val6,  other.val6,  >=) <<  5) +
            (LFA_SHORTVEC_COMPARE_HELPER(val7,  other.val7,  >=) <<  6) +
            (LFA_SHORTVEC_COMPARE_HELPER(val8,  other.val8,  >=) <<  7) +
            (LFA_SHORTVEC_COMPARE_HELPER(val9,  other.val9,  >=) <<  8) +
            (LFA_SHORTVEC_COMPARE_HELPER(val10, other.val10, >=) <<  9) +
            (LFA_SHORTVEC_COMPARE_HELPER(val11, other.val11, >=) << 10) +
            (LFA_SHORTVEC_COMPARE_HELPER(val12, other.val12, >=) << 11) +
            (LFA_SHORTVEC_COMPARE_HELPER(val13, other.val13, >=) << 12) +
            (LFA_SHORTVEC_COMPARE_HELPER(val14, other.val14, >=) << 13) +
            (LFA_SHORTVEC_COMPARE_HELPER(val15, other.val15, >=) << 14) +
            (LFA_SHORTVEC_COMPARE_HELPER(val16, other.val16, >=) << 15) +
            (LFA_SHORTVEC_COMPARE_HELPER(val17, other.val17, >=) << 16) +
            (LFA_SHORTVEC_COMPARE_HELPER(val18, other.val18, >=) << 17) +
            (LFA_SHORTVEC_COMPARE_HELPER(val19, other.val19, >=) << 18) +
            (LFA_SHORTVEC_COMPARE_HELPER(val20, other.val20, >=) << 19) +
            (LFA_SHORTVEC_COMPARE_HELPER(val21, other.val21, >=) << 20) +
            (LFA_SHORTVEC_COMPARE_HELPER(val22, other.val22, >=) << 21) +
            (LFA_SHORTVEC_COMPARE_HELPER(val23, other.val23, >=) << 22) +
            (LFA_SHORTVEC_COMPARE_HELPER(val24, other.val24, >=) << 23) +
            (LFA_SHORTVEC_COMPARE_HELPER(val25, other.val25, >=) << 24) +
            (LFA_SHORTVEC_COMPARE_HELPER(val26, other.val26, >=) << 25) +
            (LFA_SHORTVEC_COMPARE_HELPER(val27, other.val27, >=) << 26) +
            (LFA_SHORTVEC_COMPARE_HELPER(val28, other.val28, >=) << 27) +
            (LFA_SHORTVEC_COMPARE_HELPER(val29, other.val29, >=) << 28) +
            (LFA_SHORTVEC_COMPARE_HELPER(val30, other.val30, >=) << 29) +
            (LFA_SHORTVEC_COMPARE_HELPER(val31, other.val31, >=) << 30) +
            (LFA_SHORTVEC_COMPARE_HELPER(val32, other.val32, >=) << 31);
    }
#undef LFA_SHORTVEC_COMPARE_HELPER

    inline
    short_vec<double, 32> sqrt() const
    {
        return short_vec<double, 32>(
            std::sqrt(val1),
            std::sqrt(val2),
            std::sqrt(val3),
            std::sqrt(val4),
            std::sqrt(val5),
            std::sqrt(val6),
            std::sqrt(val7),
            std::sqrt(val8),
            std::sqrt(val9),
            std::sqrt(val10),
            std::sqrt(val11),
            std::sqrt(val12),
            std::sqrt(val13),
            std::sqrt(val14),
            std::sqrt(val15),
            std::sqrt(val16),
            std::sqrt(val17),
            std::sqrt(val18),
            std::sqrt(val19),
            std::sqrt(val20),
            std::sqrt(val21),
            std::sqrt(val22),
            std::sqrt(val23),
            std::sqrt(val24),
            std::sqrt(val25),
            std::sqrt(val26),
            std::sqrt(val27),
            std::sqrt(val28),
            std::sqrt(val29),
            std::sqrt(val30),
            std::sqrt(val31),
            std::sqrt(val32));
    }

    inline
    void load(const double *data)
    {
        val1  = data[ 0];
        val2  = data[ 1];
        val3  = data[ 2];
        val4  = data[ 3];
        val5  = data[ 4];
        val6  = data[ 5];
        val7  = data[ 6];
        val8  = data[ 7];
        val9  = data[ 8];
        val10 = data[ 9];
        val11 = data[10];
        val12 = data[11];
        val13 = data[12];
        val14 = data[13];
        val15 = data[14];
        val16 = data[15];
        val17 = data[16];
        val18 = data[17];
        val19 = data[18];
        val20 = data[19];
        val21 = data[20];
        val22 = data[21];
        val23 = data[22];
        val24 = data[23];
        val25 = data[24];
        val26 = data[25];
        val27 = data[26];
        val28 = data[27];
        val29 = data[28];
        val30 = data[29];
        val31 = data[30];
        val32 = data[31];
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
        *(data +  8) = val9;
        *(data +  9) = val10;
        *(data + 10) = val11;
        *(data + 11) = val12;
        *(data + 12) = val13;
        *(data + 13) = val14;
        *(data + 14) = val15;
        *(data + 15) = val16;
        *(data + 16) = val17;
        *(data + 17) = val18;
        *(data + 18) = val19;
        *(data + 19) = val20;
        *(data + 20) = val21;
        *(data + 21) = val22;
        *(data + 22) = val23;
        *(data + 23) = val24;
        *(data + 24) = val25;
        *(data + 25) = val26;
        *(data + 26) = val27;
        *(data + 27) = val28;
        *(data + 28) = val29;
        *(data + 29) = val30;
        *(data + 30) = val31;
        *(data + 31) = val32;
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
        val1  = ptr[offsets[ 0]];
        val2  = ptr[offsets[ 1]];
        val3  = ptr[offsets[ 2]];
        val4  = ptr[offsets[ 3]];
        val5  = ptr[offsets[ 4]];
        val6  = ptr[offsets[ 5]];
        val7  = ptr[offsets[ 6]];
        val8  = ptr[offsets[ 7]];
        val9  = ptr[offsets[ 8]];
        val10 = ptr[offsets[ 9]];
        val11 = ptr[offsets[10]];
        val12 = ptr[offsets[11]];
        val13 = ptr[offsets[12]];
        val14 = ptr[offsets[13]];
        val15 = ptr[offsets[14]];
        val16 = ptr[offsets[15]];
        val17 = ptr[offsets[16]];
        val18 = ptr[offsets[17]];
        val19 = ptr[offsets[18]];
        val20 = ptr[offsets[19]];
        val21 = ptr[offsets[20]];
        val22 = ptr[offsets[21]];
        val23 = ptr[offsets[22]];
        val24 = ptr[offsets[23]];
        val25 = ptr[offsets[24]];
        val26 = ptr[offsets[25]];
        val27 = ptr[offsets[26]];
        val28 = ptr[offsets[27]];
        val29 = ptr[offsets[28]];
        val30 = ptr[offsets[29]];
        val31 = ptr[offsets[30]];
        val32 = ptr[offsets[31]];
    }

    inline
    void scatter(double *ptr, const int *offsets) const
    {
        ptr[offsets[0]]  = val1;
        ptr[offsets[1]]  = val2;
        ptr[offsets[2]]  = val3;
        ptr[offsets[3]]  = val4;
        ptr[offsets[4]]  = val5;
        ptr[offsets[5]]  = val6;
        ptr[offsets[6]]  = val7;
        ptr[offsets[7]]  = val8;
        ptr[offsets[8]]  = val9;
        ptr[offsets[9]]  = val10;
        ptr[offsets[10]] = val11;
        ptr[offsets[11]] = val12;
        ptr[offsets[12]] = val13;
        ptr[offsets[13]] = val14;
        ptr[offsets[14]] = val15;
        ptr[offsets[15]] = val16;
        ptr[offsets[16]] = val17;
        ptr[offsets[17]] = val18;
        ptr[offsets[18]] = val19;
        ptr[offsets[19]] = val20;
        ptr[offsets[20]] = val21;
        ptr[offsets[21]] = val22;
        ptr[offsets[22]] = val23;
        ptr[offsets[23]] = val24;
        ptr[offsets[24]] = val25;
        ptr[offsets[25]] = val26;
        ptr[offsets[26]] = val27;
        ptr[offsets[27]] = val28;
        ptr[offsets[28]] = val29;
        ptr[offsets[29]] = val30;
        ptr[offsets[30]] = val31;
        ptr[offsets[31]] = val32;
    }

    inline
    void blend(const mask_type& mask, const short_vec<double, 32>& other)
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
        if (mask & (1 << 8)) {
            val9 = other.val9;
        }
        if (mask & (1 << 9)) {
            val10 = other.val10;
        }
        if (mask & (1 << 10)) {
            val11 = other.val11;
        }
        if (mask & (1 << 11)) {
            val12 = other.val12;
        }
        if (mask & (1 << 12)) {
            val13 = other.val13;
        }
        if (mask & (1 << 13)) {
            val14 = other.val14;
        }
        if (mask & (1 << 14)) {
            val15 = other.val15;
        }
        if (mask & (1 << 15)) {
            val16 = other.val16;
        }
        if (mask & (1 << 16)) {
            val17 = other.val17;
        }
        if (mask & (1 << 17)) {
            val18 = other.val18;
        }
        if (mask & (1 << 18)) {
            val19 = other.val19;
        }
        if (mask & (1 << 19)) {
            val20 = other.val20;
        }
        if (mask & (1 << 20)) {
            val21 = other.val21;
        }
        if (mask & (1 << 21)) {
            val22 = other.val22;
        }
        if (mask & (1 << 22)) {
            val23 = other.val23;
        }
        if (mask & (1 << 23)) {
            val24 = other.val24;
        }
        if (mask & (1 << 24)) {
            val25 = other.val25;
        }
        if (mask & (1 << 25)) {
            val26 = other.val26;
        }
        if (mask & (1 << 26)) {
            val27 = other.val27;
        }
        if (mask & (1 << 27)) {
            val28 = other.val28;
        }
        if (mask & (1 << 28)) {
            val29 = other.val29;
        }
        if (mask & (1 << 29)) {
            val30 = other.val30;
        }
        if (mask & (1 << 30)) {
            val31 = other.val31;
        }
        if (mask & (0x80000000)) {
            val32 = other.val32;
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
    double val9;
    double val10;
    double val11;
    double val12;
    double val13;
    double val14;
    double val15;
    double val16;
    double val17;
    double val18;
    double val19;
    double val20;
    double val21;
    double val22;
    double val23;
    double val24;
    double val25;
    double val26;
    double val27;
    double val28;
    double val29;
    double val30;
    double val31;
    double val32;
};

inline
void operator<<(double *data, const short_vec<double, 32>& vec)
{
    vec.store(data);
}

#ifdef __ICC
#pragma warning pop
#endif

inline
short_vec<double, 32> sqrt(const short_vec<double, 32>& vec)
{
    return vec.sqrt();
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<<(std::basic_ostream<_CharT, _Traits>& __os,
           const short_vec<double, 32>& vec)
{
    __os << "["  << vec.val1  << ", " << vec.val2  << ", " << vec.val3  << ", " << vec.val4
         << ", " << vec.val5  << ", " << vec.val6  << ", " << vec.val7  << ", " << vec.val8
         << ", " << vec.val9  << ", " << vec.val10 << ", " << vec.val11 << ", " << vec.val12
         << ", " << vec.val13 << ", " << vec.val14 << ", " << vec.val15 << ", " << vec.val16
         << ", " << vec.val17 << ", " << vec.val18 << ", " << vec.val19 << ", " << vec.val20
         << ", " << vec.val21 << ", " << vec.val22 << ", " << vec.val23 << ", " << vec.val24
         << ", " << vec.val25 << ", " << vec.val26 << ", " << vec.val27 << ", " << vec.val28
         << ", " << vec.val29 << ", " << vec.val30 << ", " << vec.val31 << ", " << vec.val32
         << "]";
    return __os;
}

}

#endif

#endif
