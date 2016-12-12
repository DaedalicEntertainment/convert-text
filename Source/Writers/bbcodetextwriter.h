#ifndef BBCODETEXTWRITER_H
#define BBCODETEXTWRITER_H

#include "textwriter.h"

class BBCodeTextWriter : public TextWriter
{
    public:
        BBCodeTextWriter(QTextStream& stream);

        void writeHeader(const QString& text) const;
        void writeSection(const QString& text) const;
        void writeListHeader() const;
        void writeListItem(const QString& text) const;
        void writeListFooter() const;
        void writeFooter() const;
};

#endif // BBCODETEXTWRITER_H
