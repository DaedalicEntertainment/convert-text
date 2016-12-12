#ifndef TEXTWRITER_H
#define TEXTWRITER_H

#include <QTextStream>

class TextWriter
{
    public:
        TextWriter(QTextStream& stream);
        virtual ~TextWriter();

        virtual void writeHeader(const QString& text) const = 0;
        virtual void writeSection(const QString& text) const = 0;
        virtual void writeListHeader() const = 0;
        virtual void writeListItem(const QString& text) const = 0;
        virtual void writeListFooter() const = 0;
        virtual void writeFooter() const = 0;

    protected:
        QTextStream& stream;
};

#endif // TEXTWRITER_H
