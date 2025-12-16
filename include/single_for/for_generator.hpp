#pragma once

#if __cplusplus >= 202002L

#include <tuple>
#include <concepts>
#include <generator>

namespace gtd {
    template<std::integral... LIMs>
    std::generator<std::tuple<LIMs...>> for_generator(LIMs...);
    template<std::integral LIM, std::integral... tLIMs>
    auto layer_handler(std::tuple<tLIMs...>& values, LIM layer_lim) {
        std::get<sizeof...(tLIMs)-1>(values) += 1;
        return layer_lim;
    }
    template<std::integral LIM, std::integral... LIMs, std::integral... tLIMs>
    auto layer_handler(std::tuple<tLIMs...>& values, LIM layer_lim, LIMs... lims) {
        if(gtd::layer_handler(values,lims...) <= std::get<sizeof...(tLIMs)-sizeof...(LIMs)>(values)) {
            std::get<sizeof...(tLIMs)-sizeof...(LIMs)>(values) = 0;
            std::get<sizeof...(tLIMs)-sizeof...(LIMs)-1>(values) += 1;
        }
        return layer_lim;
    }
}

template<std::integral... LIMs>
std::generator<std::tuple<LIMs...>> gtd::for_generator(LIMs... lims) {
    std::tuple<LIMs...> values{};
    co_yield values;
    while(gtd::layer_handler(values,lims...) > std::get<0>(values))
        co_yield values;
}

#endif