use strict; no strict 'subs';
use warnings;

use Cwd;
use Inline CPP => Config => INC   => '-I' . cwd() 
			 => MYEXTLIB => cwd() . '/*.o';
use Inline Force;
use Inline CPP;

use Test::More tests => 3;


ok(testlexer("hello{a:b c d;}"), "test lexer");
ok(testlexer("hello{a:1 2 3;}"), "test lexer");
ok(testlexer("hello{a:'world\\'';}"), "test lexer");

__END__
__CPP__

#include <iostream>
#include "CSSKit.hpp"

bool testlexer(char *input)
{
	std::cout << std::endl;
	std::string input_(input);
	CSS::Lexer lexer(input_);
	CSS::Token *t = lexer.nextToken();
	while (t->type != CSS::TokenEOF) {
		std::cout << t->name() << t->text << " ";;
		t = lexer.nextToken();
	}
	std::cout << t->name() << t->text << std::endl;
	return true;
}

