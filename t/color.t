use strict; no strict 'subs';
use warnings;
use Test::More tests => 1;

use Cwd;
use Inline CPP => Config => INC  => '-I' . cwd();
use Inline CPP;

ok(testhex(0xFFFFFFFF, 1.0, 1.0, 1.0, 1.0), "test color #FFFFFFFF");

__END__
__CPP__

#include <iostream>
#include "CSSKit.hpp"

bool testhex(unsigned int hex, float r, float g, float b, float a)
{
	CSS::Color color(hex);
	return (color.r == r && color.g == g && color.b == b && color.a == a);
}
