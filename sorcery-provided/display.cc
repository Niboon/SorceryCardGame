#include "display.h"
#include <iostream>
#include <iterator>

using namespace std;

void draw(card_template_t lines) {
  ostream_iterator<string> out{cout,"\n"};
  copy(lines.begin(),lines.end(),out);
}
