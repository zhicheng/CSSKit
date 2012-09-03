use Inline CPP => Config => LIBS => '*.o';
use Inline CPP => Config => INC  => '.';
use Inline CPP;

print "========= BUILD =========\n";
print `make`;
print "=========  RUN  =========\n";
test();
print "========= CLEAN =========\n";
print `make clean`;
print "=========  END  =========\n";

__END__
__CPP__

#include <iostream>
#include "CSSColor.hpp"

void test()
{
	CSS::Color *color = new CSS::Color(0xFFFFFFFF);
}
