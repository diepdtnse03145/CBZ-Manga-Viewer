#include <QApplication>
#include "cbzmangaviewer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("DiepDTN");
    app.setApplicationName("CBZ Manga Viewer");

    CbzMangaViewer c;
    c.start();
    return app.exec();
}
