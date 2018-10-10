//
// Classe MauvaisFormatImage
// Cette classe definit l'exception a lancee lorsque
// l'image que l'on tente d'ouvrir n'est pas
// dans un format reconnu par la classe QImage
//
#ifndef EXCEPTIONMAUVAISFORMATIMAGE_H
#define EXCEPTIONMAUVAISFORMATIMAGE_H

#include <QException>
#include <QString>

class ExceptionMauvaisFormatImage : public QException {
    public:
    ExceptionMauvaisFormatImage(QString s): s_(s){}
    virtual void raise() const {throw *this;} // virtual?
    ExceptionMauvaisFormatImage* clone() const { return new ExceptionMauvaisFormatImage(*this);}
    QString what() {return s_;}
    private:
    QString s_;
};

#endif // EXCEPTIONMAUVAISFORMATIMAGE_H
