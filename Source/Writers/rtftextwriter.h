#ifndef RTFTEXTWRITER_H
#define RTFTEXTWRITER_H

#include "textwriter.h"

class RtfTextWriter : public TextWriter
{
    public:
        RtfTextWriter(QTextStream& stream);

        void writeHeader(const QString& text) const;
        void writeSection(const QString& text) const;
        void writeListHeader() const;
        void writeListItem(const QString& text) const;
        void writeListFooter() const;
        void writeFooter() const;
};

#endif // RTFTEXTWRITER_H
