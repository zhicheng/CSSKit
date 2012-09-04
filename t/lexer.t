use strict; no strict 'subs';
use warnings;

use Cwd;
use Inline CPP => Config => INC   => '-I' . cwd() 
			 => MYEXTLIB => cwd() . '/*.o';
use Inline Force;
use Inline CPP;

use Test::More tests => 1;


ok(testlexer("hello{a:b c d;}"), "test lexer");

__END__
__CPP__

#include <iostream>
#include "CSSKit.hpp"

bool testlexer(char *input)
{
	std::string input_(input);
	CSS::Lexer lexer(input_);
	CSS::Token *t = lexer.nextToken();
	while (t->type != CSS::TokenEOF) {
		std::cout << t->name();
		t = lexer.nextToken();
	}
	std::cout << t->name();
	return true;
}

