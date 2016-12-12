#include "bbcodetextwriter.h"

BBCodeTextWriter::BBCodeTextWriter(QTextStream& stream)
    : TextWriter(stream)
{
}

void BBCodeTextWriter::writeHeader(const QString& text) const
{
    stream << "[h1]" << text << "[/h1]" << endl;
    stream << endl;
}

void BBCodeTextWriter::writeSection(const QString& text) const
{
    stream << "[b]" << text << "[/b]" << endl;
    stream << endl;
}

void BBCodeTextWriter::writeListHeader() const
{
    stream << "[list]" << endl;
}

void BBCodeTextWriter::writeListItem(const QString& text) const
{
    stream << "[*]" << text << endl;
}

void BBCodeTextWriter::writeListFooter() const
{
    stream << "[/list]" << endl;
    stream << endl;
}

void BBCodeTextWriter::writeFooter() const
{
    stream << endl;
}
