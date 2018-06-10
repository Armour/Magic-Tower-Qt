#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>

class View : public QGraphicsView {
    Q_OBJECT
signals:
    void move(int x, int y);
    void events(QString str);
    void fight(int num);
    void change();
    void quit();

public:
    explicit View(QWidget *parent = 0);       // Explicit means "implicit invocation" is not allow
    ~View();
    QString GetStatus() { return status; }
    void SetStatus(QString status) { this->status = status; }
    void keyMain(QKeyEvent *event);
    void keyShop(QKeyEvent *event);
    void keyWelcome(QKeyEvent *event);
    void keySelect(QKeyEvent *event);
    void keyFight();
    void action();

protected:
    void keyPressEvent(QKeyEvent *event);       // Rewrite the virtual function keyPressEvent

private:
    int access(int x, int y);
    QString status;
    int next_step;
};

#endif // VIEW_H
