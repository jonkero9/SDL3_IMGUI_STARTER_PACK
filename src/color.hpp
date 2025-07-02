#ifndef JCOLOR
#define JCOLOR

#include <cstdint>
namespace JCOLOR {

struct Color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
};

const Color CRUST = Color{17, 17, 27, 255};
const Color MANTLE = Color{24, 24, 37, 255};
const Color GREEN_COL = Color{166, 227, 161, 255};
const Color TEXT_COLOR = Color{205, 214, 244, 255};
const Color GREY_COL = Color{108, 112, 134, 255};
const Color BLUE_COL = Color{137, 180, 250, 255};

} // namespace JCOLOR

#endif // INCLUDE/home/jonk/files/docs/cplus/jbattles/srccolorcolor.hpp_
