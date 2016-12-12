#include "rtftextwriter.h"

RtfTextWriter::RtfTextWriter(QTextStream& stream)
    : TextWriter(stream)
{
}

void RtfTextWriter::writeHeader(const QString& text) const
{
    stream << "{\\rtf1\\ansi{\\fonttbl{\\f0\\fnil\\fcharset0 Calibri;}}" << endl;
    stream << "\\pard\\sa200\\b\\f0\\fs40 " << text << "\\b0\\fs22\\par" << endl;
}

void RtfTextWriter::writeSection(const QString& text) const
{
    stream << "\\b " << text << "\\b0\\par" << endl;
    stream << endl;
}

void RtfTextWriter::writeListHeader() const
{
    stream << "\\pard{\\*\\pn\\pnlvlblt\\pnf1\\pnindent0{\\pntxtb\\'B7}}\\fi-360\\li720\\sa200\\sl276\\slmult1" << endl;
}

void RtfTextWriter::writeListItem(const QString& text) const
{
    stream << "{\\pntext\\f1\\'B7\\tab}" << text << "\\par" << endl;
}

void RtfTextWriter::writeListFooter() const
{
    stream << "\\pard\\sa200\\sl276\\slmult1\\par" << endl;
}

void RtfTextWriter::writeFooter() const
{
    stream << "}" << endl;
}
