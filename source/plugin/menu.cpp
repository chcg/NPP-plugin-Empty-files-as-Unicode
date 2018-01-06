#include "menu.hpp"

#include "plugin-singleton.hpp"
#include <stdlib/extension/Size.hpp>            // array_size

using namespace stdlib::ext::type_builders;     // raw_array_
using stdlib::ext::array_size;

namespace {
    raw_array_<menu::Item> menu_items =
    {
        { L"About�", []{ plugin::singleton().cmd_about(); }, 0, false, nullptr },
        {},
        { L"Enabled", []{ plugin::singleton().cmd_set_enabled(); }, 0, false, nullptr },
        { L"Disabled", []{ plugin::singleton().cmd_set_disabled(); }, 0, false, nullptr },
#ifndef NDEBUG
        {},
        { L"Check all", []{ plugin::singleton().cmd_check_all(); }, 0, false, nullptr },
        { L"Show doc info�", []{ plugin::singleton().cmd_show_doc_info(); }, 0, false, nullptr },
#endif
    };
}  // namespace <anon>

namespace impl {

    template< class Result, class Type >
    constexpr inline auto array_size_( Type const& a )
        -> Result
    { return static_cast<Result>( array_size( a ) ); }
}

auto menu::items()
    -> menu::Items
{ return {menu_items, impl::array_size_<int>( menu_items )}; }
