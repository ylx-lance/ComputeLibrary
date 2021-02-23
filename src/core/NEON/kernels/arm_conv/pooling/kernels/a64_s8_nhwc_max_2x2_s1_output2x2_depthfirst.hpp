/*
 * Copyright (c) 2021 Arm Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#pragma once

namespace arm_conv {
namespace pooling {

void a64_s8_nhwc_max_2x2_s1_output2x2_depthfirst_impl(unsigned int, const int8_t *const *const, int8_t *const *const, bool, unsigned int, unsigned int, unsigned int, unsigned int);

struct a64_s8_nhwc_max_2x2_s1_output2x2_depthfirst
{
  typedef int8_t operand_type;
  typedef int8_t return_type;

  typedef void (*kern_type)(unsigned int, const int8_t *const *const, int8_t *const *const, bool, unsigned int, unsigned int, unsigned int, unsigned int);

  constexpr static PoolingType pooling_type(void) { return PoolingType::MAX; }

  constexpr static unsigned int pool_rows(void) { return 2; }
  constexpr static unsigned int pool_cols(void) { return 2; }

  constexpr static unsigned int stride_rows(void) { return 1; }
  constexpr static unsigned int stride_cols(void) { return 1; }

  constexpr static unsigned int out_rows(void) { return 2; }
  constexpr static unsigned int out_cols(void) { return 2; }

  kern_type kernel = a64_s8_nhwc_max_2x2_s1_output2x2_depthfirst_impl;

  a64_s8_nhwc_max_2x2_s1_output2x2_depthfirst(const CPUInfo *) {}
};

}  // namespace pooling
}  // namespace arm_conv
