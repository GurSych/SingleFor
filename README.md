# SingleFor

SingleFor is my C++ library for easily creating multi-leyered loops with single for-construction

# Library's concept

Library should make creating multi-leyered loops much easier and efficient, allowing you to use a single for-loop construction.\

## First idea

Code bellow is my first thoughts about this:

```cpp
#include <iostream>

int main() {
    std::cout << "Standard:" << std::endl;
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            std::cout << i << " " << j << "\t";
    std::cout << "\nSingle:" << std::endl;
    for(int i = 0, j = 0; i < 4; i = (j = (++j) < 4 ? j : 0) == 0 ? i + 1 : i)
        std::cout << i << " " << j << "\t";
    std::cout << std::endl;
    return 0;
}
```

Program's output:

```
Standard:
0 0	0 1	0 2	0 3	1 0	1 1	1 2	1 3	2 0	2 1	2 2	2 3	3 0	3 1	3 2	3 3	
Single:
0 0	0 1	0 2	0 3	1 0	1 1	1 2	1 3	2 0	2 1	2 2	2 3	3 0	3 1	3 2	3 3
```

This code allows you use single for-loop that have a multi-leyered (nested) behavior. That can be useful when you need to break such loops in a simple way.

## Vision

The goal is to design library that can be used like this:

```cpp
#include <iostream>
#include "single_for/single_for.hpp"

int main() {
    auto loop2 = gtd::single_for_handler<4,4>{};
    for(int i = 0, j = 0; loop2(i,j); )
        std::cout << i << " " << j << std::endl;
    return 0;
}
```

Variadic-template will allow you to use as many layers as you want.

# Using Library

> The library is in development so this section is updated together with library itself

## Library connection

```cpp
#include "single_for/single_for.hpp"
```

> [!NOTE]
> All library classes are in `gtd::` namespace.