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
#include "CSSKit.hpp"

void test()
{
	CSS::Color color(0xFFFFFFFF);
	std::cout << color.r << std::endl
		  << color.g << std::endl
		  << color.b << std::endl
		  << color.a << std::endl;
}
