 #!/bin/bash
find src -regextype sed -regex "src/icL\-.*\.\(h\|cpp\|js\)" \
    -exec "clang-format" -style=file  -i "{}" \;
