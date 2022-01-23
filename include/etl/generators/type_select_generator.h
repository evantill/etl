/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/ETLCPP/etl
https://www.etlcpp.com

Copyright(c) 2018 jwellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#ifndef ETL_TYPE_SELECT_INCLUDED
#define ETL_TYPE_SELECT_INCLUDED

#include "platform.h"
#include "static_assert.h"
#include "type_traits.h"
#include "null_type.h"

/*[[[cog
import cog
cog.outl("#if 0")
]]]*/
/*[[[end]]]*/
#error THIS HEADER IS A GENERATOR. DO NOT INCLUDE.
/*[[[cog
import cog
cog.outl("#endif")
]]]*/
/*[[[end]]]*/

/*[[[cog
import cog
cog.outl("//***************************************************************************")
cog.outl("// THIS FILE HAS BEEN AUTO GENERATED. DO NOT EDIT THIS FILE.")
cog.outl("//***************************************************************************")
]]]*/
/*[[[end]]]*/

namespace etl
{
#if ETL_CPP11_SUPPORTED && !defined(ETL_TYPE_SELECT_FORCE_CPP03_IMPLEMENTATION)
  //***************************************************************************
  // Variadic version.
  //***************************************************************************
  template <typename... TTypes>
  struct type_select
  {
  private:

    //***********************************
    template <size_t ID, size_t N, typename T1, typename... TRest>
    struct type_select_helper
    {
      using type = typename etl::conditional<ID == N,
                                             T1,
                                             typename type_select_helper<ID, N + 1, TRest...>::type>::type;
    };

    //***********************************
    template <size_t ID, size_t N, typename T1>
    struct type_select_helper<ID, N, T1>
    {
      using type = T1;
    };

  public:

    template <size_t ID>
    struct select
    {
      static_assert(ID < sizeof...(TTypes), "Illegal type_select::select index");

      using type = typename type_select_helper<ID, 0, TTypes...>::type;
    };

#if ETL_CPP11_SUPPORTED
    template <size_t ID>
    using select_t = typename select<ID>::type;
#endif
  };

#else

  /*[[[cog
  import cog
  cog.outl("//***************************************************************************")
  cog.outl("// For %s types." % int(NTypes))
  cog.outl("//***************************************************************************")
  cog.outl("template <typename T0,")
  for n in range(1, int(NTypes) - 1):
      cog.outl("          typename T%s = void," % n)
  cog.outl("          typename T%s = void>" %(int(NTypes) - 1))
  cog.outl("struct type_select")
  cog.outl("{")
  cog.outl("public:")
  cog.outl("")
  cog.outl("  template <const size_t ID>")
  cog.outl("  struct select")
  cog.outl("  {")
  cog.outl("    typedef typename etl::conditional<ID == 0, T0,")
  for n in range(1, int(NTypes)) :
      cog.outl("            typename etl::conditional<ID == %s, T%s," % (n, n))
  cog.outl("            etl::null_type<0> >")
  cog.out("            ")
  for n in range(1, int(NTypes)) :
      cog.out("::type>")
      if n % 8 == 0:
          cog.outl("")
          cog.out("            ")
  cog.outl("::type type;")
  cog.outl("");
  cog.outl("    ETL_STATIC_ASSERT(ID < %s, \"Invalid ID\");" % int(NTypes));
  cog.outl("  };")
  cog.outl("};")

  for s in range(int(NTypes) - 1, 0, -1):
      cog.outl("")
      cog.outl("//***************************************************************************")
      cog.outl("// For %s types." % int(s))
      cog.outl("//***************************************************************************")
      cog.out("template <")
      for n in range(0, s - 1):
          cog.outl("typename T%s, " % n)
          cog.out("          ")
      cog.outl("typename T%s>" % (s - 1))
      cog.out("struct type_select<")
      for n in range(0, s - 1):
          cog.out("T%s, " % n)
      cog.outl("T%s>" % (s - 1))
      cog.outl("{")
      cog.outl("public:")
      cog.outl("  template <const size_t ID>")
      cog.outl("  struct select")
      cog.outl("  {")
      cog.outl("    typedef typename etl::conditional<ID == 0, T0,")
      for n in range(1, s) :
          cog.outl("            typename etl::conditional<ID == %s, T%s," % (n, n))
      cog.outl("            etl::null_type<0> >")
      cog.out("            ")
      for n in range(1, s) :
          cog.out("::type>")
          if n % 8 == 0:
            cog.outl("")
            cog.out("            ")
      cog.outl("::type type;")
      cog.outl("");
      cog.outl("    ETL_STATIC_ASSERT(ID < %s, \"Invalid ID\");" % s);
      cog.outl("  };")
      cog.outl("};")
  ]]]*/
  /*[[[end]]]*/
#endif
}

#endif
