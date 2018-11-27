//
//  FindCenter.cpp
//  Teste_OpenCV
//
//  Created by Marina Silva Tavares on 27/11/18.
//  Copyright © 2018 Marina Silva Tavares. All rights reserved.
//

#include "FindCenter.hpp"

int FindCenter (float x1, float x2, float x3, float x4){
    float xf;
    
    xf=(x1+x2+x3+x4)/4;
    
    return xf;
}
