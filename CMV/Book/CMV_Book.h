#ifndef CMV_BOOK_H
#define CMV_BOOK_H

class QImage;
class QString;

class CMV_Book
{
public:
    CMV_Book();
    virtual ~CMV_Book();
    virtual QImage pageAt(const QString &id) const = 0;
    virtual int size() const = 0;
    virtual QString name() const = 0;
    virtual QString pageName(int index) const = 0;
    virtual QImage cover() const = 0;
};

#endif // CMV_BOOK_H
