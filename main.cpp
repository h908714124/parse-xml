#include "tinyxml2.h"
#include "tinyxml2.cpp"

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
   
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
      
    // Parse XML
    XMLDocument doc;
    doc.Parse( xml );
    XMLElement* titleElement = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" );
    const char* title = titleElement->GetText();

    // Create JSON
    StringBuffer sb;
    Writer<StringBuffer> writer(sb);
    writer.StartObject();
    writer.String("title");
    writer.String(title);
    writer.EndObject();

    // Write to stdout
    puts(sb.GetString());
   
    return 0;
}
