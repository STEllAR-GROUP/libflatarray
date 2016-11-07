/**
 * Copyright 2014-2016 Andreas Schäfer
 * Copyright 2015 Kurt Kanzenbach
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef FLAT_ARRAY_DETAIL_SHORT_VEC_SSE_DOUBLE_8_HPP
#define FLAT_ARRAY_DETAIL_SHORT_VEC_SSE_DOUBLE_8_HPP

#if (LIBFLATARRAY_WIDEST_VECTOR_ISA == LIBFLATARRAY_SSE) ||             \
    (LIBFLATARRAY_WIDEST_VECTOR_ISA == LIBFLATARRAY_SSE2) ||            \
    (LIBFLATARRAY_WIDEST_VECTOR_ISA == LIBFLATARRAY_SSE4_1)

#include <emmintrin.h>
#include <libflatarray/detail/short_vec_helpers.hpp>
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
class short_vec<double, 8>
{
public:
    static const std::size_t ARITY = 8;
    typedef short_vec<double, 8> mask_type;
    typedef short_vec_strategy::sse strategy;

    template<typename _CharT, typename _Traits>
    friend std::basic_ostream<_CharT, _Traits>& operator<<(
        std::basic_ostream<_CharT, _Traits>& __os,
        const short_vec<double, 8>& vec);

    inline
    short_vec(const double data = 0) :
        val1(_mm_set1_pd(data)),
        val2(_mm_set1_pd(data)),
        val3(_mm_set1_pd(data)),
        val4(_mm_set1_pd(data))
    {}

    inline
    short_vec(const double *data)
    {
        load(data);
    }

    inline
    short_vec(const __m128d& val1, const __m128d& val2, const __m128d& val3, const __m128d& val4) :
        val1(val1),
        val2(val2),
        val3(val3),
        val4(val4)
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
        __m128d buf1 = _mm_or_pd(_mm_or_pd(val1, val2),
                                 _mm_or_pd(val3, val4));

#ifdef __SSE4_1__
        return (0 == _mm_testz_si128(
                    _mm_castpd_si128(buf1),
                    _mm_castpd_si128(buf1)));
#else
        __m128d buf2 = _mm_shuffle_pd(buf1, buf1, 1);
        return _mm_cvtsd_f64(buf1) || _mm_cvtsd_f64(buf2);
#endif
    }

    inline
    double get(int i) const
    {
        __m128d buf;
        if (i < 4) {
            if (i < 2) {
                buf = val1;
            } else {
                buf = val2;
            }
        } else {
            if (i < 6) {
                buf = val3;
            } else {
                buf = val4;
            }
        }

        i &= 1;

        if (i == 0) {
            return _mm_cvtsd_f64(buf);
        }

        buf = _mm_shuffle_pd(buf, buf, 1);
        return _mm_cvtsd_f64(buf);
    }

    inline
    void operator-=(const short_vec<double, 8>& other)
    {
        val1 = _mm_sub_pd(val1, other.val1);
        val2 = _mm_sub_pd(val2, other.val2);
        val3 = _mm_sub_pd(val3, other.val3);
        val4 = _mm_sub_pd(val4, other.val4);
    }

    inline
    short_vec<double, 8> operator-(const short_vec<double, 8>& other) const
    {
        return short_vec<double, 8>(
            _mm_sub_pd(val1, other.val1),
            _mm_sub_pd(val2, other.val2),
            _mm_sub_pd(val3, other.val3),
            _mm_sub_pd(val4, other.val4));
    }

    inline
    void operator+=(const short_vec<double, 8>& other)
    {
        val1 = _mm_add_pd(val1, other.val1);
        val2 = _mm_add_pd(val2, other.val2);
        val3 = _mm_add_pd(val3, other.val3);
        val4 = _mm_add_pd(val4, other.val4);
    }

    inline
    short_vec<double, 8> operator+(const short_vec<double, 8>& other) const
    {
        return short_vec<double, 8>(
            _mm_add_pd(val1, other.val1),
            _mm_add_pd(val2, other.val2),
            _mm_add_pd(val3, other.val3),
            _mm_add_pd(val4, other.val4));
    }

    inline
    void operator*=(const short_vec<double, 8>& other)
    {
        val1 = _mm_mul_pd(val1, other.val1);
        val2 = _mm_mul_pd(val2, other.val2);
        val3 = _mm_mul_pd(val3, other.val3);
        val4 = _mm_mul_pd(val4, other.val4);
    }

    inline
    short_vec<double, 8> operator*(const short_vec<double, 8>& other) const
    {
        return short_vec<double, 8>(
            _mm_mul_pd(val1, other.val1),
            _mm_mul_pd(val2, other.val2),
            _mm_mul_pd(val3, other.val3),
            _mm_mul_pd(val4, other.val4));
    }

    inline
    void operator/=(const short_vec<double, 8>& other)
    {
        val1 = _mm_div_pd(val1, other.val1);
        val2 = _mm_div_pd(val2, other.val2);
        val3 = _mm_div_pd(val3, other.val3);
        val4 = _mm_div_pd(val4, other.val4);
    }

    inline
    short_vec<double, 8> operator/(const short_vec<double, 8>& other) const
    {
        return short_vec<double, 8>(
            _mm_div_pd(val1, other.val1),
            _mm_div_pd(val2, other.val2),
            _mm_div_pd(val3, other.val3),
            _mm_div_pd(val4, other.val4));
    }

    inline
    short_vec<double, 8> operator/(const sqrt_reference<double, 8>& other) const;

    inline
    short_vec<double, 8> operator<(const short_vec<double, 8>& other) const
    {
        return short_vec<double, 8>(
            _mm_cmplt_pd(val1, other.val1),
            _mm_cmplt_pd(val2, other.val2),
            _mm_cmplt_pd(val3, other.val3),
            _mm_cmplt_pd(val4, other.val4));
    }

    inline
    short_vec<double, 8> operator<=(const short_vec<double, 8>& other) const
    {
        return short_vec<double, 8>(
            _mm_cmple_pd(val1, other.val1),
            _mm_cmple_pd(val2, other.val2),
            _mm_cmple_pd(val3, other.val3),
            _mm_cmple_pd(val4, other.val4));
    }

    inline
    short_vec<double, 8> operator==(const short_vec<double, 8>& other) const
    {
        return short_vec<double, 8>(
            _mm_cmpeq_pd(val1, other.val1),
            _mm_cmpeq_pd(val2, other.val2),
            _mm_cmpeq_pd(val3, other.val3),
            _mm_cmpeq_pd(val4, other.val4));
    }

    inline
    short_vec<double, 8> operator>(const short_vec<double, 8>& other) const
    {
        return short_vec<double, 8>(
            _mm_cmpgt_pd(val1, other.val1),
            _mm_cmpgt_pd(val2, other.val2),
            _mm_cmpgt_pd(val3, other.val3),
            _mm_cmpgt_pd(val4, other.val4));
    }

    inline
    short_vec<double, 8> operator>=(const short_vec<double, 8>& other) const
    {
        return short_vec<double, 8>(
            _mm_cmpge_pd(val1, other.val1),
            _mm_cmpge_pd(val2, other.val2),
            _mm_cmpge_pd(val3, other.val3),
            _mm_cmpge_pd(val4, other.val4));
    }

    inline
    short_vec<double, 8> sqrt() const
    {
        return short_vec<double, 8>(
            _mm_sqrt_pd(val1),
            _mm_sqrt_pd(val2),
            _mm_sqrt_pd(val3),
            _mm_sqrt_pd(val4));
    }

    inline
    void load(const double *data)
    {
        val1 = _mm_loadu_pd(data + 0);
        val2 = _mm_loadu_pd(data + 2);
        val3 = _mm_loadu_pd(data + 4);
        val4 = _mm_loadu_pd(data + 6);
    }

    inline
    void load_aligned(const double *data)
    {
        SHORTVEC_ASSERT_ALIGNED(data, 16);
        val1 = _mm_load_pd(data + 0);
        val2 = _mm_load_pd(data + 2);
        val3 = _mm_load_pd(data + 4);
        val4 = _mm_load_pd(data + 6);
    }

    inline
    void store(double *data) const
    {
        _mm_storeu_pd(data + 0, val1);
        _mm_storeu_pd(data + 2, val2);
        _mm_storeu_pd(data + 4, val3);
        _mm_storeu_pd(data + 6, val4);
    }

    inline
    void store_aligned(double *data) const
    {
        SHORTVEC_ASSERT_ALIGNED(data, 16);
        _mm_store_pd(data + 0, val1);
        _mm_store_pd(data + 2, val2);
        _mm_store_pd(data + 4, val3);
        _mm_store_pd(data + 6, val4);
    }

    inline
    void store_nt(double *data) const
    {
        SHORTVEC_ASSERT_ALIGNED(data, 16);
        _mm_stream_pd(data + 0, val1);
        _mm_stream_pd(data + 2, val2);
        _mm_stream_pd(data + 4, val3);
        _mm_stream_pd(data + 6, val4);
    }

    inline
    void gather(const double *ptr, const int *offsets)
    {
        val1 = _mm_loadl_pd(val1, ptr + offsets[0]);
        val1 = _mm_loadh_pd(val1, ptr + offsets[1]);
        val2 = _mm_loadl_pd(val2, ptr + offsets[2]);
        val2 = _mm_loadh_pd(val2, ptr + offsets[3]);
        val3 = _mm_loadl_pd(val3, ptr + offsets[4]);
        val3 = _mm_loadh_pd(val3, ptr + offsets[5]);
        val4 = _mm_loadl_pd(val4, ptr + offsets[6]);
        val4 = _mm_loadh_pd(val4, ptr + offsets[7]);
    }

    inline
    void scatter(double *ptr, const int *offsets) const
    {
        _mm_storel_pd(ptr + offsets[0], val1);
        _mm_storeh_pd(ptr + offsets[1], val1);
        _mm_storel_pd(ptr + offsets[2], val2);
        _mm_storeh_pd(ptr + offsets[3], val2);
        _mm_storel_pd(ptr + offsets[4], val3);
        _mm_storeh_pd(ptr + offsets[5], val3);
        _mm_storel_pd(ptr + offsets[6], val4);
        _mm_storeh_pd(ptr + offsets[7], val4);
    }

    inline
    void blend(const mask_type& mask, const short_vec<double, 8>& other)
    {
#ifdef __SSE4_1__
        val1  = _mm_blendv_pd(val1,  other.val1,  mask.val1);
        val2  = _mm_blendv_pd(val2,  other.val2,  mask.val2);
        val3  = _mm_blendv_pd(val3,  other.val3,  mask.val3);
        val4  = _mm_blendv_pd(val4,  other.val4,  mask.val4);
#else
        val1 = _mm_or_pd(
            _mm_and_pd(mask.val1, other.val1),
            _mm_andnot_pd(mask.val1, val1));
        val2 = _mm_or_pd(
            _mm_and_pd(mask.val2, other.val2),
            _mm_andnot_pd(mask.val2, val2));
        val3 = _mm_or_pd(
            _mm_and_pd(mask.val3, other.val3),
            _mm_andnot_pd(mask.val3, val3));
        val4 = _mm_or_pd(
            _mm_and_pd(mask.val4, other.val4),
            _mm_andnot_pd(mask.val4, val4));
#endif
    }

private:
    __m128d val1;
    __m128d val2;
    __m128d val3;
    __m128d val4;
};

#ifdef __ICC
#pragma warning pop
#endif

inline
void operator<<(double *data, const short_vec<double, 8>& vec)
{
    vec.store(data);
}

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
    const double *data1 = reinterpret_cast<const double *>(&vec.val1);
    const double *data2 = reinterpret_cast<const double *>(&vec.val2);
    const double *data3 = reinterpret_cast<const double *>(&vec.val3);
    const double *data4 = reinterpret_cast<const double *>(&vec.val4);
    __os << "[" << data1[0] << ", " << data1[1]  << ", " << data2[0]  << ", " << data2[1]  << ", " << data3[0]  << ", " << data3[1]  << ", " << data4[0]  << ", " << data4[1] << "]";
    return __os;
}

}

#endif

#endif
