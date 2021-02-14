#include "tinyxml2.h"
#include "tinyxml2.cpp"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
    
using namespace tinyxml2;
using namespace rapidjson;

int main(int argc, char *argv[])
{
    static const char* xml =
      "<?xml version=\"1.0\"?>"
      "<!DOCTYPE PLAY SYSTEM \"play.dtd\">"
      "<PLAY>"
      "<TITLE>A Midsummer Night's Dream</TITLE>"
      "</PLAY>";
    XMLDocument doc;
    doc.Parse( xml );
    XMLElement* titleElement = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" );
    const char* title = titleElement->GetText();
    printf( "Name of play (1): %s\n", title );
    
    const char* json = "{\"title\":\"a\"}";
    Document d;
    d.Parse(json);
    d["title"].SetString(title, strlen(title));


    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    
    return 0;
}
