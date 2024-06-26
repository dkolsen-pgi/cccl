//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// test ratio_multiply

#include <cuda/std/ratio>

int main(int, char**)
{
  {
    typedef cuda::std::ratio<1, 1> R1;
    typedef cuda::std::ratio<1, 1> R2;
    typedef cuda::std::ratio_multiply<R1, R2>::type R;
    static_assert(R::num == 1 && R::den == 1, "");
  }
  {
    typedef cuda::std::ratio<1, 2> R1;
    typedef cuda::std::ratio<1, 1> R2;
    typedef cuda::std::ratio_multiply<R1, R2>::type R;
    static_assert(R::num == 1 && R::den == 2, "");
  }
  {
    typedef cuda::std::ratio<-1, 2> R1;
    typedef cuda::std::ratio<1, 1> R2;
    typedef cuda::std::ratio_multiply<R1, R2>::type R;
    static_assert(R::num == -1 && R::den == 2, "");
  }
  {
    typedef cuda::std::ratio<1, -2> R1;
    typedef cuda::std::ratio<1, 1> R2;
    typedef cuda::std::ratio_multiply<R1, R2>::type R;
    static_assert(R::num == -1 && R::den == 2, "");
  }
  {
    typedef cuda::std::ratio<1, 2> R1;
    typedef cuda::std::ratio<-1, 1> R2;
    typedef cuda::std::ratio_multiply<R1, R2>::type R;
    static_assert(R::num == -1 && R::den == 2, "");
  }
  {
    typedef cuda::std::ratio<1, 2> R1;
    typedef cuda::std::ratio<1, -1> R2;
    typedef cuda::std::ratio_multiply<R1, R2>::type R;
    static_assert(R::num == -1 && R::den == 2, "");
  }
  {
    typedef cuda::std::ratio<56987354, 467584654> R1;
    typedef cuda::std::ratio<544668, 22145> R2;
    typedef cuda::std::ratio_multiply<R1, R2>::type R;
    static_assert(R::num == 15519594064236LL && R::den == 5177331081415LL, "");
  }

  return 0;
}
