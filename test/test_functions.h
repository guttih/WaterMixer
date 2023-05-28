#include "arduino.h"
#include <unity.h>


String repeat(String s, unsigned int count) {
    String str ="";
    for(unsigned int ui = 0; ui < count; ui++) {
        str.concat(s);
    }
    return str;
}
String concat(String str1, String str2, String str3) {
    String str = str1;
    str.concat(str2);
    str.concat(str3);
     return str;
}
void header(const char *strHeader) {
    String v="|", 
           h="-",
           c="+",
           text = String(" "+ h +" ") + String(strHeader) + String(" "+ h +" ");
    int textLen = text.length();
    //frame length default is 50
    const int len = textLen > 46? (textLen+4) : 50;
    const int spaces = (len - textLen)-2;
    
    Serial.println(concat(c, repeat(h, len-2), c));
    Serial.println(concat(v, repeat(" ", len-2), v));
    int spaceLeft = spaces/2;
    int spaceRight = spaces - spaceLeft;    
    String frameLeft = concat(v, repeat(" ", spaceLeft), text);
    Serial.println(concat(frameLeft, repeat(" ", spaceRight), v));
    Serial.println(concat(v, repeat(" ", len-2), v));
    Serial.println(concat(c, repeat(h, len-2), c));
}

