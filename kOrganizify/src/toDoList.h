#ifndef TODOLIST_H
#define TODOLIST_H

#include "task.h"
#include "saveload.h"
#include <QObject>
#include <QVector>
#include <QString>
#include <QJsonArray>
#include <QJsonValue>

class ToDoList : public SaveLoad
{
    Q_OBJECT

private:
    QVector<Task> m_tasks;

public:
    explicit ToDoList(QObject *parent = nullptr);
    void loadData(const QString &username);
    void saveData(const QString &username);
    void fromJson(const QJsonObject &jsonObject) override;
    void setTasks(const QVector<Task>& tasks);
    void addTask(const Task task);
    void removeTask(const int index);

    QVector<Task> getTasks();
    Task* getTask(int index) const;
    QString toString();
    QJsonValue toJson() const override;
};

#endif // TODOLIST_H
