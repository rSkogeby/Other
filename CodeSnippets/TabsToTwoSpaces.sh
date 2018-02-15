# Changes all tabs in all .cpp files of current directory into 2 spaces

find . -name '*.cpp' ! -type d -exec bash -c 'expand -t 2 "$0" > /tmp/e && mv /tmp/e "$0"' {} \;
