//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//                        CLASS CONSTRUCTORS LAB                            //
//                               COLOR.CPP                                  //
//                                                                          //
//  Date ...: 18/MAR/2017                                                   //
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//                                 Includes                                 //
//////////////////////////////////////////////////////////////////////////////
#include "Color.h"

//////////////////////////////////////////////////////////////////////////////
//                     Color Class Member Definitions                       //
//////////////////////////////////////////////////////////////////////////////

Color::Color(int Red,int Green,int Blue):R(Red),G(Green),B(Blue){
    	if (!is_valid_val(Red))
    		        throw Color_error{};
    		 if (!is_valid_val(Blue))
    		 	    throw Color_error{};
    		 if (!is_valid_val(Green))
    		 	    throw Color_error{};
};
//
std::string Color::to_str()
{
    std::stringstream ss;
    ss << '(' << R << ',' << G << ',' << B << ')';
    return ss.str();
}

void Color::set_R(int r)
{
    if (!is_valid_val(r))
        throw Color_error{};
    R = r;
}
void Color::set_G(int g)
{
    if (!is_valid_val(g))
        throw Color_error{};
    G = g;
}
void Color::set_B(int b)
{
    if (!is_valid_val(b))
        throw Color_error{};
    B = b;
}
bool Color::is_valid_val(int v)
{
    if (v < 0 || v > 255)
        return false;
    else
        return true;
}
