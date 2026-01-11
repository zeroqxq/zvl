<div id="header" align="center">
  <h1>zvl</h1>
  <h3>Data validator on C++</h3>
</div>

<div id="header" align="center">
  <img alt="Project language" src="https://img.shields.io/badge/language-C%2B%2B-blue" </img>
  <img alt="GitHub Repo stars" src="https://img.shields.io/github/stars/zeroqxq/zvl?style=flat&color=blue"> </img>
  <img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/zeroqxq/zvl?color=blue"> </img>
  
</div>

<div id="header" align="center">
  <img alt="GitHub License" src="https://img.shields.io/github/license/zeroqxq/zvl"> </img>
  <img alt="GitHub Issues" src="https://img.shields.io/github/issues/zeroqxq/zvl"> </img>
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/zeroqxq/zvl"> </img>


</div>

---

## Examples
``` cpp
#include "../zvl.hpp"
#include <iostream>

int main(){
    int b = 2;
    auto c = zvl::check(b).in_range(18,100);
    std::cout << c.is_valid() << " " << c.message() << std::endl;
}
```
