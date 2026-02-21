# binary
Created by sammy (2026)

C++ 기반의 이진 패킷 생성 라이브러리입니다.

## Installation
터미널에서 아래 명령어를 입력하여 시스템에 라이브러리를 설치하세요.
```bash
git clone https://github.com/a01041093767-star/binary.git
cd binary
chmod +x install.sh
./install.sh
```

## Usage
```cpp
#include <binary.hpp>
#include <iostream>

int main() {
    binary b;
    std::cout << b.generate(32) << std::endl;
    return 0;
}
```

## License
Copyright (c) 2026 sammy. MIT License.
