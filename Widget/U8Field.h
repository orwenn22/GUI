#ifndef U8FIELD_H
#define U8FIELD_H

#include "Widget.h"

//Same as IntFielt but for "unsigned char" variables.
//Maybe there is a better way to handle this ?
class U8Field : public Widget {
    public:
    U8Field(int x, int y, int w, unsigned char* variableptr);

    void Update() override;
    void Draw() override;

    void SetTargetVariable(unsigned char* variableptr);

    private:
    bool m_isselected;                  //If this is set to true, the U8Field will read and react to keyboard input.
    unsigned char* m_varriableptr;      //Pointer to the int value that the U8Field will update.
    bool m_updaterealtime;

    //this value is stored in the U8Field. 
    //When the user input something, this value is the thing that actually get changed and displayed.
    unsigned char m_tempvariable;
};

#endif