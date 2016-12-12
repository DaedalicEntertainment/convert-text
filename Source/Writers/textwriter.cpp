#include "textwriter.h"

TextWriter::TextWriter(QTextStream &stream)
    : stream(stream)
{
}

TextWriter::~TextWriter()
{
}
