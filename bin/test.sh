#!/bin/sh
# Filename: test.sh
# Note:     POSIX shell script to test URL encoder.
#
#           URL encoding rules:
#           Decoded: space !   "   #   $   %   &   '   (   )   *   +   ,   /   :   ;   <   =   >   ?   @   [   \   ]   ^   `   {   |   }
#           Encoded: %20   %21 %22 %23 %24 %25 %26 %27 %28 %29 %2A %2B %2C %2F %3A %3B %3C %3D %3E %3F %40 %5B %5C %5D %5E %60 %7B %7C %7D

ctrl_unencoded=" !@#$%^&*()[]{}/=\?+|',.\"<>"
ctrl_encoded="%20%21%40%23%24%25%5E%26%2A%28%29%5B%5D%7B%7D%2F%3D%5C%3F%2B%7C%27%2C.%22%3C%3E"

echo "Type in the string: $ctrl_unencoded (first char is a space)"

c_encoded="$(./bin/urlencode)"

if [ "$ctrl_encoded" = "$c_encoded" ]
then
  echo "success"
else
  echo "failure"
fi
