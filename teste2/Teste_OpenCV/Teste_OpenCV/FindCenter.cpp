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

void file_txt (char filename[]){
    
    fstream appendFileToWorkWith;
    
    appendFileToWorkWith.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    
    
    // If file does not exist, Create new file
    if (!appendFileToWorkWith )
    {
        cout << "Cannot open file, file does not exist. Creating new file..";
        
        appendFileToWorkWith.open(filename,  fstream::in | fstream::out | fstream::trunc);
        appendFileToWorkWith <<"\n";
        appendFileToWorkWith.close();
        
    }
    else
    {    // use existing file
        cout<<"success "<<filename <<" found. \n";
        cout<<"\nAppending writing and working with existing file"<<"\n---\n";
        
        appendFileToWorkWith << "Appending writing and working with existing file"<<"\n---\n";
        appendFileToWorkWith.close();
        cout<<"\n";
        
    }
    
}
