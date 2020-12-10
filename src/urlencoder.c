// Filename: urlencoder.c
// Note:     Dumbest URL encoder for STDIN. Or at least one of them. Pretty sure
//           it's down there. Also written by a non-C coder.
//
//           URL encoding rules:
//           Decoded: space !   "   #   $   %   &   '   (   )   *   +   ,   /   :   ;   <   =   >   ?   @   [   \   ]   ^   `   {   |   }
//           Encoded: %20   %21 %22 %23 %24 %25 %26 %27 %28 %29 %2A %2B %2C %2F %3A %3B %3C %3D %3E %3F %40 %5B %5C %5D %5E %60 %7B %7C %7D

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCODE_LENGTH 3
#define UNENCODE_MAX  30
#define ENCODE_MAX    128

int main() {
  char unencoded[UNENCODE_MAX] = "";
  char encoded[ENCODE_MAX] = "";
  fgets(unencoded, UNENCODE_MAX, stdin);
  size_t len = strlen(unencoded);
  for (size_t i = 0; i < len-1; i++) { // len-1 because we don't want to append the newline.
    if (unencoded[i] == ' ') {
      strncat(encoded, "%20", ENCODE_LENGTH);
    } else if (unencoded[i] == '!') {
      strncat(encoded, "%21", ENCODE_LENGTH);
    } else if (unencoded[i] == '"') {
      strncat(encoded, "%22", ENCODE_LENGTH);
    } else if (unencoded[i] == '#') {
      strncat(encoded, "%23", ENCODE_LENGTH);
    } else if (unencoded[i] == '$') {
      strncat(encoded, "%24", ENCODE_LENGTH);
    } else if (unencoded[i] == '%') {
      strncat(encoded, "%25", ENCODE_LENGTH);
    } else if (unencoded[i] == '&') {
      strncat(encoded, "%26", ENCODE_LENGTH);
    } else if (unencoded[i] == '\'') {
      strncat(encoded, "%27", ENCODE_LENGTH);
    } else if (unencoded[i] == '(') {
      strncat(encoded, "%28", ENCODE_LENGTH);
    } else if (unencoded[i] == ')') {
      strncat(encoded, "%29", ENCODE_LENGTH);
    } else if (unencoded[i] == '*') {
      strncat(encoded, "%2A", ENCODE_LENGTH);
    } else if (unencoded[i] == '+') {
      strncat(encoded, "%2B", ENCODE_LENGTH);
    } else if (unencoded[i] == ',') {
      strncat(encoded, "%2C", ENCODE_LENGTH);
    } else if (unencoded[i] == '/') {
      strncat(encoded, "%2F", ENCODE_LENGTH);
    } else if (unencoded[i] == ':') {
      strncat(encoded, "%3A", ENCODE_LENGTH);
    } else if (unencoded[i] == ';') {
      strncat(encoded, "%3B", ENCODE_LENGTH);
    } else if (unencoded[i] == '<') {
      strncat(encoded, "%3C", ENCODE_LENGTH);
    } else if (unencoded[i] == '=') {
      strncat(encoded, "%3D", ENCODE_LENGTH);
    } else if (unencoded[i] == '>') {
      strncat(encoded, "%3E", ENCODE_LENGTH);
    } else if (unencoded[i] == '?') {
      strncat(encoded, "%3F", ENCODE_LENGTH);
    } else if (unencoded[i] == '@') {
      strncat(encoded, "%40", ENCODE_LENGTH);
    } else if (unencoded[i] == '[') {
      strncat(encoded, "%5B", ENCODE_LENGTH);
    } else if (unencoded[i] == '\\') {
      strncat(encoded, "%5C", ENCODE_LENGTH);
    } else if (unencoded[i] == ']') {
      strncat(encoded, "%5D", ENCODE_LENGTH);
    } else if (unencoded[i] == '^') {
      strncat(encoded, "%5E", ENCODE_LENGTH);
    } else if (unencoded[i] == '`') {
      strncat(encoded, "%60", ENCODE_LENGTH);
    } else if (unencoded[i] == '{') {
      strncat(encoded, "%7B", ENCODE_LENGTH);
    } else if (unencoded[i] == '|') {
      strncat(encoded, "%7C", ENCODE_LENGTH);
    } else if (unencoded[i] == '}') {
      strncat(encoded, "%7D", ENCODE_LENGTH);
    } else {
      strncat(encoded, &unencoded[i], 1);
    }
  }
  printf("%s", encoded);
  return 0;
}
