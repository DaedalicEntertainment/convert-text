#include <iostream>

#include <QFile>
#include <QFileInfo>
#include <QTextStream>

#include "Writers/textwriter.h"

#include "Writers/bbcodetextwriter.h"
#include "Writers/rtftextwriter.h"

using namespace std;


int main(int argc, char *argv[])
{
    // Parse arguments.
    if (argc != 3)
    {
        cout << "USAGE: ConvertText <Source> <Destination>" << endl;
        return 1;
    }

    QString sourcePath(argv[1]);
    QString destinationPath(argv[2]);

    QFileInfo sourceFileInfo(sourcePath);
    QFileInfo destinationFileInfo(destinationPath);

    cout << "Source: " << sourceFileInfo.absoluteFilePath().toStdString().c_str() << endl;
    cout << "Destination: " << destinationFileInfo.absoluteFilePath().toStdString().c_str() << endl;

    // Prepare I/O.
    QFile sourceFile(sourcePath);
    QFile destinationFile(destinationPath);

    if (!sourceFile.open(QFile::ReadOnly))
    {
        cout << "Unable to open source file." << endl;
        return 1;
    }

    if (!destinationFile.open(QFile::WriteOnly | QFile::Truncate))
    {
        sourceFile.close();
        cout << "Unable to open destination file." << endl;
        return 1;
    }

    QTextStream sourceStream(&sourceFile);
    QTextStream destinationStream(&destinationFile);

    // Determine output file format.
    TextWriter* writer;
    QString format(destinationFileInfo.suffix().toLower());

    if (format == "bbcode")
    {
        writer = new BBCodeTextWriter(destinationStream);
    }
    else if (format == "rtf")
    {
        writer = new RtfTextWriter(destinationStream);
    }
    else
    {
        sourceFile.close();
        destinationFile.close();
        cout << "Unknown output file format: " << format.toStdString().c_str() << endl;
        return 1;
    }

    // Parse input file.
    cout << "Converting...";

    QString line;
    bool list = false;
    int lineCount = 0;

    while (sourceStream.readLineInto(&line))
    {
        if (line.startsWith("# "))
        {
            writer->writeHeader(line.mid(2));
        }
        else if (line.startsWith("## "))
        {
            writer->writeSection(line.mid(3));
        }

        if (line.startsWith('*'))
        {
            if (!list)
            {
                list = true;
                writer->writeListHeader();
            }

            writer->writeListItem(line.mid(2));
        }
        else
        {
            if (list)
            {
                list = false;
                writer->writeListFooter();
            }
        }

        ++lineCount;
        cout << ".";
    }

    writer->writeFooter();

    cout << endl;
    cout << "Converted " << lineCount << " input lines." << endl;

    // Clean up.
    sourceFile.close();
    destinationFile.close();

    delete writer;

    return 0;
}
