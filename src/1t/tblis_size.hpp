#ifndef _TBLIS_SIZE_HPP_
#define _TBLIS_SIZE_HPP_

#include "tblis_assert.hpp"
#include "tblis_basic_types.hpp"

namespace tblis
{

/*******************************************************************************
 *
 * Storage size helper functions.
 *
 ******************************************************************************/

inline size_t tensor_size(const std::vector<idx_type>& len)
{
    return std::accumulate(len.begin(), len.end(), size_t(1), std::multiplies<size_t>());
}

inline size_t
tensor_storage_size(const std::vector<idx_type>& len, const std::vector<stride_type>& stride)
{
    TBLIS_ASSERT(len.size() == stride.size());

    size_t size = 1;

    for (unsigned i = 0;i < len.size();i++)
    {
        size += std::abs(stride[i])*(len[i]-1);
    }

    return size;
}

}

#endif
