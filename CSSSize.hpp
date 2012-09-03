#ifndef __SIZE_HPP__
#define __SIZE_HPP__

namespace CSS {

typedef enum {	CSSUnitPercent,		/* %   	*/
		CSSUnitInch,		/* in	*/
		CSSUnitCentimeter,	/* cm	*/
		CSSUnitMillimeter,	/* mm	*/
		CSSUnitPoint,		/* pt	*/
		CSSUnitPica,		/* pc	*/
		CSSUnitPixels,		/* px	*/
		CSSUnitEm,		/* em	*/
		CSSUnitEx,		/* px	*/
} CSSUnit;

class CSSSize {
public:
	double  value;
	CSSUnit unit;

	CSSSize(double value_, CSSUnit unit_)
	: value(value_), unit(unit_) {}
};


}; /* namespace */


#endif /* __SIZE_HPP__ */

