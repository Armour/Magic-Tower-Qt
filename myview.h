#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>

class MyView : public QGraphicsView {
    Q_OBJECT
signals:
    void move(int x, int y);
    void events(QString str);
    void fight(int num);
    void change();
    void quit();

public:
    explicit MyView(QWidget *parent = 0);       /* explicit means "implicit invocation" is not allow*/
    ~MyView();
    QString GetStatus() { return status; }
    void SetStatus(QString status) { this->status = status; }
    void keyMain(QKeyEvent * event);
    void keyShop(QKeyEvent * event);
    void keyWelcome(QKeyEvent * event);
    void keySelect(QKeyEvent * event);
    void keyFight();
    void action();

protected:
    void keyPressEvent(QKeyEvent *event);       /* rewrite the virtual function keyPressEvent*/

private:
    int access(int x, int y);
    QString status;
    int NextStep;
};

#endif // MYVIEW_H
